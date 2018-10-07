#include <iostream>
#include<string.h>
using namespace std;

template<class T>class List;
template<class T>ostream& operator<<(ostream &, const List<T>&);
template<class T>istream& operator>>(istream &, const List<T>&);
template<class T>List<T>operator+(const List<T>&, const List<T>&);


template<class T>
class List {
private:
	T * data;
	int size;

public:
	List(int n =0);
	List(const List &obj);
	~List();
	friend istream& operator>> <T>(istream &is, const List<T> &obj) ;
	friend ostream& operator<< <T>(ostream &os, const List<T>&obj) ;
	friend List<T> operator+<>(const List<T> &obj1, const List<T> &obj2);

};


template<class T>
List<T>::List(int n)
{
	data = new T[n];
	size = n;
}

template<class T>
List<T>::List(const List<T> &obj)
{
	data = new T[obj.size];
	size = obj.size;
	for (int i = 0; i < size; i++)
		data[i] = obj.data[i];
}

template<class T>
List<T>::~List()
{
	delete[] data;
}

template<class T>
istream& operator>>(istream &is,const List<T> &obj)
{
	for (int i = 0; i < obj.size; i++)
	{
		is >> obj.data[i];
	}
	return is;
}

template<class T>
ostream& operator<<(ostream &os, const List<T> &obj)
{
	for (int i = 0; i < obj.size; i++)
		os << obj.data[i] << " ";
	return os;
}

template<class T>
List<T> operator+(const List<T> &obj1, const List<T> &obj2)
{
	List<T> res(obj1.size + obj2.size);
	for (int i = 0; i < obj1.size; i++)
		res.data[i] = obj1.data[i];
	for (int i = 0; i < obj2.size; i++)
		res.data[i + obj1.size] = obj2.data[i];
	return res;
}


int main()
{
	char type[10];
	int n1=0, n2=0;
	cin >> type;
	cin >> n1>>n2;
	if (strcmp(type, "int") == 0)
	{
		List<int> obj1(n1), obj2(n2);
		cin >> obj1;
		cin >> obj2;
		List<int> combination(obj1 + obj2);
		cout << combination << endl;
	}
	else if (strcmp(type, "char") == 0)
	{
		List<char> obj1(n1), obj2(n2);
		cin >> obj1;
		cin >> obj2;
		List<char> combination(obj1 + obj2);
		cout << combination << endl;
	}
	if (strcmp(type, "double") == 0)
	{
		List<double> obj1(n1), obj2(n2);
		cin >> obj1;
		cin >> obj2;
		List<double> combination(obj1 + obj2);
		cout << combination << endl;
	}
	system("PAUSE");
	return 0;
}