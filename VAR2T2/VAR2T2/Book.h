#pragma once
#include <iostream>
#include<string>
#include "Article.h"
using namespace std;

class Book : public Article
{
public:
	string GetType() override;
	int GetQuantity() override;
	int GetPrice() override;
	void Print() override;
	Book(float price, int quantity, string name, string author);
private:
	string type;
	string title;
	string author;
	float price;
	int quantity;
	
};

