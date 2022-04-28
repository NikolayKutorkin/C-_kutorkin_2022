//
// Created by Николай on 28.04.2022.
//
#include <iostream>

class Rational {
protected:
    int a;
    int b;
public:
    // Конструктор дроби, здесь a - числитель, b - знаменатель
    Rational(int a, int b) : a(a), b(b) {}

    // Реализуйте операторы:
    // - сложения двух дробей
    Rational operator+(const Rational &r) const {
        return {(a * r.b + r.a * b), b * r.b};
    }

    // - вычитания двух дробей
    Rational operator-(const Rational &r) const {
        return {(a * r.b - r.a * b), b * r.b};
    }

    // - умножения двух дробей
    Rational operator*(const Rational &r) const {
        return {a * r.a, b * r.b};
    }

    // - деления двух дробей
    Rational operator/(const Rational &r) const {
        return {a * r.b, b * r.a};
    }

    // - умножения дроби на целое число (должно работать при любом порядке операндов)
    Rational operator*(int &x) const {
        return {a * x, b};
    }

    friend Rational operator*(const int &x, const Rational &r);

    friend std::ostream &operator<<(std::ostream &os, const Rational &r);
};

Rational operator*(const int &x, const Rational &r) {
    return {r.a * x, r.b};
}

std::ostream &operator<<(std::ostream &os, const Rational &r) {
    os << r.a << '/' << r.b;
    return os;
}