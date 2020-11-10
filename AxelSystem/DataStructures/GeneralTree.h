#ifndef GENERALTREE_H
#define GENERALTREE_H

template<class T>
class GeneralTree
{


	T				m_data;
	GeneralTree*	m_next;
	GeneralTree*	m_prev;
	GeneralTree*	m_child;


public:

	explicit GeneralTree( const T& value ) : 
		m_data( value ), 
		m_prev( nullptr ),
		m_next( nullptr ),
		m_child( nullptr )
	{}

	~GeneralTree()
	{
		GeneralTree *currentNode = m_child;

		while ( currentNode != nullptr )
		{
			GeneralTree *tmp = currentNode;
			currentNode = currentNode->m_next;

			delete tmp;
		}
	}

	void add_child( GeneralTree *node )
	{
		if ( m_child == nullptr )
			m_child = node;
		else
			m_child->add_sibiling( node );
	}

	void add_sibiling( GeneralTree *node )
	{
		if ( this->m_next == nullptr )
		{
			this->m_next = node;
			node->m_prev = this;
			node->m_next = nullptr;
		}
		else
		{
			GeneralTree *tmp = this->m_next;

			while ( tmp->m_next != nullptr )
			{
				tmp = tmp->m_next;
			}

			tmp->m_next = node;
			node->m_prev = tmp;
			node->m_next = nullptr;
		}
	}

	GeneralTree *find( const T& value )
	{
		if ( m_data == value )
			return this;

		for ( GeneralTree *c = m_child; c; c = c->m_next )
		{
			GeneralTree *result = c->find( value );

			if ( result != nullptr )
				return result;
		}

		return nullptr;
	}

	GeneralTree *find_child( const T& value )
	{

		for ( GeneralTree *c = this->m_child; c; c = c->m_next )
		{
			if ( c == nullptr )
			{
				break;
			}
			else
			{
				if ( c->m_data == value )
				{
					return c;
				}
			}

		}

		return nullptr;
	}

	void remove( const T& value )
	{
		for ( GeneralTree *c = m_child; c; c = c->m_next )
		{
			if ( c->m_data == value )
			{
				if ( c->m_prev )
					c->m_prev->m_next = c->m_next;
				else
					m_child = c->m_next;
				if ( c->m_next )
					c->m_next->m_prev = c->m_prev;

				delete c;
				return;
			}
			else
			{
				c->remove( value );
			}
				
		}
	}

	
};

#endif // !GENERALTREE_H

