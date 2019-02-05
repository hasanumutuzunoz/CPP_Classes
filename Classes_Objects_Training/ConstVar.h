#pragma once
class ConstVar
{
public:
	ConstVar(int s, int l);
	~ConstVar();

private:
	const int size;
	const int level;
	
};

