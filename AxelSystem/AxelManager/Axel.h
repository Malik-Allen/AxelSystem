#ifndef AXEL_H
#define AXEL_H

#include "Input.h"
#include "../Utility/High-ResTimer.h"


using MyInput = Input<Button>;	// Hear is where you can customize what data is used to define an input

class Axel
{
	
	friend class AxelManager;

public:

	explicit Axel( const Button& button, float timeRangeStart, float timeRangeEnd ) :
		m_input( MyInput( button, 0 ) ),
		m_timeRangeStart( SECONDS_TO_MILLISECONDS * timeRangeStart ),
		m_timeRangeEnd( SECONDS_TO_MILLISECONDS * timeRangeEnd )
	{}

	Axel( const MyInput& input ) :
		m_input( input ),
		m_timeRangeStart( 0 ),
		m_timeRangeEnd( 0 )
	{}

	~Axel() {}

	bool operator==( const Axel& rhs )
	{
		return m_input == rhs.m_input;
	}

private:

	// Some Aniamtion Component to play
	MyInput			m_input;
	unsigned int	m_timeRangeStart;
	unsigned int	m_timeRangeEnd;

};

#endif // !AXEL_H

