// Figuri.h
#ifndef FIGURI_H
#define FIGURI_H

#include <iostream>
#include <string>

class Figura {
protected:
    double x, y; // координати
public:
    Figura();
    void Init(double x, double y);
    void Read();
    void Display();
    virtual void Resize(double factor) = 0; // чисто віртуальна функція
    virtual void Rotate(double angle) = 0; // чисто віртуальна функція
    virtual std::string toString() const = 0;
};

class Kruh : public Figura {
private:
    double radius;
public:
    Kruh();
    void Init(double x, double y, double radius);
    void Read();
    void Display();
    void Resize(double factor); // Оновлено метод Resize
    void Rotate(double angle);
    std::string toString() const;
};

class Kvadrat : public Figura {
private:
    double side;
public:
    Kvadrat();
    void Init(double x, double y, double side);
    void Read();
    void Display();
    void Resize(double factor) override; // Оновлено метод Resize
    void Rotate(double angle);
    std::string toString() const;
};

class Pryamokutnik : public Figura {
private:
    double width, height;
public:
    Pryamokutnik();
    void Init(double x, double y, double width, double height);
    void Read();
    void Display();
    void Resize(double factor) override; // Оновлено метод Resize
    void Rotate(double angle);
    std::string toString() const;
};

#endif // FIGURI_H
