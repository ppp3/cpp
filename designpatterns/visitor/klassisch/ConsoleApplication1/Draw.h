#include "Visitor.h"
#include "Circle.h"
#include "Square.h"
#include <iostream>
using std::cout;
using std::endl;

class Draw: public Visitor
{
    public:
       
        void visit(const Circle & c) const override{cout <<"circle: radius="<<c.radius()<<endl;}
        void visit(const Square & s) const override{cout <<"Square: side="<<s.side()<<endl;}
        
};
