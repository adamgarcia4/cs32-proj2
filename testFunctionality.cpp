#include "Set.h"
#include <iostream>

void insertTest();

int main()
{
	insertTest();
	//setTest.insert(2);
	//setTest.insert(3);
	//setTest.insert(2); //should be error here.
	//setTest.dump();
	//setTest.erase(3); //correctly erases first node.
	//setTest.erase(1);
	//setTest.dump();
	system("pause");
}
void insertTest()
{
	Set a;
	
	a.insert(1);
	a.insert(2);
	a.insert(3);
	a.insert(4);
	cerr << "A is: " << endl;
	a.dump();
	Set b;
	b = a;
	cerr << "B is: " << endl;
	b.dump();
	ItemType elem;
	a.get(4, elem);
	cerr << "get element 0: " << elem << endl;
}