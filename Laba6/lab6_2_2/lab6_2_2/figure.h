#pragma once

class Figure {
public:
    virtual double area() { return 0; };
    virtual void show() {};
};

class Circle : public Figure {
public:
    Circle(double r);
    double area();
    void show();
protected:
    double r;
};

class Rectangle : public Figure {
public:
    Rectangle(double d1, double d2 =0) ;

    double area();
    void show();
protected:
    double d1, d2;
};