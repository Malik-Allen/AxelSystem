#include "AxelManager.h"

AxelManager::AxelManager( GeneralTree<Axel>* rootTree ) :
	m_axelTree( rootTree ),
	m_inputQueue( new Queue<Input>() ),
	m_currentNode( nullptr ),
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
