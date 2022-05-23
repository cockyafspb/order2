#ifndef Rational_H
#define Rational_H

class Rational
{
public:
    explicit Rational(int numerator = 0, int denominator = 1): numerator_(numerator), denominator_(denominator) {}

    Rational& operator+=(Rational const & Rational){
        numerator_ = numerator_ * Rational.denominator_ + denominator_ * Rational.numerator_;
        denominator_ *= Rational.denominator_;
        return *this;
    }

    Rational& operator-=(Rational const & Rational){
        numerator_ = numerator_ * Rational.denominator_ - denominator_ * Rational.numerator_;
        denominator_ *= Rational.denominator_;
        return *this;
    }

    Rational& operator*=(Rational const & Rational){
        numerator_ *= Rational.numerator_;
        denominator_ *= Rational.denominator_;
        return *this;
    }

    Rational& operator/=(Rational const & Rational){
        numerator_ *= Rational.denominator_;
        denominator_ *= Rational.numerator_;
        return *this;
    }

    Rational operator-() const{
        Rational x(-numerator_, denominator_);
        return x;
    }

    Rational operator+() const{
        Rational x(numerator_, denominator_);
        return x;
    }

    // для совместимости с целыми числами
    #define GENERATE_OP(op) \
    Rational operator op(Rational lhs, const Rational& rhs) { \
        return lhs op##= rhs; \
    }

    friend GENERATE_OP(+)
    friend GENERATE_OP(-)
    friend GENERATE_OP(*)
    friend GENERATE_OP(/)

    friend bool operator<(Rational const & r1, Rational const & r2){
        return (r1.numerator_ * r2.denominator_ < r2.numerator_ * r1.denominator_);
    }

    friend bool operator<=(Rational const & r1, Rational const & r2){
        return (r1.numerator_ * r2.denominator_ <= r2.numerator_ * r1.denominator_);
    }

    friend bool operator>(Rational const & r1, Rational const & r2){
        return (r1.numerator_ * r2.denominator_ > r2.numerator_ * r1.denominator_);
    }

    friend bool operator>=(Rational const & r1, Rational const & r2){
        return (r1.numerator_ * r2.denominator_ >= r2.numerator_ * r1.denominator_);
    }

    friend bool operator==(Rational const & r1, Rational const & r2){
        return (r1.numerator_ == r2.numerator_ && r1.denominator_ == r2.denominator_);
    }

    friend bool operator!=(Rational const & r1, Rational const & r2){
        return !(r1 == r2);
    }
private:
    int numerator_;
    int denominator_;
};

#endif