//
// Created by Николай on 28.04.2022

#include <cmath>

class Point {
protected:
    int x;
    int y;

public:
    Point(int x, int y) : x(x), y(y) {
    }

    Point operator+(const Point &a) const {
        return Point(x + a.x, y + a.y);
    }

    Point operator-(const Point &a) const {
        return Point(x - a.x, y - a.y);
    }

    double dist() const {
        return sqrt(x * x + y * y);
    }
};

class Triangle {
protected:
    Point a;
    Point b;
    Point c;
public:
    // Создать треугольник из трёх точек
    Triangle(const Point &a, const Point &b, const Point &c) : a(a), b(b), c(c) {}

    // Посчитать и вернуть периметр треугольника
    double perimeter() const {
        auto _a = b - a;
        auto _b = c - b;
        auto _c = a - c;
        return _a.dist() + _b.dist() + _c.dist();
    }
};