#pragma once
//��������� ���������� � �������� ���������� � ����� �������� "Vector.cpp"
template<class T>							//�������� ���������� ������ Vector
class Vector
{
	int size;								//���������� ���������� �� ���������� ��������� � �������
	T *el;									//������������ ������ ���� �
public:
	Vector(int n_size = 0);					//���������� ������ �� ���������
	Vector(const Vector& a);				//����������� �����������
	Vector& operator=(Vector&& other);		//�������� ��������� ������������(=)
	T operator[](int c);					//�������� ��������� []
	bool operator==(const Vector& a);		//�������� ��������� ==
	bool operator!=(const Vector& a);		//�������� ��������� !=
	bool operator>=(const Vector& a);		//�������� ��������� >=
	bool operator<=(const Vector& a);		//�������� ��������� <=
	bool operator>(const Vector& a);		//�������� ��������� >
	bool operator<(const Vector& a);		//�������� ��������� <
	void push_back(T elem);					//������� ����������� ������� � ����� �������
	void pop_back();						//������� ��������� ��������� ������� � �������
	int length();							//������� ������������ ����� �������
	bool empty();							//������� ��������� ���� �� ������  
	void clear();							//������� ������� ��� �������� ������� � ������ ��� ����� = 0
	void insert(int pos,T elem);			//������� ��������� ������� � ������� pos
	void erase(int pos, int k = 1);			//������� ������� k ��������� (�� ��������� 1) ������� � ������� pos
	~Vector();								//����������
};

