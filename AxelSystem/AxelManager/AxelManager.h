#ifndef AXELMANAGER_H
#define AXELMANAGER_H

#include "../DataStructures/GeneralTree.h"
#include "../DataStructures/Queue.h"

#include "Axel.h"


class AxelManager
{
	AxelManager( const AxelManager& ) = delete;
	AxelManager& operator=( const AxelManager& ) = delete;
	AxelManager( AxelManager&& ) = delete;
	AxelManager& operator = ( AxelManager&& ) = delete;

public:

	explicit AxelManager( GeneralTree<Axel>* rootTree );

	~AxelManager();
	
	// Adds input to the queue of waiting inputs to be processed by manager
	void QueueInput( const MyInput& input );

	// Call this event once the attack has been completed, inorder to transition
	void OnAttackComplete();

	// When an attack has been cancelled or interrupted for any reason, break and clear current combo
	void OnAttackCancel();

	// Returns the next attack to play, returns nullptr if combo chain is broken
	GeneralTree<Axel>* GetNextAttackNode() const { return m_nextNode; }

private:

	// Axel Tree represents possible combinations designed by the developer
	GeneralTree<Axel>*		m_axelTree;

	// Input queue, is input received from the player 
	Queue<MyInput>*			m_inputQueue;

	GeneralTree<Axel>*		m_currentNode;
	GeneralTree<Axel>*		m_nextNode;

	MyInput					m_lastSuccessfulInput;

	bool					m_hasAttackSequenceStarted;

	// Dequeues Input to be processed by manager, begins process of begining an attack sequence
		// When an input has been deemed as valid, remember to assign it to last successful input
	void ProcessInput();

	// Stop current attack sequence, clearing the queue of input, reseting all variables on the manager, reassigning the current node to the m_axelTree
	void BreakAndClear();

	// Searches passed axel tree for a child node that matches the passed input 
	// Returns the Node if it exists, otherwise returns nullptr
	GeneralTree<Axel>* SearchForNextNode ( GeneralTree<Axel>* axelTree, const MyInput& input );


	// Returns true if the difference in time between the last successful input and the input in question is inside the range of time for the desired Axel
	bool HasInputBeenReceivedInTime(const MyInput& lastSuccessfulInput, const MyInput& inputInQuestion, GeneralTree<Axel>* desiredAxelNode);

};


#endif // !AXELMANAGER_H

