#pragma once
#include "Visitor.h"

class Shape
{
    public:
        virtual ~Shape()=default;
        virtual void accept(const Visitor& v) =0;
};
