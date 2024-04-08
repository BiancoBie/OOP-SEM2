#include <iostream>
#include <cstring>
#include "Math.h"
#define _CRT_SECURE_NO_WARNINGS 
using namespace std;

int main() {
	Math mate;

	int count = 11;
	int suma1= mate.Add(3, 4);
	cout << suma1;
	cout << endl;
	int suma2= mate.Add(1, 2, 3);
	cout << suma2;
	cout << endl;
	int sumad1= mate.Add(5.29, -4.2);
	cout << sumad1;
	cout << endl;
	int sumad2= mate.Add(5.29, -4.2, 3.1);
	cout << sumad2;
	cout << endl;
	int mul1= mate.Mul(5, 6);
	cout << mul1;
	cout << endl;
	int mul2= mate.Mul(10, 8, 5);
	cout << mul2;
	cout << endl;
	int muld1= mate.Mul(3.2, -4.5);
	cout << muld1;
	cout << endl;
	int muld2= mate.Mul(3.23, -4.5, -2.51);
	cout << muld2;
	cout << endl;
	int sum = mate.Add(5, 1, 2, 3, 4, 5);
	cout << "Suma elementelor din lista: " << sum << endl;
	const char* str1 = "352";
	const char* str2 = "10";
	char* result = mate.Add(str1, str2);
	cout << result;
	free(result);

	return 0;
}
