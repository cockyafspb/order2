#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <vector>
#include <cmath>

struct CPoint {
    double x, y;

    explicit CPoint(double x = double(), double y = double()) : x(x), y(y) {}
};

class Triangle {
private:
    std::vector<CPoint> vec;

    double get_length(CPoint p1, CPoint p2) const;

public:
    Triangle() = default;

    explicit Triangle(std::vector<CPoint> data);

    double square() const;

    void rotate(std::pair<double, double> vector);
};

bool operator==(const Triangle &t1, const Triangle &t2);

bool operator!=(const Triangle &t1, const Triangle &t2);

bool operator<(const Triangle &t1, const Triangle &t2);

bool operator>(const Triangle &t1, const Triangle &t2);

#endif
