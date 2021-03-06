#include "FieldElem.h"

FieldVec FieldElem::irreducible_polynomial(0);
BoolVec BoolFieldElem::irreducible_polynomial(0);

FieldElem::FieldElem(unsigned long long z){
    v = FieldVec(z) % irreducible_polynomial;
}

FieldElem::FieldElem(FieldVec &t){
    v = t % irreducible_polynomial;
}

FieldElem &FieldElem::operator+=(FieldElem &a){
    v += a.v;
    return *this;
}

FieldElem FieldElem::operator+(FieldElem &a){
    FieldElem b = *this;
    b += a;
    return b;
}

FieldElem &FieldElem::operator*=(FieldElem &a){
    v = (v * a.v) % irreducible_polynomial;
    return *this;
}

FieldElem FieldElem::operator*(FieldElem &a){
    FieldElem r = *this;
    r *= a;
    return r;
}

FieldElem FieldElem::pow(unsigned int p){
    FieldElem power(1);
    if(p == 0){
        return power;
    }
    p = p % FieldVec::q;
    if(p == 0){
        p += FieldVec::q;
    }
    while(p){
        power *= *this;
        p--;
    }
    return power;
}





BoolFieldElem::BoolFieldElem(unsigned long long z){
    v = BoolVec(z) % irreducible_polynomial;
}

BoolFieldElem::BoolFieldElem(BoolVec &t){
    v = t % irreducible_polynomial;
}

BoolFieldElem &BoolFieldElem::operator+=(BoolFieldElem &a){
    v += a.v;
    return *this;
}

BoolFieldElem BoolFieldElem::operator+(BoolFieldElem &a){
    BoolFieldElem b = *this;
    b += a;
    return b;
}

BoolFieldElem &BoolFieldElem::operator*=(BoolFieldElem &a){
    v = (v * a.v) % irreducible_polynomial;
    return *this;
}

BoolFieldElem BoolFieldElem::operator*(BoolFieldElem &a){
    BoolFieldElem r = *this;
    r *= a;
    return r;
}

BoolFieldElem BoolFieldElem::pow(unsigned int p){
    BoolFieldElem power(1);
    if(p == 0){
        return power;
    }
    p = p % FieldVec::q;
    if(p == 0){
        p += FieldVec::q;
    }
    while(p){
        power *= *this;
        p--;
    }
    return power;
}
