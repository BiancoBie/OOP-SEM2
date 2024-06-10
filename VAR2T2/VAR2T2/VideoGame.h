#pragma once
#include <iostream>
#include<string>
#include "Article.h"
using namespace std;

class VideoGame : public Article
{
public:
	string GetType() override;
	int GetQuantity() override;
	int GetPrice() override;
	void Print() override;
	VideoGame(float price, int quantity, string platform, string name);
private:
	string type;
	string platform;
	string name;
	float price;
	int quantity;
};
