#pragma once

#include <iostream>
//class A is a friend with class FriendClass
class FriendClass
{
public:
	FriendClass();
	~FriendClass();
	FriendClass(int a, int b) : _x(a), _y(b){}
	//copy constructor
	FriendClass(const FriendClass& obj)
	{
		_x = obj._x; _y = obj._y;
	}

	friend class A;

private:
	int _x;
	int _y;
};

class A 
{
public:
	A(){}
	~A(){}
	friend class FriendClass;

	//methods
	void AccessFriendClass(FriendClass a) {
		std::cout << a._x << " " << a._y << std::endl;
	}
};

class complex
{
public:
	complex(){}
	~complex(){}
	complex(double Img, double real) : _Img(Img), _real(real){}

	//methods and operators
/*
complex operator+(const complex& other) 
	{
		_Img += other._Img;
		_real += other._real;

		return complex(_Img, _real);
	}
*/
//	friend complex operator+(const complex& num1, const complex& num2);

private:
	double _Img;
	double _real;
};
/*
complex operator+(const complex& num1, const complex& num2)
{
return complex(num1._real + num2._real, num1._Img + num2._Img);
}
*/
