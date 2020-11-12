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

template<typename T>
struct Input
{

public:

	explicit Input(const T& button, const unsigned int timeStamp) :
		m_button( button ),
		m_timeStamp( timeStamp )
	{}

	~Input() {}

	const T& GetButton() const { return m_button; }

	const unsigned int GetTimeStamp() const { return m_timeStamp; }

	bool operator==( const Input& rhs )
	{
		return m_button == rhs.m_button;
	}

private:

	T			m_button;
	unsigned int	m_timeStamp;

};


#endif // !INPUT_H

