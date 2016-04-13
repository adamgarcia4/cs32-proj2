#ifndef SET_H
#define SET_H

#include <string>
using namespace std;

typedef string ItemType;

class Set
{
public:
	Set();

	//Destructor
	/* 
	When a Set is destroyed, the nodes in the linked list must be deallocated.
	*/
	~Set();

	//Copy Constructor
	/*
	When a brand new Set is created as a copy of an existing Set, enough new nodes must be allocated to hold a duplicate of the original list.
	http://www.tutorialspoint.com/cplusplus/cpp_copy_constructor.htm
	*/
	Set(const Set &obj);

	//Assignment Operator
	Set operator=(Set obj);

	//Empty Function
	bool empty() const;

	//Size Function
	int size() const;

	//Insert Function
	bool insert(const ItemType& value);

	//Erase Function
	bool erase(const ItemType& value);

	//Contains Function
	bool contains(const ItemType& value) const;

	//Get Function
	bool get(int pos, ItemType& value) const;

	//Swap Function
	void swap(Set& other);

	struct node
	{
		ItemType m_data;
		node* m_next;
		node* m_prev;
	};
private:
	node* m_head;
	node* m_tail;
};

#endif