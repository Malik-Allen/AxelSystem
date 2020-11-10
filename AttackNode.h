#ifndef ATTACKNODE_H
#define ATTACKNODE_H

#include "Node.h"
#include "Input.h"

class AttackNode
{
	// Change time ranges from ints to floats
	// Make it so that attack node only receives time in seconds and nothing else
		// Perform conversion on construct, from seconds to milliseconds to be used in the calculation
		// The time ranges should never be altered again
		// Make getters for them returning a float, don't perform a conversion for each get call, may lead to miscalculation
public:

	AttackNode(const Input& input, const unsigned int timeRangeStart, const unsigned int timeRangeEnd) : 
		m_input(input),
		m_timeRangeStart( timeRangeStart ),
		m_timeRangeEnd( timeRangeEnd )
	{}
	~AttackNode() {}

	bool operator==( const AttackNode& rhs )
	{
		return this->m_input == rhs.m_input;
	}

	const Input& GetInput() const { return m_input; }

private:

	// Some Aniamtion to play
	Input m_input;
	unsigned int m_timeRangeStart;
	unsigned int m_timeRangeEnd;

};

#endif // !ATTACKNODE_H

