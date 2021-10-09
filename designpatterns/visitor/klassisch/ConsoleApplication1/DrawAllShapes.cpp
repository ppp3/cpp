#include "DrawAllShapes.h"
#include "Draw.h"

void draw(Shapes const& shapes)
{
    for(auto const& shape:shapes)
    {
        shape->accept(Draw());
    }
}
