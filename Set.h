#ifndef SET_H
#define SET_H

#include <string>
#include <iostream>
using namespace std;

typedef unsigned long ItemType;

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
	Set& operator=(Set obj);

	//Empty Function
	/*Return true if the set is empty, otherwise false.
	*/
	bool empty() const;

	//Size Function
	int size() const;

	//Insert Function
	/*
	 Insert value into the set if it is not already present.  Return
	 true if the value was actually inserted.  Leave the set unchanged
	 and return false if the value was not inserted (perhaps because it
	 is already in the set).
	*/
	bool insert(const ItemType& value);

	//Erase Function
	/*
	Remove the value from the set if present.  Return true if the
    value was removed; otherwise, leave the set unchanged and
    return false.
	*/
	bool erase(const ItemType& value);

	//Contains Function
	/*
	Return true if the value is in the set, otherwise false.
	*/
	bool contains(const ItemType& value) const;

	//Get Function
	bool get(int pos, ItemType& value) const;

	//Swap Function
	void swap(Set& other);

	void dump() const;

	struct node
	{
	public:
		node();
		node(ItemType data);

		ItemType m_data;
		node* m_next;
		node* m_prev;
	};
private:
	node* m_head=nullptr;
	node* m_tail=nullptr;
	int m_listSize=0;
};

#endif