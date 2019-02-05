#include "pch.h"
#include "ConstVar.h"


ConstVar::ConstVar(int s, int l) : size(s) , level(l)
{
	cout << "Size: " << size << ", Level: " << level << endl;
}


ConstVar::~ConstVar()
{
}


