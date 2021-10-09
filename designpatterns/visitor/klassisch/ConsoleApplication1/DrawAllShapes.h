#include <memory.h>
#include "Shape.h"

using Shapes=std::vector<std::unique_ptr<Shape>>;
void draw(Shapes const& shapes);
