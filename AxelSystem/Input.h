#ifndef INPUT_H
#define INPUT_H

enum class Input
{
	NoInput = 0,
	A,
	X,
	B,
	Y
};

struct Axel
{
	// Keep miliseconds, this will be working with the converted time in seconds to milliseconds from the attack node
public:

	explicit Axel(const Input& input, unsigned int timeStamp) :
		m_input( input ),
		m_timeStamp( timeStamp )
	{}

	~Axel() {}

private:

	Input			m_input;
	unsigned int	m_timeStamp;

};


#endif // !INPUT_H

