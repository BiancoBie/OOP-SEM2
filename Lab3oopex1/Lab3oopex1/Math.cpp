// Lab3oopex1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdarg>
#include <cstring>
#include "Math.h"
using namespace std;

int Math::Add(int a, int b) {
	a = a + b;
	return a;
}

int Math::Add(int a, int b, int c) {
	a = a + b + c;
	return a;
}

int Math::Add(double a, double b) {
	a = a + b;
	return a;
}

int Math::Add(double a, double b, double c) {
	a = a + b + c;
	return a;
}

int Math::Mul(int a, int b) {
	a = a * b;
	return a;
}

int Math::Mul(int a, int b, int c) {
	a = a * b * c;
	return a;
}

int Math::Mul(double a, double b) {
	a = a * b;
	return a;
}

int Math::Mul(double a, double b, double c) {
	a = a * b * c;
	return a;
}

int Math::Add(int count, ...) {
	int sum = 0;
	va_list args;
	va_start(args, count);
	for (int i = 0; i < count; ++i) {
		int num = va_arg(args, int);
		sum += num;
	}
	va_end(args);
	return sum;
}

char* Math::Add(const char* str1, const char* str2) {
	int num1 = atoi(str1);
	int num2 = atoi(str2);
	int sum = num1 + num2;
	char* result = (char*)malloc(12);
	if (result == nullptr)
		return nullptr;
	_itoa(sum, result, 10);
	return result;
}

	/*if (str1 == nullptr || str2 == nullptr)
		return nullptr;
	size_t len1 = strlen(str1);
	size_t len2 = strlen(str2);
	size_t totalLen = len1 + len2 + 1;
	char* result = (char*)malloc(totalLen);
	if (result == nullptr) 
		return nullptr;
	strcpy(result, str1);
	strcat(result, str2);
	return result;
	*/


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
