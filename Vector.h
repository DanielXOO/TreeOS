#pragma once
//подробная информация о функциях находиться в файле описания "Vector.cpp"
template<class T>							//создание шаблонного класса Vector
class Vector
{
	int size;								//переменная отвечающая за количество элементов в векторе
	T *el;									//динамический массив типа Т
public:
	Vector(int n_size = 0);					//коструктор класса по умолчанию
	Vector(const Vector& a);				//конструктор копирования
	Vector& operator=(Vector&& other);		//описание оператора присваивания(=)
	T operator[](int c);					//описание оператора []
	bool operator==(const Vector& a);		//оператор сравнения ==
	bool operator!=(const Vector& a);		//оператор сравнения !=
	bool operator>=(const Vector& a);		//оператор сравнения >=
	bool operator<=(const Vector& a);		//оператор сравнения <=
	bool operator>(const Vector& a);		//оператор сравнения >
	bool operator<(const Vector& a);		//оператор сравнения <
	void push_back(T elem);					//функция добавляющая элемент в конец вектора
	void pop_back();						//функция удаляющая последний элемент в векторе
	int length();							//функция возвращающая длину вектора
	bool empty();							//функция проверяет пуст ли вектор  
	void clear();							//функция удаляет все элементы вектора и делает его длину = 0
	void insert(int pos,T elem);			//функция вставляет элемент в позицию pos
	void erase(int pos, int k = 1);			//функция удаляет k элементов (по умолчанию 1) начиная с позиции pos
	~Vector();								//деструктор
};

