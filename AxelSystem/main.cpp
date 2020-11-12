#include "AxelCombatSystem.h"

#include <Windows.h>


// Axel Combat System Vision: 
	// Visual Scripting Nodes for setting up combo tree
	// Any Input Enum can be taken as input
	// Requires Time in seconds, program will handle conversions internally
	// Fast and Accurate, and Percise
	// Can Accpet Any Aniamtion Data for Axels
	


int main()
{
	HighResTimer* timer = new HighResTimer();

	Axel root = Axel( MyInput( Button::NoInput ), 0, 0 );


	Axel basic_attack_1 = Axel( MyInput( Button::A ), 0.0f, 1.0f );
	Axel basic_attack_2 = Axel( MyInput( Button::X ), 0.0f, 1.0f );
	Axel basic_attack_3 = Axel( MyInput( Button::B ), 0.0f, 1.0f );
	Axel basic_attack_4 = Axel( MyInput( Button::Y ), 0.0f, 1.0f );

	GeneralTree<Axel>* rootTree = new GeneralTree<Axel>( root );

	GeneralTree<Axel>* combo_1 = new GeneralTree<Axel>( basic_attack_1 );
	combo_1->add_child( new GeneralTree<Axel>( Axel( MyInput( Button::A ), 0.0f, 1.0f ) ) );

	GeneralTree<Axel>* combo_2 = new GeneralTree<Axel>( basic_attack_2 );
	GeneralTree<Axel>* temp = new GeneralTree<Axel>( Axel( MyInput( Button::Y ), 0.0f, 1.0f ) );
	combo_2->add_child( temp );
	temp->add_child( new GeneralTree<Axel>( Axel( MyInput( Button::Y ), 0.0f, 0.2f ) ) );

	GeneralTree<Axel>* combo_3 = new GeneralTree<Axel>( basic_attack_3 );
	combo_3->add_child( new GeneralTree<Axel>( Axel( MyInput( Button::X ), 0.0f, 1.0f ) ) );

	GeneralTree<Axel>* combo_4 = new GeneralTree<Axel>( basic_attack_4 );
	combo_4->add_child( new GeneralTree<Axel>( Axel( MyInput( Button::B ), 0.0f, 1.0f ) ) );

	rootTree->add_child( combo_1 );
	rootTree->add_child( combo_2 );
	rootTree->add_child( combo_3 );
	rootTree->add_child( combo_4 );


	AxelManager* axelManager = new AxelManager(rootTree);

	axelManager->QueueInput( MyInput( Button::X, timer->GetCurrentTimeInMilliSeconds() ) );

	Sleep( 200 );

	axelManager->QueueInput( MyInput( Button::Y, timer->GetCurrentTimeInMilliSeconds() ) );

	Sleep( 201 );

	axelManager->QueueInput( MyInput( Button::Y, timer->GetCurrentTimeInMilliSeconds() ) );
	
	GeneralTree<Axel>* current = nullptr;

	current = axelManager->GetNextAttackNode();
	axelManager->OnAttackComplete();
	current = axelManager->GetNextAttackNode();
	axelManager->OnAttackComplete();
	current = axelManager->GetNextAttackNode();

	return 0;

}



