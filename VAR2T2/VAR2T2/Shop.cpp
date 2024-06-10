#include "Shop.h"
#include "Article.h"

void Shop::Add(Article* x)
{
	items.push_back(x);
}

int Shop::GetTotalPrice()
{
	float sum = 0;
	for (auto i : items) {
		sum += i->GetPrice() * i->GetQuantity();
	}
	return sum;
}

int Shop::GetQuantity(string type)
{
	int totalq = 0;
	for (auto i : items) {
		if (i->GetType() == "Apple ")
		totalq += i->GetQuantity();
	}
	return totalq;
}

void Shop::List()
{
	for (auto i : items) {
		i->Print();
	}
}
