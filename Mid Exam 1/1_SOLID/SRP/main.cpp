#include "SRP.cpp"

int main() {
    Circle circle(10.0);

    Screen screen;
    Printer printer;
    ByteStream stream;

    CircleRenderer renderer;
    CircleSerializer serializer;

    renderer.draw(circle, screen);
    renderer.draw(circle, printer);
    serializer.serialize(circle, stream);

    return 0;
}