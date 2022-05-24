#include "Triangle.h"
#include "MyQueue.h"
#include <iostream>
int main() {
    MyQueue q;
    q << 5 << 6 << 7 << 1;
    while (!q.IsEmpty()){
        int elm1, elm2;
        q >> elm1 >> elm2;
        std::cout << elm1 + elm2 << "\n";
    }

    CPoint p1(1, 1), p2(4, 5), p3(2,10);
    std::vector<CPoint> vec;
    vec.emplace_back(p1);
    vec.emplace_back(p2);
    vec.emplace_back(p3);
    Triangle tr(vec);
    std::cout << tr.square();
    return 0;
}
