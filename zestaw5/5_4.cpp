#include <iostream>

// Abstrakcyjna klasa Drawing
class Drawing {
public:
    virtual void drawLine() = 0;
    virtual void drawCircle() = 0;
};

// Implementacja DP1
class DP1 {
public:
    void draw_a_line() {
        std::cout << "Rysowanie linii za pomocą DP1" << std::endl;
    }

    void draw_a_circle() {
        std::cout << "Rysowanie okręgu za pomocą DP1" << std::endl;
    }
};

// Implementacja DP2
class DP2 {
public:
    void drawline() {
        std::cout << "Rysowanie linni za pomocą DP2" << std::endl;
    }

    void drawcircle() {
        std::cout << "Rysowanie okręgu za pomocą DP2" << std::endl;
    }
};

// Klasa adaptera V1Drawing
class V1Drawing : public Drawing {
private:
    DP1* dp1;

public:
    V1Drawing(DP1* dp1) : dp1(dp1) {}

    void drawLine() {
        dp1->draw_a_line();
    }

    void drawCircle() {
        dp1->draw_a_circle();
    }
};

// Klasa adaptera V2Drawing
class V2Drawing : public Drawing {
private:
    DP2* dp2;

public:
    V2Drawing(DP2* dp2) : dp2(dp2) {}

    void drawLine() {
        dp2->drawline();
    }

    void drawCircle() {
        dp2->drawcircle();
    }
};

// Abstrakcyjna klasa Shape
class Shape {
protected:
    Drawing* drawing;

public:
    Shape(Drawing* drawing) : drawing(drawing) {}

    virtual void draw() = 0;
    virtual void setLib(Drawing* newDrawing) {
        drawing = newDrawing;
    }
};


class Rectangle : public Shape {
public:
    Rectangle(Drawing* drawing) : Shape(drawing) {}

    void draw() {
        std::cout << "Rysowanie prostokątu: ";
        drawing->drawLine();
    }
};


class Circle : public Shape {
public:
    Circle(Drawing* drawing) : Shape(drawing) {}

    void draw() {
        std::cout << "Rysowanie okręgu: ";
        drawing->drawCircle();
    }
};

int main() {
    DP1 library1; // pierwsza biblioteka
    DP2 library2; // druga biblioteka
    Drawing* d1 = new V1Drawing(&library1);
    Drawing* d2 = new V2Drawing(&library2);
    Shape* p1 = new Rectangle(d1);
    Shape* p2 = new Circle(d2);
    p1->draw(); // rectangle linia V1
    p2->draw(); // circle okrąg V2
    p1->setLib(d2);
    p2->setLib(d1);
    p1->draw(); // rectangle linia V2
    p2->draw(); // circle okrąg V1

    delete p1;
    delete p2;
    delete d1;
    delete d2;
}