#include "AxelCombatSystem.h"
#include "DataStructures/Queue.h"
#include "DataStructures/GeneralTree.h"


// 1. Pass through a float time for the axel, to be converted to an unsigned internal int
// 2. Create a Class to Lead the functionality
	// a. Have a clear injection for input
	// b. Have a clear injection point for the general tree of combinations


int main()
{
	HighResTimer* timer = new HighResTimer();

	Axel root = Axel( Button::NoInput, 0, 0 );


	Axel basic_attack_1 = Axel( Button::A, 0, 1 );
	Axel basic_attack_2 = Axel( Button::X, 0, 1 );
	Axel basic_attack_3 = Axel( Button::B, 0, 1 );
	Axel basic_attack_4 = Axel( Button::Y, 0, 1 );

	GeneralTree<Axel>* rootTree = new GeneralTree<Axel>( root );

	GeneralTree<Axel>* combo_1 = new GeneralTree<Axel>( basic_attack_1 );
	combo_1->add_child( new GeneralTree<Axel>( Axel( Button::A, 0, 2 ) ) );

	GeneralTree<Axel>* combo_2 = new GeneralTree<Axel>( basic_attack_2 );
	combo_2->add_child( new GeneralTree<Axel>( Axel( Button::Y, 0, 2 ) ) );


	GeneralTree<Axel>* combo_3 = new GeneralTree<Axel>( basic_attack_3 );
	combo_3->add_child( new GeneralTree<Axel>( Axel( Button::X, 0, 2 ) ) );

	GeneralTree<Axel>* combo_4 = new GeneralTree<Axel>( basic_attack_4 );
	combo_4->add_child( new GeneralTree<Axel>( Axel( Button::B, 0, 2 ) ) );

	rootTree->add_child( combo_1 );
	rootTree->add_child( combo_2 );
	rootTree->add_child( combo_3 );
	rootTree->add_child( combo_4 );

	Queue<Input>* playerInput = new Queue<Input>();

	playerInput->enqueue_back( Input( Button::X, timer->GetCurrentTimeInMilliSeconds() ) );
	playerInput->enqueue_back( Input( Button::A, timer->GetCurrentTimeInMilliSeconds() ) );
	playerInput->enqueue_back( Input( Button::A, timer->GetCurrentTimeInMilliSeconds() ) );
	
	GeneralTree<Axel>* current = rootTree;
	GeneralTree<Axel>* next = nullptr;

	next = current->find_child( playerInput->front() );
	playerInput->dequeue_front();

	// Check that we are within range for time stamp
		// Comparison against previous tree 

	// Play some animation interface

	if ( next == nullptr )
	{
		return 0;
	}

	current = next;

	next = current->find_child( playerInput->front() );
	playerInput->dequeue_front();

	if ( next == nullptr )
	{
		return 0;
	}

	current = next;

	next = current->find_child( playerInput->front() );
	playerInput->dequeue_front();

	if ( next == nullptr )
	{
		return 0;
	}


	return 0;
}



