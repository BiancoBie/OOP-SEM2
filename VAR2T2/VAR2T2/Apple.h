#pragma once
#include <iostream>
#include <string>
#include "Article.h"
using namespace std;

class Apple : public Article
{
public:
	string GetType() override;
	int GetQuantity() override;
	int GetPrice() override;
	void Print() override;
	Apple(float price, int quantity, string from);
private:
	string type;
	string from;
	float price;
	int quantity;
};

