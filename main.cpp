#include "AttackNode.h"
#include "Input.h"
#include "High-ResTimer.h"
#include "DataStructures/Queue.h"

// Linked list will represent the current attack branch
// Queue for Axels
// Axel System Class Will contiain a reference to a node graph
// Node Tree

#include "DataStructures/GeneralTree.h"

int main()
{
	/*
	AttackNode* parent = new AttackNode( Input::NoInput, 1, 2);

	parent->AddChild( new AttackNode( Input::A, 0, 1 ) );
	

	parent->AddChild( new AttackNode( Input::B, 1, 2 ) )->AddChild( new AttackNode( Input::X, 1, 3 ) );
	
	parent->AddChild( new AttackNode( Input::X, 0, 1 ) );

	parent->AddChild( new AttackNode( Input::Y, 0, 1 ) );
	*/
	
	HighResTimer* timer = new HighResTimer();

	AttackNode root = AttackNode( Input::NoInput, 0, 0 );
	AttackNode basic1 = AttackNode( Input::A, 0, 1 );
	AttackNode basic2 = AttackNode( Input::X, 0, 1 );
	AttackNode basic3 = AttackNode( Input::Y, 0, 1 );
	AttackNode basic4 = AttackNode( Input::B, 0, 1 );
	Axel* axel = new Axel( Input::A, timer->GetCurrentTimeInMilliSeconds() );

	GeneralTree<AttackNode>* attackTree = new GeneralTree<AttackNode>( root );

	attackTree->add_child( new GeneralTree<AttackNode>( basic1 ) );
	attackTree->add_child( new GeneralTree<AttackNode>( basic2 ) );
	attackTree->add_child( new GeneralTree<AttackNode>( basic3 ) );
	attackTree->add_child( new GeneralTree<AttackNode>( basic4 ) );

	GeneralTree<AttackNode>* tmp = attackTree->find_child( basic3 );

	attackTree->remove( basic4 );

	tmp = attackTree->find_child( basic4 );

	Queue<Axel> incomingInput;

	incomingInput.enqueue_back( *axel );
	

	incomingInput.enqueue_back( Axel( Input::A, timer->GetCurrentTimeInMilliSeconds() ) );
	incomingInput.enqueue_back( Axel( Input::B, timer->GetCurrentTimeInMilliSeconds() ) );
	incomingInput.enqueue_back( Axel( Input::X, timer->GetCurrentTimeInMilliSeconds() ) );
	Axel a = incomingInput.front();
	incomingInput.dequeue_front();


	delete attackTree;
	return 0;
}