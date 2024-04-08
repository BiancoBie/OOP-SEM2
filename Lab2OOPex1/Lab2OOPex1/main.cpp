#include<iostream>
#include "NumberList.h"
using namespace std;

int main()
{
	NumberList lista;

	lista.Init();

	lista.Add(10);
	lista.Add(25);
	lista.Add(35);
	lista.Add(40);
	lista.Add(15);


	//Lista initiala:
	lista.Print();

	cout << endl;

	lista.Add(30);


	//lista dupa sortare
	lista.Sort();
	lista.Print();

	return 0;
}