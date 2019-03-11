#include "pch.h"
#include "MyClass.h"	
#include "ConstVar.h"
#include "Person.h"

//ENCAPSULATION 
class Enemy {

	/*Public    : Accesible from anywhere manytimes within the scope
	  Protected : Accesible to only its derived class
	  Private   : Only accesible from within the class */

public:
	//CONTSTRUCTOR runs whenever the new object created
	Enemy(string n, int hp, int s, int a) : age(a) {
 // : age(a) is a member initializer for constant variable (and normal variables)
		cout << "I am your ENEMY!." << endl;
		//setStats("Skeleton", 250, 12);
		setStats(n, hp, s);
	}

	//BEHAVIOUR (METHODS)
	void setStats(string n, int h, int s) {
		name = n;
		health = h;
		strength = s;
	}
	void getStats() {
		cout << "Name: " << name << endl;
		cout << "HP: " << health << endl;
		cout << "Strength: " << strength << endl;
		cout << "Age: " << age << endl;
	}
	

	//this (a pointer to the object)
	void printInfoWithThis() {
		cout << health << endl;
		cout << this->health << endl;
		cout << (*this).health << endl;
	}

	//ATTRIBUTES
private: 
	string name;
	int health;
	int strength;
	const int age; //Constant Variable

	friend void changeHP(Enemy &obj, int hp);//friend function declare
};

//FRIEND FUNCTION (to change the private members of a class)
void changeHP(Enemy &obj, int hp)
{
	obj.health = hp;
	obj.name = "Changed Named";
	obj.getStats();
}



//POLIMORPHISM
//Abstract Class (cannot be instantiated)
class Character {
public:
	//Pure Virtual Function
	virtual void attack() = 0; //Function has no body so derived classes define this class.

	void setAttackPower(int a) {
		attackPower = a;
	}
protected:
	int attackPower;
};
//Polimorphic Class (has virtual class)
class Ninja : public Character {
public:
	void attack() {
		cout << "Ninja attacks! " << attackPower << endl;
	}
};
class Monster : public Character {
public:
	void attack() {
		cout << "Monster attacks! " << attackPower << endl;
	}
};



//INHERITANCE
class Mother	
{
public:
	Mother() 
	{
		cout << "Mother constructor" << endl;
	};
	~Mother() 
	{
		cout << "Mother destructor" << endl;
	}
	void sayHi()
	{
		cout << "Hi there" << endl;
	}
protected: 
	string eyeColour = "blue";
};
//Public Inheritance: Public members of the base class become public, protected become protected
//Protected Inheritance: Public and protected members of the base class become protected 
//Private Inhertence: Public and protected members of the base class become private
//If no specified, it will become private. Generally public is used. 
class Daughter : public Mother
{
public:
	Daughter()
	{
		cout << "Daughter constructor" << endl;
	}
	~Daughter()
	{
		cout << "Daughter destructor" << endl;
	}

	void tellEyeColour()
	{
		cout << "My eyes are " << eyeColour << endl;
	}
};



//OPERATOR OVERLOADING
//In this example we can add different types of variables with just adding the objects 
class operatorOverloading {
public:
	int var;
	operatorOverloading() {};
	operatorOverloading(int a) : var(a) {};

	operatorOverloading operator + (operatorOverloading &obj) {
		operatorOverloading res;
		res.var = this->var + obj.var;
		return res;
	}
};


//FUNCTION TEMPLATES
//One version of function to work with parameters of any type
template <class T>
T sum(T a , T b) {
	return a + b;
}
template <class T>
T printT(T a) {
	return 	a;
}
template <class T, class U>
auto smaller(T a, U b) { 
	return (a < b ? a : b); //if a < b; return a, else; return b 
}


//CLASS TEMPLATES
template <class T>
class Pair {
private:
		T first, second;
public: 
		Pair(T a, T b) : first(a), second(b) {}
};




int main() {
	//INITIALIZING an object from Enemy class
	Enemy skeleton("Skeleton", 250, 12, 18);
	skeleton.getStats();
	//FRIEND FUNCTION (We changed the private variables)
	changeHP(skeleton, 333); 

	Enemy fireWarrior("Fire Warrior", 999, 35, 28);
	fireWarrior.getStats();
	fireWarrior.printInfoWithThis(); 
	
	// ACCESSING an object's members
	MyClass obj; //Object //use (.)
	obj.myPrint(); 
	MyClass *ptr = &obj; //Pointer //use (->)
	ptr->myPrint(); 
	(*ptr).myPrint(); //same
	
	//Only CONSTANT OBJECTS can call CONSTRANT FUNCTIONS
	const MyClass constObj; 
	constObj.myConstPrint();

	ConstVar constVar(17, 99); 

	//COMPOSITION (using objects inside an object)
	Birthday myBirthday(1, 9, 1991);
	Person Hasan("Hasan", myBirthday);
	Hasan.printInfo();

	//OPERATOR OVERLOADING
	operatorOverloading obj1(12), obj2(55), obj3(123), exampleObject;
	operatorOverloading abc = obj1 + obj2 + obj3;
	cout << abc.var << endl;

	//INHERITANCE
	Daughter Alex;
	Alex.sayHi();
	Alex.tellEyeColour();

	//POLIMORPHISM
	Ninja n;
	Monster m;
	Character *c2 = &m;
	Ninja *c1 = &n; // It doesn't matter pointer object type 

	c1->setAttackPower(18);
	c2->setAttackPower(25);

	n.attack();
	m.attack();
	c1->attack();
	c2->attack();

	////FUNCTION TEMPLATE
	float a = 1.323;
	float b = 5.8585;
	cout << sum(a, b) << endl;
	cout << printT(b) << endl;
	cout << smaller(b, 1) << endl;


	return 0;
}
