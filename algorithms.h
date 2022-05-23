#ifndef ALGO_H
#define ALGO_H

namespace algs{
    template<class InputIt, class UnaryPredicate>
    bool any_of(InputIt first, InputIt last, UnaryPredicate p) {
        for (; first != last; ++first) {
            if (p(*first)) {
                return true;
            }
        }
        return false;
    }

    template<class InputIt, class UnaryPredicate>
    bool one_of(InputIt first, InputIt last, UnaryPredicate p) {
        int counter = 0;
        for (; first != last; ++first) {
            if (p(*first)) {
                ++counter;
                if (counter > 1)
                    return false;
            }
        }
        if (counter == 1) return true;
        return false;
    }

    template<class InputIt1, class InputIt2, class BinaryPredicate>
    bool is_palindrome(InputIt1 first1, InputIt1 last1,
                       InputIt2 first2, BinaryPredicate p) {
        for (; first1 != last1; ++first1, ++first2) {
            if (!p(*first1, *first2)) {
                return false;
            }
        }
        return true;
    }
}

#endif