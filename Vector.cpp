#include "Vector.h"

template <class T>
Vector<T>::Vector(int n_size)						//коструктор класса по умолчанию
{
	size = n_size;			//задаём значение size которое будет равно заданному n_size(по умолчанию 0)
	el = new T[size];		//создание динамического массива длинной size и типа Т
}

template<class T>
Vector<T>::Vector(const Vector & a)					//конструктор копирования
{
	size = a.size;						//копируем значение в size 
	el = new T[size];					//создание динамического массива длинной size и типа Т
	for (int i = 0; i < size; i++)
	{
		el[i] = a.el[i];				//перенос всех элементов в соответсвующие ячейки
	}
}

//мы имеем оператор имеющий L-value и R-value
//R-value мы передаем в скобочках как статичный вектор
//L-value мы возвращаем значение
template<class T>
Vector<T> &Vector<T>::operator=(Vector&& other)		//описание оператора присваивания(=)
{
	if (this != other)					//проверка чтобы слева и справа не стоял один и тот же элемент
	{
		delete[]el;						//удаляем уже не нужные нам элементы
		size = other.size;				//задаём размер равный копируемому
		el = new T[size];				//создание динамического массива длинной size и типа Т
		for (int i = 0; i < size; i++)	
		{
			el[i] = other.el[i];		//перенос всех элементов в соответсвующие ячейки
		}
	}
	return *this;						//возвращаем в L-value полученный вектор
}

//оператор [] позволяет вернуть значение типа Т содержащиеся в массиве на месте с
template<class T>
T Vector<T>::operator[](int c)
{
		return el[c];
}

//следующие шесть функций - определяют операторы сравнения
//оператор == требует равенство и длины векторов и всех значений векторов
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

//оператор != требует при равенстве длины векторов неравенство хотя бы одного значения векторов
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

//оператор >= требует чтобы вектор слева имел большую или равную длину и все элементы правого вектора были меньше или равны левых
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

//оператор <= требует чтобы вектор справа имел большую или равную длину и все элементы левого вектора были меньше или равны правых
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

//оператор > требует чтобы вектор слева имел большую или равную длину и все элементы правого вектора были меньше левых
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

//оператор < требует чтобы вектор справа имел большую или равную длину и все элементы левого вектора были меньше правых
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

//функция push_back, добавляющая элемент в конец вектора
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

//функция pop_back, удаляющая последний элемент в векторе
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

//функция возвращающая длину вектора
template<class T>
int Vector<T>::length()
{
	return size;
}

//функция проверяет пуст ли вектор 
template<class T>
bool Vector<T>::empty()
{
	if (size != 0)
		return false;
	else
		return true;
}

//функция удаляет все элементы вектора и делает его длину = 0
template<class T>
void Vector<T>::clear()
{
	size = 0;
	delete[]el;
	el = new T[size];
}

//функция вставляет элемент в позицию pos
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

//функция удаляет k элементов (по умолчанию 1) начиная с позиции pos
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

//деструктор
template <class T>
Vector<T>::~Vector()
{
	size = 0;
	delete[]el;
}