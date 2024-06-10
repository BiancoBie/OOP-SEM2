#include "Apple.h"

string Apple::GetType()
{
	return "Apple ";
}

int Apple::GetQuantity()
{
	return quantity;
}

int Apple::GetPrice()
{
	return price;
}

void Apple::Print()
{
	cout << this->GetType() << "(from = " << from << ") Price = " << this->GetPrice() << " Quantity = " << this->GetQuantity() << endl;
}

Apple::Apple(float price, int quantity, string from)
{
	this->price = price;
	this->quantity = quantity;
	this->from = from;
}
