#define _CRT_SECURE_NO_WARNINGS
#include "Number.h"
#include <iostream>
#include <cstring>
#include <stdexcept>
#include <algorithm>

int charToInt(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    else if (c >= 'A' && c <= 'F') {
        return 10 + (c - 'A');
    }
    else if (c >= 'a' && c <= 'f') {
        return 10 + (c - 'a');
    }
    else {
        throw std::invalid_argument("Invalid character");
    }
}

char intToChar(int num) {
    if (num >= 0 && num <= 9) {
        return '0' + num;
    }
    else if (num >= 10 && num <= 15) {
        return 'A' + (num - 10);
    }
    else {
        throw std::invalid_argument("Invalid integer");
    }
}

Number::Number(const char* value, int base) {
    Init(value, base);
}

Number::Number(int value) {
    char str[20];
    sprintf(str, "%d", value);
    Init(str, 10);
}

Number::Number(const Number& other) {
    Init(other.digits_, other.base_);
}

Number::Number(Number&& other) noexcept {
    digits_ = other.digits_;
    base_ = other.base_;
    size_ = other.size_;


    other.digits_ = nullptr;
    other.size_ = 0;
}


Number::~Number() {
    delete[] digits_;
}

Number& Number::operator=(const Number& other) {
    if (this != &other) {
        delete[] digits_;
        Init(other.digits_, other.base_);
    }
    return *this;
}

Number& Number::operator=(Number&& other) noexcept {
    if (this != &other) {
        delete[] digits_;
        digits_ = other.digits_;
        base_ = other.base_;
        size_ = other.size_;

        other.digits_ = nullptr;
        other.size_ = 0;
    }
    return *this;
}

Number& Number::operator=(int value) {
    char str[20];
    sprintf(str, "%d", value);
    Init(str, 10);
    return *this;
}

Number& Number::operator=(const char* value) {
    Init(value, base_);
    return *this;
}

Number operator+(const Number& a, const Number& b) {
    int base = std::max(a.base_, b.base_);
    int maxSize = std::max(a.size_, b.size_) + 1;
    char* result = new char[maxSize + 1];
    result[maxSize] = '\0';

    int carry = 0;
    int idxA = a.size_ - 1;
    int idxB = b.size_ - 1;
    int idxResult = maxSize - 1;

    while (idxA >= 0 || idxB >= 0 || carry > 0) {
        int digitA = (idxA >= 0) ? charToInt(a.digits_[idxA--]) : 0;
        int digitB = (idxB >= 0) ? charToInt(b.digits_[idxB--]) : 0;

        int sum = digitA + digitB + carry;
        result[idxResult--] = intToChar(sum % base);
        carry = sum / base;
    }

    return Number(result, base);
}

Number operator-(const Number& a, const Number& b) {
    int base = std::max(a.base_, b.base_);
    int maxSize = a.size_;
    char* result = new char[maxSize + 1];
    result[maxSize] = '\0';

    int borrow = 0;
    int idxA = a.size_ - 1;
    int idxB = b.size_ - 1;
    int idxResult = maxSize - 1;

    while (idxA >= 0) {
        int digitA = charToInt(a.digits_[idxA--]);
        int digitB = (idxB >= 0) ? charToInt(b.digits_[idxB--]) : 0;

        int diff = digitA - digitB - borrow;
        if (diff < 0) {
            diff += base;
            borrow = 1;
        }
        else {
            borrow = 0;
        }
        result[idxResult--] = intToChar(diff);
    }

    int start = 0;
    while (result[start] == '0') {
        start++;
    }

    if (start == maxSize) {
        return Number("0", base);
    }
    else {
        return Number(result + start, base);
    }
}

Number& Number::operator+=(const Number& other) {
    *this = *this + other;
    return *this;
}

Number& Number::operator-=(const Number& other) {
    *this = *this - other;
    return *this;
}

Number& Number::operator--() {
    if (size_ == 1) {
        delete[] digits_;
        digits_ = nullptr;
        size_ = 0;
    }
    else {
        char* newDigits = new char[size_ - 1];
        for (int i = 0; i < size_ - 1; ++i) {
            newDigits[i] = digits_[i];
        }
        delete[] digits_;
        digits_ = newDigits;
        size_--;
    }
    return *this;
}

Number Number::operator--(int) {
    Number temp(*this);
    --(*this);
    return temp;
}

char Number::operator[](int i) const {
    if (i >= 0 && i < size_) {
        return digits_[i];
    }
    else {
        throw std::out_of_range("Index out of range");
    }
}

bool Number::operator==(const Number& other) const {
    if (size_ != other.size_ || base_ != other.base_) {
        return false;
    }
    for (int i = 0; i < size_; ++i) {
        if (digits_[i] != other.digits_[i]) {
            return false;
        }
    }
    return true;
}

bool Number::operator!=(const Number& other) const {
    return !(*this == other);
}

bool Number::operator>(const Number& other) const {
    if (base_ != other.base_) {
        throw std::invalid_argument("Cannot compare numbers with different bases");
    }

    if (size_ > other.size_) {
        return true;
    }
    else if (size_ < other.size_) {
        return false;
    }
    else {
        for (int i = 0; i < size_; ++i) {
            if (digits_[i] > other.digits_[i]) {
                return true;
            }
            else if (digits_[i] < other.digits_[i]) {
                return false;
            }
        }
        return false;
    }
}

bool Number::operator<(const Number& other) const {
    return !(*this > other || *this == other);
}

bool Number::operator>=(const Number& other) const {
    return !(*this < other);
}

bool Number::operator<=(const Number& other) const {
    return !(*this > other);
}

void Number::SwitchBase(int newBase) {
    int decimalValue = 0;
    for (int i = 0; i < size_; ++i) {
        decimalValue = decimalValue * base_ + charToInt(digits_[i]);
    }

    int temp = decimalValue;
    int newSize = 0;
    while (temp > 0) {
        temp /= newBase;
        newSize++;
    }

    char* newDigits = new char[newSize];
    for (int i = newSize - 1; i >= 0; --i) {
        newDigits[i] = intToChar(decimalValue % newBase);
        decimalValue /= newBase;
    }

    delete[] digits_;
    digits_ = newDigits;
    size_ = newSize;
    base_ = newBase;
}

void Number::Print() const {
    for (int i = 0; i < size_; ++i) {
        std::cout << digits_[i];
    }
    std::cout << std::endl;
}

int Number::GetDigitsCount() const {
    return size_;
}

int Number::GetBase() const {
    return base_;
}

void Number::Init(const char* value, int base) {
    int length = strlen(value);
    digits_ = new char[length];
    base_ = base;
    size_ = length;
    for (int i = 0; i < length; ++i) {
        digits_[i] = value[i];
    }
}