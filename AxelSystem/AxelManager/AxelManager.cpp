#include "AxelManager.h"


#include <iostream>

AxelManager::AxelManager( GeneralTree<Axel>* rootTree ) :
	m_axelTree( rootTree ),
	m_inputQueue( new Queue<MyInput>() ),
	m_currentNode( rootTree ),
	m_nextNode( nullptr ),
	m_lastSuccessfulInput( Button::NoInput, 0 ),
	m_hasAttackSequenceStarted( false )
{}

AxelManager::~AxelManager()
{
	if ( m_axelTree )
	{
		delete m_axelTree;
		m_axelTree = nullptr;
	}
	if ( m_inputQueue )
	{
		delete m_inputQueue;
		m_inputQueue = nullptr;
	}
	if ( m_currentNode )
	{
		delete m_currentNode;
		m_currentNode = nullptr;
	}
	if ( m_nextNode )
	{
		delete m_nextNode;
		m_nextNode = nullptr;
	}
}

// Adds input to the queue of waiting inputs to be processed by manager
void AxelManager::QueueInput( const MyInput & input )
{
	m_inputQueue->enqueue_back( input );

	if ( m_hasAttackSequenceStarted == false )
	{
		ProcessInput();
	}
}

// Call this event once the attack has been completed, inorder to transition
void AxelManager::OnAttackComplete()
{

	m_currentNode = m_nextNode;
	m_nextNode = nullptr;
	
	ProcessInput();
	
}

// Call this event once the attack has been completed, inorder to transition
void AxelManager::OnAttackCancel()
{
	BreakAndClear();
}

// Dequeues Input to be processed by manager, begins process of begining an attack sequence
		// When an input has been deemed as valid, remember to assign it to last successful input
void AxelManager::ProcessInput()
{
	m_hasAttackSequenceStarted = true;

	if ( m_inputQueue->size() == 0 )
	{
		return;
	}

	MyInput receivedInput = m_inputQueue->front();
	m_inputQueue->dequeue_front();

	m_nextNode = SearchForNextNode( m_currentNode, receivedInput );

	if ( m_nextNode == nullptr )
		// No combination found, break combination and clear queue
	{
		BreakAndClear();
		return;
	}

	if ( HasInputBeenReceivedInTime( m_lastSuccessfulInput, receivedInput, m_nextNode ) )
	{
		m_lastSuccessfulInput = receivedInput;
		// Wait for either OnAttack Complete or OnAttack Cancel
	}
	else
	{
		BreakAndClear();
		return;
	}



}

// Stop current attack sequence, clearing the queue of input, reseting all variables on the manager, reassigning the current node to the m_axelTree
void AxelManager::BreakAndClear()
{
	m_inputQueue->clear();
	m_currentNode = m_axelTree;
	m_nextNode = nullptr;
	m_lastSuccessfulInput = MyInput( Button::NoInput, 0 );
	m_hasAttackSequenceStarted = false;
}

// Searches passed axel tree for a child node that matches the passed input 
	// Returns the Node if it exists, otherwise returns nullptr
GeneralTree<Axel>* AxelManager::SearchForNextNode( GeneralTree<Axel> * axelTree, const MyInput & input )
{
	if ( axelTree == nullptr )
	{
		return nullptr;
	}

	return axelTree->find_child( input );
}

// Returns true if the difference in time between the last successful input and the input in question is inside the range of time for the desired Axel
bool AxelManager::HasInputBeenReceivedInTime( const MyInput & lastSuccessfulInput, const MyInput & inputInQuestion, GeneralTree<Axel>* desiredAxelNode )
{
	if ( lastSuccessfulInput.GetButton() == Button::NoInput && inputInQuestion.GetButton() != Button::NoInput )
	{
		return true;
	}

	unsigned int diff = inputInQuestion.GetTimeStamp() - lastSuccessfulInput.GetTimeStamp();

	if ( diff >= desiredAxelNode->get().m_timeRangeStart && diff <= desiredAxelNode->get().m_timeRangeEnd )
	{
		return true;
	}

	return false;
}
