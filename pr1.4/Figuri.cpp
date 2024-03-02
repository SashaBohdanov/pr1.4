
#include "Figuri.h"
#include <iostream>


Figura::Figura() : x(0.0), y(0.0) {}

void Figura::Init(double x, double y) {
    this->x = x;
    this->y = y;
}

void Figura::Read() {
    std::cout << "Enter x and y coordinates: ";
    std::cin >> x >> y;
}

void Figura::Display() {
    std::cout << "Coordinates: (" << x << ", " << y << ")\n";
}

Kruh::Kruh() : radius(0.0) {}

void Kruh::Init(double x, double y, double radius) {
    Figura::Init(x, y);
    this->radius = radius;
}

void Kruh::Read() {
    Figura::Read();
    std::cout << "Enter the radius: ";
    std::cin >> radius;
}

void Kruh::Display() {
    Figura::Display();
    std::cout << "Radius: " << radius << "\n";
}

void Kruh::Resize(double factor) {
    std::cout << "Resizing not applicable for a circle.\n";
}

void Kruh::Rotate(double angle) {  
      double radians = angle * 3.14159265 / 180.0;
        double newX = x * cos(radians) - y * sin(radians);
        double newY = x * sin(radians) + y * cos(radians);

        x = newX;
        y = newY;
    }

std::string Kruh::toString() const {
    return "Circle";
}

Kvadrat::Kvadrat() : side(0.0) {}

void Kvadrat::Init(double x, double y, double side) {
    Figura::Init(x, y);
    this->side = side;
}

void Kvadrat::Read() {
    Figura::Read();
    std::cout << "Enter the side length: ";
    std::cin >> side;
}

void Kvadrat::Display() {
    Figura::Display();
    std::cout << "Side length: " << side << "\n";
}

void Kvadrat::Resize(double factor) {
    side *= factor;
}

void Kvadrat::Rotate(double angle) {
   double radians = angle * 3.14159265 / 180.0;
        double newX = x * cos(radians) - y * sin(radians);
        double newY = x * sin(radians) + y * cos(radians);

        x = newX;
        y = newY;
}

std::string Kvadrat::toString() const {
    return "Square";
}

Pryamokutnik::Pryamokutnik() : width(0.0), height(0.0) {}

void Pryamokutnik::Init(double x, double y, double width, double height) {
    Figura::Init(x, y);
    this->width = width;
    this->height = height;
}

void Pryamokutnik::Read() {
    Figura::Read();
    std::cout << "Enter the width and height: ";
    std::cin >> width >> height;
}

void Pryamokutnik::Display() {
    Figura::Display();
    std::cout << "Width: " << width << ", Height: " << height << "\n";
}

void Pryamokutnik::Resize(double factor) {
    width *= factor;
    height *= factor;
}

void Pryamokutnik::Rotate(double angle) {
  
        double radians = angle * 3.14159265 / 180.0;

        // Calculate new coordinates after rotation
        double newX = x * cos(radians) - y * sin(radians);
        double newY = x * sin(radians) + y * cos(radians);

        x = newX;
        y = newY;
    }

std::string Pryamokutnik::toString() const {
    return "Rectangle";
}
