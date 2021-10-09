#pragma once
class Circle;
class Square;
#include <cstdlib>
#include <iostream>
#include <memory>
#include <vector>

class Visitor
{
    
    public:
        virtual ~Visitor()=default;
        virtual void visit(const Circle&) const=0;
        virtual void visit(const Square&) const=0;
};
