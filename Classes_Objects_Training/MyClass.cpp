#include "pch.h";
#include "MyClass.h"

//Constructor
MyClass::MyClass() //MyClass class - MyClass function
{		
}

//Destructor (Only 1 destructor max, runs when the object is deleted, cannot have parameter, cannot overload, cannot return value)
MyClass::~MyClass()
{
}

void MyClass::myPrint() {
	cout << "Hello! test function in a class." << endl;
}

void MyClass::myConstPrint() const {
	cout << "Constant print function" << endl;
}
