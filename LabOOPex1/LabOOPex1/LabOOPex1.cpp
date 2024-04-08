// LabOOPex1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>
using namespace std;

int stringtoint(char* str)
{
    int numar = 0;
    while (*str != '\0' and *str != '\n') {
        numar = numar * 10 + (*str - '0');
        str++;
    }
    return numar;
}

int main()
{
    FILE* f;
    int s = 0;
    char rand[50];
    f=fopen("in.txt", "r");
    while (fgets(rand,sizeof(rand), f))
    {
        s = s + stringtoint(rand);
    }

    printf(" %d ", s);
    fclose(f);
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
