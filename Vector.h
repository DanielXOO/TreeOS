#pragma once
#include <iostream>
//detailed information about the functions can be found in the description file "Vector.cpp"
template<class T>							//creating template class Vector
class Vector
{
	int size;								//variable responsible for the number of elements in the vector
	T *el;									//dynamic array of type T
public:
	Vector(int n_size = 0);					//default class constructor
	Vector(const Vector& a);				//copy constructor
	Vector<T>& operator=(const Vector<T>& other);		//assignment statement description(a = b)
	Vector<T> operator+(const Vector<T>& other);		//description of the addition opperator(a + b)
	T operator[](int c);					//description of statement []
	std::ostream& operator<<(std::ostream& out);		//shit-happens  -\(o_o)/-
	bool operator==(const Vector& a);		//description of bool statement ==
	bool operator!=(const Vector& a);		//description of bool statement !=
	bool operator>=(const Vector& a);		//description of bool statement >=
	bool operator<=(const Vector& a);		//description of bool statement <=
	bool operator>(const Vector& a);		//description of bool statement >        
	bool operator<(const Vector& a);		//description of bool statement <
	void push_back(T elem);					//add an element to the end of Vector
	void pop_back();						//delete last elemeht in the Vector
	int length();							//return size of the Vector
	bool empty();							//is it empty?  
	void clear();							//delete all elements and makes size = 0
	void insert(int pos,T elem);			//add an element in position pos
	void erase(int pos, int k = 1);			//delete k elements (default k = 1), starts from position pos
	~Vector();								//destructor
};