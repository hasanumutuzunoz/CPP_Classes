#pragma once

class Birthday
{
public:
	Birthday(int m, int d, int y);
	~Birthday();
	void printDate();

private:
	int month;
	int day;
	int year;
};

