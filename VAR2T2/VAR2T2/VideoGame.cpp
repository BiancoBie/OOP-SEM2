#include "VideoGame.h"
#include<iostream>
using namespace std;

string VideoGame::GetType()
{
	return "VideoGame ";
}

int VideoGame::GetQuantity()
{
	return quantity;
}

int VideoGame::GetPrice()
{
	return price;
}

void VideoGame::Print()
{
	cout << this->GetType() << "(Platform=" << platform << ", Name=" << name << ") Price=" << this->GetPrice() << " Quantity=" << this->GetQuantity() << endl;
}

VideoGame::VideoGame(float price, int quantity, string platform, string name)
{
	this->platform = platform;
	this->name = name;
	this->quantity = quantity;
	this->price = price;
}


