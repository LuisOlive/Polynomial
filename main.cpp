#include <iostream>
#include "lib/Polynomial.h"

using namespace std;

void inicializers();
void operations();
void printData(const string name, const Polynomial p);
void print(const string name, const Polynomial p);
void division();
void negativeIndexes();

auto &x = Polynomial::x;

int main()
{
  // inicializers();
  operations();
  // negativeIndexes();
  division();
  return 0;
}

void inicializers()
{
  vector<double> vect = {8, 7, 6, 5};
  Polynomial a, b, c, d, e, f;

  a = {0, -1, 0, 1, 0, -1, -2, 0};
  b = vect;
  c = 5;
  d = (x ^ 4) * 3 + (x ^ 2) * 7;
  e = (x - 3) ^ 3;
  f = 4;

  f <<= 3;

  print("A", a);
  print("B", b);
  print("C", c);
  print("D", d);
  print("E", e);
  print("F", f);
}

void operations()
{
  Polynomial p = {4, 7, -3, 5}, q = {1, 6, 3};

  cout << "p(x) = " << p << endl;
  cout << "q(x) = " << q << endl;

  cout << endl;

  cout << "(p + q)(x) = " << (p + q) << endl;
  cout << "(p - q)(x) = " << (p - q) << endl;
  cout << "(p * q)(x) = " << (p * q) << endl;
  cout << "(p / q)(x) = " << (p / q) << endl;
  cout << "(p % q)(x) = " << (p % q) << endl;

  cout << endl;
}

void print(const string name, const Polynomial p)
{
  cout << name << "(x) = " << p << endl;
}

void printData(const string name, const Polynomial p)
{
  cout << name << "(x) = " << p << endl
       << endl;

  cout << "grade of " << name << ": " << p.grade() << endl
       << endl;

  cout
      << name << "'(x) = " << p.derivative() << endl
      << "|" << name << "(x)dx = " << p.integral() << " + c" << endl
      << endl;

  for (int i = 0; i <= 5; i++)
    cout << name << "(" << i << ") = " << p(i) << endl;

  cout << endl;
}

void negativeIndexes()
{
  //              -6  -5  -4  -3  -2  -1
  Polynomial p = {34, 53, 61, 52, 27, 10, 0, 0, 0};

  p[-2] = 38;

  cout << "p(x) = " << p << endl;
  cout << "grade: " << p.grade() << endl;

  for (int i = 1; i <= p.grade() + 1; i++)
    cout << "p[-" << i << "] -> " << p[-i] << endl;
}

void division()
{
  Polynomial p = {34, 53, 61, 52, 27, 10, 0, 0, 0}, q = {4, 3, 2}, s = {8,5,7}, result, residual;

  cout << "p(x) = " << p << endl;
  cout << "q(x) = " << q << endl;
  cout << "s(x) = " << s << endl << endl;

  p.writeDivision(q, result, residual);

  cout << "(p / q)(x) = " << result << endl;
  cout << "(p % q)(x) = " << residual << endl << endl;
  
  q.writeDivision(p, result, residual);
  
  cout << "(q / p)(x) = " << result << endl;
  cout << "(q % p)(x) = " << residual << endl << endl;
  
  q.writeDivision(s, result, residual);
  
  cout << "(q / s)(x) = " << result << endl;
  cout << "(q % s)(x) = " << residual << endl << endl;
}