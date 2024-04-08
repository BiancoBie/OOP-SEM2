// lab7OOPex1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

float operator"" _Kelvin(unsigned long long int a)
{
    return (a - 273.15);
}

float operator"" _Fahrenheit(unsigned long long int b)
{
    return ((b - 32) / 1.8);
}

int main() {
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;
    cout << "Gradele lui a din Kelvin in Celsius sunt: " << a;
    cout << endl;
    cout << "Gradele lui b din Fahrenheit in Celsius sunt: " << b;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
