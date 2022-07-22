#include "Polynomial.h"

const Polynomial Polynomial::x = {0, 1};

Polynomial::Polynomial(){};

Polynomial::Polynomial(const double n){
  coeffs = {n};
}

Polynomial::Polynomial(const Polynomial &p) {
  coeffs = p.coeffs;
}

Polynomial::Polynomial(const vector<double> coeffs) {
  this->coeffs = coeffs;
}

Polynomial::Polynomial(const std::initializer_list<double> coeffs){
  this->coeffs = coeffs;
}

Polynomial::~Polynomial(){};