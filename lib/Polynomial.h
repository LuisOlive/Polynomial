#include <iostream>
#include <vector>

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

using std::vector;

class Polynomial
{
public:
  // equivalent to x
  static const Polynomial x;
  // polynomial coefficients, indexes are the x grades
  vector<double> coeffs;

  Polynomial();
  Polynomial(const double n);
  Polynomial(const Polynomial &p);
  Polynomial(const vector<double> coeffs);
  Polynomial(const std::initializer_list<double> coeffs);
  ~Polynomial();

  /*
    the max exponent

    if you use method grade() in a for loop, you must use i=0; i<= pol.grade().
    to avoid confussions, use size() method in for loops
  */
  int grade() const;

  /*
    cofficients vector size shortcut

    if you use method grade() in a for loop, you must use i=0; i<= pol.grade(); i++
    to avoid confussions, use size() method in for loops
  */
  int size() const;

  Polynomial derivative() const;
  // don't forget to print the " + c" :)
  Polynomial integral() const;

  double operator[](const int i) const;
  double &operator[](const int i);
  
  Polynomial operator=(const Polynomial &p);
  Polynomial operator()(const double n);

  Polynomial operator+(const Polynomial &p);
  Polynomial operator-(const Polynomial &p);
  Polynomial operator*(const Polynomial &p);
  Polynomial operator/(const Polynomial &p);
  Polynomial operator%(const Polynomial &p);
  Polynomial operator^(const int n);

  Polynomial operator+=(const Polynomial &p);
  Polynomial operator-=(const Polynomial &p);
  Polynomial operator*=(const Polynomial &p);
  Polynomial operator/=(const Polynomial &p);
  Polynomial operator%=(const Polynomial &p);
  Polynomial operator^=(const int n);
};

std::ostream &operator<<(std::ostream &cout, const Polynomial &p);

Polynomial pow(const Polynomial &p, const double n);

#endif