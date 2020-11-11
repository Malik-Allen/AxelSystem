#ifndef INPUT_H
#define INPUT_H

enum class Button
{
	NoInput = 0,
	A,
	X,
	B,
	Y
};

struct Input
{

public:

	explicit Input(const Button& button, const unsigned int timeStamp) :
		m_button( button ),
		m_timeStamp( timeStamp )
	{}

	~Input() {}

	const Button& GetButton() const { return m_button; }

	const unsigned int GetTimeStamp() const { return m_timeStamp; }

private:

	Button			m_button;
	unsigned int	m_timeStamp;

};


#endif // !INPUT_H

