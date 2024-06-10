#include "Book.h"
#include "Article.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;

string Book::GetType() {
    return "Book";
}

int Book::GetQuantity()
{
    return quantity;
}

int Book::GetPrice()
{
    return price;
}

void Book::Print()
{
    cout << this->GetType() << " (Title="<< title << ", Author=" << author << ") Price=" << this->GetPrice() << " Quantity=" << this->GetQuantity()<< endl;
}

Book::Book(float price, int quantity, string name, string author)
{
    this->title = title;
    this->author = author;
    this->quantity = quantity;
    this->price = price;
}




