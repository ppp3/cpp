#pragma once;
#include "Shape.h"

class Circle : public Shape
{
    public:
        explicit Circle(double radius):Shape(),radius_(radius)
        {
        
        }
        
        void accept(const Visitor& v) override
        {
            v.visit(*this);
        }
        
        double radius() const {
            return radius_;
            
        }
    
    private:
        double radius_;
        
};
