#include <iostream>

#include "lib/Polynomial.h"

using namespace std;

int main(){
  auto& x = Polynomial::x;
  vector<double> vect = {4,7,-3,5};
  Polynomial p = {1, 6, 3};
  Polynomial q = vect;
  
  cout << "p(x) = " << p << endl;
  cout << "q(x) = " << q << endl;

  cout << endl;

  cout << "(p + q)(x) = " << (p + q) << endl;
  cout << "(p - q)(x) = " << (p - q) << endl;
  cout << "(p * q)(x) = " << (p * q) << endl;

  cout << endl;

  cout << "grade of p: " << p.grade() << endl;
  cout << "grade of q: " << q.grade() << endl;
  
  cout << endl;
  
  cout << "p(x) = " << p << endl;
  cout << "p'(x) = " << p.derivative() << endl;
  cout << "P(x) = " << p.integral() << " + c" << endl;
  
  cout << endl;
  
  cout << "q(x) = " << q << endl;
  cout << "q'(x) = " << q.derivative() << endl;
  cout << "Q(x) = " << q.integral() << " + c" << endl;

  cout << endl;


  Polynomial f = {0, -1, 0, 1, 0, -1, -2, 0};

  cout << f << endl;
  cout << "grade of f: " << f.grade() << endl;
  cout << "size of f: " << f.size() << endl;

  cout << endl;
  cout << "x = " << x << endl;
  
  f = x;
  cout << f << endl;
  
  f += x;
  cout << f << endl;

  f *= x;
  cout << f << endl;

  return 0;
}