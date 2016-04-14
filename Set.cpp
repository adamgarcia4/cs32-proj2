#include "Set.h"

Set::Set()
{
	//initialization is done by default in private members.
}

//Destructor
/*
When a Set is destroyed, the nodes in the linked list must be deallocated.
*/
Set::~Set()
{
	while (m_head != nullptr) //traverses list starting from head and deletes, then traverses to next.
	{
		node* tempHeadNext = m_head->m_next; //stores next element.  Needed because we are deleting head's data.
		delete m_head;
		m_head = tempHeadNext;
	}
}

//Copy Constructor
/*
When a brand new Set is created as a copy of an existing Set, enough new nodes must be allocated to hold a duplicate of the original list.
*/
Set::Set(const Set & obj)
{
	node* objTailPtr = obj.m_tail; //stores pointer to tail.  This will be used to traverse list without affecting the list's tail.

	for(;objTailPtr!=nullptr;objTailPtr=objTailPtr->m_prev) //loop through entire list, from end to beginning.  Take each node's data and insert it into our own (this) set.
	{
		insert(objTailPtr->m_data);  //employs insert function to perform insertion into our own list.
	}
	this->m_listSize = obj.m_listSize;
}

//Assignment Operator
/*
When we want to assign one list to another, algorithm needs to delete entire contents of this list, then need to insert contents of other list to this one.
*/
Set& Set::operator=(Set obj)
{

	while (m_head != nullptr) //Loop through linked list, deleting all data elements.
	{
		node* tempHeadNext = m_head->m_next;
		delete m_head;
		m_head = tempHeadNext;
	}
	m_tail = nullptr;

	node* insertNext = obj.m_head; //create variable which traverses object nodes.
	while (insertNext!=nullptr) //loop through object nodes, inserting each element of that node into this linked list.
	{
		this->insert(insertNext->m_data);
		insertNext = insertNext->m_next;
	}
	this->m_listSize = obj.m_listSize;
	//for (node* objHead = obj.m_head; objHead != nullptr; objHead=objHead->m_next)
	//{
	//	this->erase(objHead->m_data);
	//}

	/*for (node* objTail = obj.m_tail; objTail != nullptr; objTail = objTail->m_prev)
	{
		this->insert(objTail->m_data);
	}*/
	return *this; //Returns dereference (data pointed to by this).  This is used so that C=B=A can be called.
}

//Empty Function
/* Return true if the set is empty, otherwise false.
*/
bool Set::empty() const
{
	if (m_head == nullptr) //or m_listSize==0
		return true;
	else
		return false;
}


//Size Function
/* 
Return the number of items in the set.
*/
int Set::size() const
{
	return m_listSize;
}

//Insert Function
/*
Insert value into the set if it is not already present.  Return
true if the value was actually inserted.  Leave the set unchanged
and return false if the value was not inserted (perhaps because it
is already in the set).
*/
bool Set::insert(const ItemType & value)
{
	if (contains(value)) //Ensures Uniqueness.  If list contains value, escape.
	{
		return false;
	}


	//by this time, value is unique.  Now, need to insert it.

	node* temp = new node(value); //creates new node with data in it.  Now time to link it.
	
	//if list is empty, then head and tail both point to same node.
	if (m_head == nullptr)
	{
		m_head = temp;
		m_tail = temp;
	}
	else //already data in list.  If so, the head wouldn't be nulled out.
	{
		temp->m_next = m_head;
		m_head->m_prev = temp;
		m_head = temp;
	}

	//cerr << "m_prev is: " << temp->m_prev << "  And m_next is:  " << temp->m_next << endl;
	m_listSize++; //Inserted, so now list grew.
	return true; //true case.
}

//Erase Function
/*
Remove the value from the set if present.  Return true if the
value was removed; otherwise, leave the set unchanged and
return false.
*/
bool Set::erase(const ItemType & value)
{

	if (m_head == nullptr)//if empty | Or if m_head = nullptr;  m_listSize == 0
	{
		return false;
	}

	node* headPtr = m_head;
	node* tailPtr = m_tail;

	if (headPtr->m_data == value) //the node is at head of list b/c haven't traversed.
	{
		headPtr = headPtr->m_next; //head pointer points to next.
		delete m_head; //delete this node.
		headPtr->m_prev = nullptr;
		m_head = headPtr;
		return true;
	}
	else if ((tailPtr->m_data) == value) //if at end of list.
	{
		tailPtr = tailPtr->m_prev;
		delete m_tail;
		tailPtr->m_next = nullptr;
		m_tail = tailPtr;
		return true;
	}
	else
	{
		for (node* temp = m_head; temp != nullptr; temp = temp->m_next)
		{
			if (temp->m_data == value)
			{
				temp->m_prev->m_next = temp->m_next;
				temp->m_next->m_prev = temp->m_prev;
				delete temp;
				return true;
			}
		}
	}
	

	//while (p != nullptr)  //if not empty, spit data and increment pointer to next element.
	//{
	//	if (p->m_data == value)//if this is the node to delete
	//	{
	//		//p->m_next->m_prev = p->m_prev; //make the next's prev = to this prev.
	//		//p->m_prev->m_next = p->m_next; //make the prev's next = to this next.
	//		//return true;
	//		if (p==m_head) //if p is head node, then change head pointer to next head.
	//		{
	//			m_head = p->m_next;
	//		}



	//	}
	//	p = p->m_next;
	//}
	return false;
}

//Contains Function
/*
Return true if the value is in the set, otherwise false.
*/
bool Set::contains(const ItemType & value) const
{
	node* temp1 = m_head;  //creates traversing element.
	for (; temp1 != nullptr;) //Traverses list.  Ensures unique entry.  Returns false otherwise.
	{
		if (temp1->m_data == value)
		{
			//cerr << temp1->m_data << "already in here" << endl;
			return true;
		}
		//cerr << "m_listSize = " << m_listSize << endl;
		temp1 = temp1->m_next;
	}

	return false;

	/*
	while (temp1 != nullptr) //Traverses list.  Ensures unique entry.  Returns false otherwise.
	{
	if (temp1->m_data == value)
	{
	//cerr << temp1->m_data << "already in here" << endl;
	return false;
	}
	//cerr << "m_listSize = " << m_listSize << endl;
	temp1 = temp1->m_next;
	}*/
	/*
	for (int i=0; i<m_listSize; i++) //Traverses list.  Ensures unique entry.  Returns false otherwise.
	{
	if (temp1->m_data == value)
	{
	//cerr << temp1->m_data << "already in here" << endl;
	return false;
	}
	//cerr << "m_listSize = " << m_listSize << endl;
	temp1 = temp1->m_next;
	}

	*/
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

	if (m_head == nullptr) //check to see if list empty.
	{
		cerr << "Empty list:" << endl;
		return;
	}

	while (p != nullptr)  //if not empty, spit data and increment pointer to next element.
	{
		cerr << "Element " << counter << " is: " << p->m_data << " Where m_prev: " << p->m_prev << " Where m_next: " << p->m_next << endl;
		p = p->m_next;
		counter++;
	}
	
}

//By default, node initialized to empty node, with no data or traversing.
Set::node::node(): m_next(nullptr), m_prev(nullptr)
{
	//need to check for m_data being initialized to empty string.  Not uninitialized.
}

//If we know data, we can initialize to data already in it.  No traversing data
Set::node::node(ItemType data): m_data(data), m_next(nullptr), m_prev(nullptr)
{

}
