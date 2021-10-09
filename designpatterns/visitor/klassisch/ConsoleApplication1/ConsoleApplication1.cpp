// ConsoleApplication1.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//
#include "Circle.h";
#include "Draw.h";
#include "DrawAllShapes.h";
#include "Shape.h";
#include "Square.h";
#include "Visitor.h"

#include <iostream>

int main()
{
    Shapes shapes{};
    shapes.push_back(std::make_unique<Circle>(2.3));
    shapes.push_back(std::make_unique<Square>(4.3));
    shapes.push_back(std::make_unique<Circle>(1.3));

    draw(shapes);

    
}

