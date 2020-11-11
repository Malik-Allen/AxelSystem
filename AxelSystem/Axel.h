#ifndef AXEL_H
#define AXEL_H

#include "Input.h"
#include "Utility/High-ResTimer.h"

class Axel
{
	// Change time ranges from ints to floats
	// Make it so that attack node only receives time in seconds and nothing else
		// Perform conversion on construct, from seconds to milliseconds to be used in the calculation
		// The time ranges should never be altered again
		// Make getters for them returning a float, don't perform a conversion for each get call, may lead to miscalculation
public:

	Axel( const Button& button, float timeRangeStart, float timeRangeEnd ) :
		m_input( new Input( button, 0 ) ),
		m_timeRangeStart( SECONDS_TO_MILLISECONDS * timeRangeStart ),
		m_timeRangeEnd( SECONDS_TO_MILLISECONDS * timeRangeEnd )
	{}

	Axel( const Input& input ) :
		m_input( new Input( input ) ),
		m_timeRangeStart( 0 ),
		m_timeRangeEnd( 0 )
	{}

	~Axel() 
	{
		delete m_input;
		m_input = nullptr;
	}

	bool operator==( const Axel& rhs )
	{
		return this->m_input->GetButton() == rhs.m_input->GetButton();
	}

	const Input& GetInput() const { return *m_input; }

private:

	// Some Aniamtion to play
	Input*			m_input;
	unsigned int	m_timeRangeStart;
	unsigned int	m_timeRangeEnd;

};

#endif // !AXEL_H

