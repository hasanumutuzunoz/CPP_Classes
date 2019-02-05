#include "pch.h"
#include "Person.h"

Person::Person(string n, Birthday b) : name(n), bd(b)
{
	
}


Person::~Person()
{
}

void Person::printInfo()
{
	cout << name << endl;
	bd.printDate();
}
