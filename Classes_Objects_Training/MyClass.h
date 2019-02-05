#pragma once
//Header file is just for decleare the functions, variables and define which one is public,private,protected
class MyClass
{
public:
	MyClass(); //Constructor
	virtual ~MyClass(); //Destructor

	void myPrint();
	void myConstPrint() const;
};

