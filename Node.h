#ifndef NODE_H
#define NODE_H

#include <vector>

class Node
{

public:

	Node() : m_parent( nullptr ) {}
	~Node() 
	{
		ClearChildren();
	}

	Node* AddChild( Node* child )
	{
		if ( child == nullptr )
		{
			return nullptr;
		}

		child->m_parent = this;
		m_children.push_back( child );

		return child;
	}

	void RemoveChild( uint32_t index )
	{

		if ( index > m_children.size() )
		{
			return;
		}

		if ( m_children[index] != nullptr )
		{
			delete m_children[index];
			m_children[index] = nullptr;
		}

		m_children.erase( m_children.begin() + index );

	}

private:

	Node*				m_parent;
	std::vector<Node*>	m_children;

	void ClearChildren()
	{
		for ( size_t i = 0; i < m_children.size(); i++ )
		{
			if ( m_children[i] != nullptr )
			{
				m_children[i]->ClearChildren();
				delete m_children[i];
				m_children[i] = nullptr;
			}
		}

		m_children.clear();
	}


};


#endif // !NODE_H

