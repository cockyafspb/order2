#include <iostream>
#include <vector>
#include <cmath>

class IGeoFig {
public:
    virtual double square() = 0;

    virtual double perimeter() = 0;
};

class CVector2D {
public:
    double x, y;
};

class IPhysObject {
public:
    virtual double mass() const = 0;

    virtual CVector2D position() const = 0;

    virtual bool operator==(const IPhysObject &ob) const = 0;

    virtual bool operator<(const IPhysObject &ob) const = 0;
};

class IPrintable {
public:
    virtual void draw() = 0;
};

class IDialogInitiable {
public:
    virtual void initFromDialog() = 0;
};

class BaseCObject {
public:
    virtual const char *classname() = 0;

    virtual unsigned int size() = 0;
};

class Circle : IGeoFig, IPhysObject, IPrintable, IDialogInitiable, BaseCObject {
private:
    CVector2D centre;
    double radius;
    const double pi = 3.1415926535;
public:
    Circle() = default;

    Circle(CVector2D point, double r) : centre(point), radius(r) {}

    double square() override {
        return radius * pi * pi;
    }

    double perimeter() override {
        return 2 * pi * radius;
    }

    double mass() const override { return 0; }

    CVector2D position() const override { return centre; }

    bool operator==(const IPhysObject &ob) const override {
        return mass() == ob.mass();
    }

    bool operator<(const IPhysObject &ob) const override {
        return mass() < ob.mass();
    }

    void draw() override {
        std::cout << "Circle: centre (" << centre.x << ";" << centre.y << "), radius = " << radius << "\n";
    }

    void initFromDialog() override {
        std::cout << "Input 3 numbers:\nX-coordinate for centre\nY-coordinate for centre\nRadius value\n";
        double x, y, r;
        std::cin >> x >> y >> r;
        centre.x = x;
        centre.y = y;
        radius = r;
    }

    const char *classname() override { return "Circle"; }

    unsigned int size() override { return sizeof(centre) + sizeof(radius) + sizeof(pi); }
};

class Rectangle : IGeoFig, IPhysObject, IPrintable, IDialogInitiable, BaseCObject {
private:
    std::vector<CVector2D> vec;

    double get_length(CVector2D p1, CVector2D p2) {
        return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
    }

public:
    Rectangle() = default;

    explicit Rectangle(std::vector<CVector2D> data) : vec(data) {}

    double square() override {
        return get_length(vec[0], vec[1]) * get_length(vec[1], vec[2]);
    }

    double perimeter() override {
        return 2 * (get_length(vec[0], vec[1]) + get_length(vec[1], vec[2]));
    }

    double mass() const override { return 0; }

    CVector2D position() const override {
        CVector2D tmp = CVector2D();
        tmp.x = (vec[3].x - vec[0].x) / 2;
        tmp.y = (vec[1].x - vec[0].x) / 2;
        return tmp;
    }

    bool operator==(const IPhysObject &ob) const override {
        return mass() == ob.mass();
    }

    bool operator<(const IPhysObject &ob) const override {
        return mass() < ob.mass();
    }

    void draw() override {
        std::cout << "Rectangle with 4 points:\n(" << vec[0].x << ";" << vec[0].y << "), (" << vec[1].x << ";"
                  << vec[1].y << "), (" << vec[2].x << ";" << vec[2].y << "), (" << vec[3].x << ";" << vec[3].y
                  << ")\n";
    }

    void initFromDialog() override {
        std::cout << "Input 2 numbers:\nX-coordinate for centre\nY-coordinate for centre\nDo it 4 times\n";
        for (int i = 0; i < 4; ++i){
            int x, y;
            std::cin >> x >> y;
            CVector2D tmp = CVector2D();
            tmp.x = x;
            tmp.y = y;
            vec.emplace_back(tmp);
        }
    }

    const char *classname() override { return "Rectangle"; }

    unsigned int size() override { return (4 * sizeof(CVector2D) + sizeof(std::vector<CVector2D>)); }
};

int main() {
    Circle krug;
    krug.initFromDialog();
    krug.draw();
    std::cout << krug.square() << " " << krug.perimeter() << " " << krug.size() << "\n";

    Rectangle pr;
    pr.initFromDialog();
    pr.draw();
    std::cout << pr.square() << " " << pr.perimeter() << " " << pr.size() << "\n";
    return 0;
}
