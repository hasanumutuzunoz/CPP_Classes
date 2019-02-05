#include "pch.h"
#include "MyClass.h"	
#include "ConstVar.h"
#include "Person.h"

//ENCAPSULATION 
class Enemy {
public://Accesible from anywhere manytimes within the scope

	//CONTSTRUCTOR runs whenever the new object created
	Enemy(string n, int hp, int s, int a) : age(a) { // : age(a) is a member initializer for constant variable (and normal variables)
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

	//ATTRIBUTES
private: //Only accesible from within the class 
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


int main() {
	//Initializing an object from Enemy class
	Enemy skeleton("Skeleton", 250, 12, 18);
	skeleton.getStats();
	changeHP(skeleton, 333); //FRIEND FUNCTION (We changed the private variables)

	Enemy fireWarrior("Fire Warrior", 999, 35, 28);
	fireWarrior.getStats();
	
	// Accessing an object's members
	MyClass obj; //Object //use (.)
	obj.myPrint(); 
	MyClass *ptr = &obj; //Pointer //use (->)
	ptr->myPrint(); 
	(*ptr).myPrint(); //same
	
	//Only constant objects can call contant functions
	const MyClass constObj; 
	constObj.myConstPrint();

	ConstVar constVar(17, 99); 

	//COMPOSITION (using objects inside an object)
	Birthday myBirthday(1, 9, 1991);
	Person Hasan("Hasan", myBirthday);
	Hasan.printInfo();

	return 0;
}
