#include "algorithms.h"
#include "rational.h"

#include <iostream>
#include <vector>

template<class T>
bool plus(T x) {
    return x > 0;
}

template<class T>
bool equal(T a, T b) {
    return a == b;
}
// if rational num == 1/2;
bool func(Rational num){
    Rational tmp(1, 2);
    return num == tmp;
}


int main() {
    std::vector<int> vec{6, 2, 4, 4, 2, 6};
    bool (*p)(int x);
    p = &plus;
    if (algs::any_of(vec.begin(), vec.end(), p)){
        std::cout << "YES\n";
    }
    else{
        std::cout << "NO\n";
    }
    bool (*i)(int x, int y);
    i = &equal;
    if (algs::is_palindrome(vec.begin(), vec.begin() + vec.size()/2, vec.rbegin(), i)){
        std::cout << "YES\n";
    }
    else{
        std::cout << "NO\n";
    }

    std::vector <Rational> numbers;
    Rational p1(1, 2);
    Rational p2(2, 3);
    Rational p3(3, 4);
    Rational p4(6, 7);
    numbers.push_back(p1);
    numbers.push_back(p2);
    numbers.push_back(p3);
    numbers.push_back(p4);
    bool (*ptr)(Rational num);
    ptr = &func;
    if (algs::one_of(numbers.begin(), numbers.end(), ptr)) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }

    return 0;
}