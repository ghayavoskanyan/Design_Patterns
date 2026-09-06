#include "OCP.cpp"

int main()
{
    std::vector<std::unique_ptr<Shape>> shapes;

    shapes.push_back(std::make_unique<Circle>());
    shapes.push_back(std::make_unique<Square>());

    draw(shapes);

    return 0;
}