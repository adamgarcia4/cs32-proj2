#include "Set.h"

Set::Set()
{
	m_head = nullptr;
	m_tail = nullptr;
	m_listSize = 0;
}

//Not sure
Set::~Set()
{
	//delete m_head;
	//delete m_tail;
}

Set::Set(const Set & obj)
{
}

Set Set::operator=(Set obj)
{
	return Set();
}

/*Return true if the set is empty, otherwise false.
*/

bool Set::empty() const
{
	return false;
}

int Set::size() const
{
	return 0;
}

bool Set::insert(const ItemType & value)
{
	node* temp = new node(value); //creates new node with data in it
	
	//if list is empty
	if (m_head == nullptr)
	{
		m_head = temp;
		m_tail = temp;
	}
	else
	{
		temp->m_next = m_head;
		m_head = temp;
	}




	return false;
}

bool Set::erase(const ItemType & value)
{
	return false;
}

bool Set::contains(const ItemType & value) const
{
	return false;
}

bool Set::get(int pos, ItemType & value) const
{
	return false;
}

void Set::swap(Set & other)
{
}

void Set::dump() const
{
	node* p = m_head;
	int counter = 0;

	if (m_head == nullptr)
	{
		cerr << "Empty list:" << endl;
		return;
	}

	while (p != nullptr)
	{
		cerr << "Element " << counter << " is: " << p->m_data << endl;
		p = p->m_next;
		counter++;
	}
	
}

Set::node::node(): m_next(nullptr), m_prev(nullptr)
{
	
}

Set::node::node(ItemType data): m_data(data), m_next(nullptr), m_prev(nullptr)
{

}
