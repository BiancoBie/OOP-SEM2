#ifndef NUMBER_H
#define NUMBER_H

class Number {
public:
    Number(const char* value, int base);
    Number(int value);
    Number(const Number& other);
    Number(Number&& other) noexcept;
    ~Number();

    Number& operator=(const Number& other);
    Number& operator=(Number&& other) noexcept;
    Number& operator=(int value);
    Number& operator=(const char* value);

    friend Number operator+(const Number& a, const Number& b);
    friend Number operator-(const Number& a, const Number& b);

    Number& operator+=(const Number& other);
    Number& operator-=(const Number& other);
    Number& operator--();
    Number operator--(int);

    char operator[](int i) const;
    bool operator==(const Number& other) const;
    bool operator!=(const Number& other) const;
    bool operator>(const Number& other) const;
    bool operator<(const Number& other) const;
    bool operator>=(const Number& other) const;
    bool operator<=(const Number& other) const;

    void SwitchBase(int newBase);
    void Print() const;
    int GetDigitsCount() const;
    int GetBase() const;

private:
    char* digits_;
    int base_;
    int size_;

    void Init(const char* value, int base);
    void Resize(int new_size);
};
#endif