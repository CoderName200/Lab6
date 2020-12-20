#pragma once
#include"figure.h";

class Triangle : public Figure {
public:
    Triangle(double a, double b, double c);

    double area();
    void show();
protected:
    double a, b, c;
};