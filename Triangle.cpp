#include "Triangle.h"

double Triangle::get_length(CPoint p1, CPoint p2) const {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

Triangle::Triangle(std::vector<CPoint> data) : vec(data) {}

double Triangle::square() const {
    double a = get_length(vec[0], vec[1]);
    double b = get_length(vec[1], vec[2]);
    double c = get_length(vec[0], vec[2]);
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

void Triangle::rotate(std::pair<double, double> vector) {
    for (auto it: vec) {
        it.x += vector.first;
        it.y += vector.second;
    }
}

bool operator==(const Triangle &t1, const Triangle &t2) {
    return t1.square() == t2.square();
}

bool operator!=(const Triangle &t1, const Triangle &t2) {
    return !(t1 == t2);
}

bool operator<(const Triangle &t1, const Triangle &t2) {
    return t1.square() < t2.square();
}

bool operator>(const Triangle &t1, const Triangle &t2) {
    return !(t1 == t2) && !(t1 < t2);
}