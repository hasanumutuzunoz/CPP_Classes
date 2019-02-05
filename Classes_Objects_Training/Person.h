#pragma once
#include "Birthday.h"


class Person
{
public:
	Person(string n, Birthday b);
	~Person();
	void printInfo();

private: 
	string name;
	Birthday bd;
};

