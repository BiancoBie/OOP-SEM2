#pragma once
#include<iostream>
#include<vector>
#include<string>
#include "Article.h"
using namespace std;

class Shop{
private:
	vector<Article*> items;
public:
	void Add(Article* x);
	int GetTotalPrice();
	int GetQuantity(string type);
	void List();
};

