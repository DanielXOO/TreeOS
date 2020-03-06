#include "Vector.h"

//default class constructor
template <class T>
Vector<T>::Vector(int n_size)						
{
	size = n_size;			
	el = new T[size];	
	T x(0);
	for (int i = 0; i < size; i++)
		el[i] = x;
}

//copy constructor
template<class T>
Vector<T>::Vector(const Vector & a)					
{
	size = a.size;						 
	el = new T[size];					
	for (int i = 0; i < size; i++)
	{
		el[i] = a.el[i];				
	}
}

//We have an operator having L-value and R-value
//We pass R-value in brackets as a static vector
//L-value we return the value
template<class T>
Vector<T> &Vector<T>::operator=(const Vector<T>& other)		//assignment statement description(a = b)
{
	if (this != &other)					//checking that the same element doesn't stand left and right
	{
		delete[]el;						//delete the elements we no longer need
		size = other.size;				//set the size equal to the copied
		el = new T[size];				//creation of a dynamic array of long size and type T
		for (int i = 0; i < size; i++)	
		{
			el[i] = other.el[i];		//transfer of all elements to the corresponding cells
		}
	}
	return *this;						//return the received vector to L-value
}

//operator + 
//stacks up all the values ​​in their places
template<class T>
Vector<T> Vector<T>::operator+(const Vector<T>& other)
{
	Vector<T> x(*this);
	for (int i = 0; i < other.size; i++)
		x.push_back(other.el[i]);
	return x;
}

//operator [] 
//allows you to return a value of type T contained in the array in place with
template<class T>
T Vector<T>::operator[](int c)
{
		return el[c];
}

//-\(o_o)/-  a piece of shit  -\(o_o)/-
template<class T>
std::ostream & Vector<T>::operator<<(std::ostream & out)
{
	for (int i = 0; i < size; i++)
	{
		out << el[i]<<"\n";
	}
	return out;
}

//next six functions - define comparison operators
//operator ==
//requires equality and length of vectors and all values ​​of vectors
template<class T>
bool Vector<T>::operator==(const Vector & a)
{
	if (size == a.size)
	{
		for (int i = 0; i < size; i++)
		{
			if (el[i] != a.el[i])
				return false;
		}
		return true;
	}
	return false;
}

//operator !=
//if the vectors are equal, the inequality of at least one value of the vectors
template<class T>
bool Vector<T>::operator!=(const Vector & a)
{
	if (size == a.size)
	{
		for (int i = 0; i < size; i++)
		{
			if (el[i] != a.el[i])
				return true;
		}
		return false;
	}
	return true;
}

//operator >=
//requires that the vector on the left has a greater or equal length 
//and all elements of the right vector are less than or equal to the left
template<class T>
bool Vector<T>::operator>=(const Vector & a)
{
	if (size >= a.size)
	{
		for (int i = 0; i < a.size; i++)
		{
			if (el[i] < a.el[i])
				return false;
		}
		return true;
	}
	return false;
}

//operator <= 
//requires that the vector on the right has a greater or equal length
//and all elements of the left vector are less than or equal to the right
template<class T>
bool Vector<T>::operator<=(const Vector & a)
{
	if (size <= a.size)
	{
		for (int i = 0; i < size; i++)
		{
			if (el[i] > a.el[i])
				return false;
		}
		return true;
	}
	return false;
}

//operator > 
//requires that the vector on the left has a greater or equal length 
//and all elements of the right vector are smaller than the left
template<class T>
bool Vector<T>::operator>(const Vector & a)
{
	if (size >= a.size)
	{
		for (int i = 0; i < a.size; i++)
		{
			if (el[i] <= a.el[i])
				return false;
		}
		return true;
	}
	return false;
}

//operator <
//requires that the vector on the right has a greater or equal length 
//and all elements of the left vector are smaller than the right
template<class T>
bool Vector<T>::operator<(const Vector & a)
{
	if (size <= a.size)
	{
		for (int i = 0; i < size; i++)
		{
			if (el[i] >= a.el[i])
				return false;
		}
		return true;
	}
	return false;
}

//function push_back
//add an element to the end of Vector
template<class T>
void Vector<T>::push_back(T elem)
{
	T *n_el = new T[size];
	for (int i = 0; i < size; i++)
	{
		n_el[i] = el[i];
	}
	delete[]el;
	size++;
	el = new T[size];
	for (int i = 0; i < size - 1; i++)
	{
		el[i] = n_el[i];
	}
	el[size - 1] = elem;
	delete[]n_el;
}

//function pop_back
//delete last elemeht in the Vector
template<class T>
void Vector<T>::pop_back()
{
	size--;
	T *n_el = new T[size];
	for (int i = 0; i < size; i++)
	{
		n_el[i] = el[i];
	}
	delete[]el;
	el = new T[size];
	for (int i = 0; i < size; i++)
	{
		el[i] = n_el[i];
	}
	delete[]n_el;
}

//return size of the Vector
template<class T>
int Vector<T>::length()
{
	return size;
}

//is it empty?  
template<class T>
bool Vector<T>::empty()
{
	if (size != 0)
		return false;
	else
		return true;
}

//delete all elements and makes size = 0
template<class T>
void Vector<T>::clear()
{
	size = 0;
	delete[]el;
	el = new T[size];
}

//add an element in position pos
template<class T>
void Vector<T>::insert(int pos, T elem)
{
	if (pos - size <= 1)
	{
		size++;
		T *n_el = new T[size];
		for (int i = 0; i < pos; i++)
		{
			n_el[i] = el[i];
		}
		n_el[pos] = elem;
		for (int i = pos + 1; i < size; i++)
		{
			n_el[i] = el[i - 1];
		}
		delete[]el;
		el = new T[size];
		for (int i = 0; i < size; i++)
		{
			el[i] = n_el[i];
		}
		delete[]n_el;
	}
	else
	{
		T *n_el = new T[pos];
		for (int i = 0; i < size; i++)
		{
			n_el[i] = el[i];
		}
		for (int i = size; i < pos; i++)
		{
			n_el[i] = elem;
		}
		delete[]el;
		size = pos;
		el = new T[size];
		for (int i = 0; i < size; i++)
		{
			el[i] = n_el[i];
		}
		delete[]n_el;
	}
}

//delete k elements (default k = 1), starts from position pos
template<class T>
void Vector<T>::erase(int pos, int k)
{
	T *n_el;
	if (pos + k < size)
		n_el = new T[size - k];
	else
		n_el = new T[pos];
	if (pos < size)
	{
		for (int i = 0; i < pos; i++)
		{
			n_el[i] = el[i];
		}
		for (int i = pos + k; i < size; i++)
		{
			n_el[i - k] = el[i];
		}
		if (pos + k < size)
			size = pos + (size - (pos + k));
		else
			size = pos;
		delete[]el;
		el = new T[size];
		for (int i = 0; i < size; i++)
		{
			el[i] = n_el[i];
		}
		delete[]n_el;
	}
}

//destructor
template <class T>
Vector<T>::~Vector()
{
	size = 0;
	delete[]el;
}