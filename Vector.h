#pragma once
template<class T>
class Vector
{
	int size;
	T *el;
public:
	Vector(int n_size = 0);
	Vector(const Vector& a);
	Vector& operator=(Vector&& other);
	T operator[](int c);
	bool operator==(const Vector& a);	
	bool operator!=(const Vector& a);
	bool operator>=(const Vector& a);
	bool operator<=(const Vector& a);
	bool operator>(const Vector& a);
	bool operator<(const Vector& a);
	void push_back(T elem);
	int length();
	bool empty();
	void clear();
	void insert(int pos,T elem);
	void erase(int pos, int k = 1);
	~Vector();
};

