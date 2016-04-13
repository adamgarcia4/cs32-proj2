#include "Set.h"

Set::Set()
{
	m_head = nullptr;
	m_tail = nullptr;
}

Set::~Set()
{
}

Set::Set(const Set & obj)
{
}

Set Set::operator=(Set obj)
{
	return Set();
}

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
