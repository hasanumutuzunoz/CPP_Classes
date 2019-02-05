#include "pch.h"
#include "Birthday.h"



Birthday::Birthday(int m, int d, int y) : month(m), day(d), year(y)
{
}


Birthday::~Birthday()
{
}

void Birthday::printDate()
{
	cout << "Month: " << month << " " << "Day: " << day << " " << "Year: " << year << endl;
	
}
