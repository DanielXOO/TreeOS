#include "Vector.h"

template <class T>
Vector<T>::Vector(int n_size)						//���������� ������ �� ���������
{
	size = n_size;			//����� �������� size ������� ����� ����� ��������� n_size(�� ��������� 0)
	el = new T[size];		//�������� ������������� ������� ������� size � ���� �
}

template<class T>
Vector<T>::Vector(const Vector & a)					//����������� �����������
{
	size = a.size;						//�������� �������� � size 
	el = new T[size];					//�������� ������������� ������� ������� size � ���� �
	for (int i = 0; i < size; i++)
	{
		el[i] = a.el[i];				//������� ���� ��������� � �������������� ������
	}
}

//�� ����� �������� ������� L-value � R-value
//R-value �� �������� � ��������� ��� ��������� ������
//L-value �� ���������� ��������
template<class T>
Vector<T> &Vector<T>::operator=(Vector&& other)		//�������� ��������� ������������(=)
{
	if (this != other)					//�������� ����� ����� � ������ �� ����� ���� � ��� �� �������
	{
		delete[]el;						//������� ��� �� ������ ��� ��������
		size = other.size;				//����� ������ ������ �����������
		el = new T[size];				//�������� ������������� ������� ������� size � ���� �
		for (int i = 0; i < size; i++)	
		{
			el[i] = other.el[i];		//������� ���� ��������� � �������������� ������
		}
	}
	return *this;						//���������� � L-value ���������� ������
}

//�������� [] ��������� ������� �������� ���� � ������������ � ������� �� ����� �
template<class T>
T Vector<T>::operator[](int c)
{
		return el[c];
}

//��������� ����� ������� - ���������� ��������� ���������
//�������� == ������� ��������� � ����� �������� � ���� �������� ��������
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

//�������� != ������� ��� ��������� ����� �������� ����������� ���� �� ������ �������� ��������
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

//�������� >= ������� ����� ������ ����� ���� ������� ��� ������ ����� � ��� �������� ������� ������� ���� ������ ��� ����� �����
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

//�������� <= ������� ����� ������ ������ ���� ������� ��� ������ ����� � ��� �������� ������ ������� ���� ������ ��� ����� ������
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

//�������� > ������� ����� ������ ����� ���� ������� ��� ������ ����� � ��� �������� ������� ������� ���� ������ �����
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

//�������� < ������� ����� ������ ������ ���� ������� ��� ������ ����� � ��� �������� ������ ������� ���� ������ ������
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

//������� push_back, ����������� ������� � ����� �������
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

//������� pop_back, ��������� ��������� ������� � �������
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

//������� ������������ ����� �������
template<class T>
int Vector<T>::length()
{
	return size;
}

//������� ��������� ���� �� ������ 
template<class T>
bool Vector<T>::empty()
{
	if (size != 0)
		return false;
	else
		return true;
}

//������� ������� ��� �������� ������� � ������ ��� ����� = 0
template<class T>
void Vector<T>::clear()
{
	size = 0;
	delete[]el;
	el = new T[size];
}

//������� ��������� ������� � ������� pos
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

//������� ������� k ��������� (�� ��������� 1) ������� � ������� pos
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

//����������
template <class T>
Vector<T>::~Vector()
{
	size = 0;
	delete[]el;
}