//
// Created by Николай on 25.02.2022.
//
#include <iostream>
#include <cmath>

class Figure {
public:
    Figure() = default;

    virtual ~Figure() = default;

    virtual double getPerimeter() {
        return perimeter;
    }

    virtual double getSquare() {
        return square;
    }

    virtual void getInfo() {
        std::cout << "-----//-----" << std::endl;
        std::cout << "Name: " << this->name << std::endl;
        std::cout << "Perimeter: " << this->perimeter << std::endl;
        std::cout << "Square: " << this->square << std::endl;
        getMoreInfo();
        std::cout << std::endl;
        std::cout << "-----//-----" << std::endl;
    }

    virtual void getMoreInfo() {};

protected:
    double perimeter{}, square{};
    std::string name;
};

class Circle : public Figure {
public:
    explicit Circle(double radius) {
        name = "Circle";
        this->radius = radius;
        perimeter = 2 * std::acos(-1) * radius;
        square = std::acos(-1) * radius * radius;
    }
    void getMoreInfo() override {
        std::cout << "Radius: " << this->radius;
    }
private:
    double radius;
};

// эллипс, круг, многоугольник, треугольник, четырёхугольник, прямоугольник, квадрат.

class RegularPolygon : public Figure {
public:
    RegularPolygon(double a, int n) : a(a), n(n)
    {
        name = "Regular polygon";
        perimeter = a * n;
        square = n * a * a / (4 * std::tan(180 / n));
    }

    void getMoreInfo() override {
        std::cout << "Number of sides: " << n << std::endl;
        std::cout << "Side: " << a << std::endl;
    }

private:
    double a;
    int n;
};

class Triangle : public Figure {
public:
    Triangle(double a, double b, double c) : a(a), b(b), c(c) {
        name = "Triangle";
        perimeter = a + b + c;
        square = std::sqrt(perimeter * (perimeter - a) * (perimeter - b) * (perimeter - c));
    }
    void getMoreInfo() override{
        std::cout << "Sides: " << a << ", " << b << ", " << c << std::endl;
    }
private:
    double a, b, c;
};

class Quadrilateral : public Figure {
public:
    Quadrilateral(double a, double b, double c, double d) : a(a), b(b), c(c), d(d) {
        name = "Quadrilateral";
        perimeter = a + b + c + d;
        square = std::sqrt(perimeter * (perimeter - a) * (perimeter - b) * (perimeter - c) * (perimeter - d));
    }

    void getMoreInfo() override {
        std::cout << "Sides: " << a << ", " << b << ", " << c << ", " << d << std::endl;
    }
protected:
    double a, b, c, d;
};

class Square : public Figure {
public:
    explicit Square(double a) : a(a) {
        name = "Square";
        perimeter = 4 * a;
        square = a * a;
    }
    void getMoreInfo() override{
        std::cout << "Side: " << a;
    }
private:
    double a;
};

class Rectangle : public Figure {
public:
    Rectangle(double a, double b) : a(a), b(b) {
        name = "Rectangle";
        perimeter = 2 * (a + b);
        square = a * b;
    }

    void getMoreInfo() override {
        std::cout << "Sides: " << a << ", " << b;
    }
private:
    double a, b;
};

class Ellipse : public Figure {
public:
    Ellipse(double a, double b) : a(a), b(b) {
        name = "Ellipse";
        perimeter = 4 * (std::acos(-1) * a * b + (a - b) * (a - b)) / (a + b);
        square = std::acos(-1) * a *b;
    }
     void getMoreInfo() override {
        std::cout << "The length of the semi-axes of the ellipse: " << a << ", " << b;
    }
private:
    double a, b;
};



int main() {
    Figure* f[7];
    f[0] = new Circle(8);
    f[1] = new Rectangle(3, 4);
    f[2] = new Square(5);
    f[3] = new Quadrilateral(1, 2, 3, 4);
    f[4] = new Triangle(3, 4, 5);
    f[5] = new RegularPolygon(6, 4);
    f[6] = new Ellipse(3, 4);
    for (auto & i : f) {
        i->getInfo();
        std::cout << "Perimeter again: " << i->getPerimeter() << "; and Square again: " << i->getSquare() << std::endl;
    }
    return 0;
}