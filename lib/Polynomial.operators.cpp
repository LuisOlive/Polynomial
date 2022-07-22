#include "Polynomial.h"

Polynomial Polynomial::operator=(const Polynomial &p)
{
  coeffs = p.coeffs;
}

Polynomial Polynomial::operator+(const Polynomial &p)
{
  Polynomial ans;

  for (int i = 0; i < size() || i < p.size(); i++)
    ans[i] = coeffs[i] + p[i];

  return ans;
}

Polynomial Polynomial::operator-(const Polynomial &p)
{
  Polynomial ans;

  for (int i = 0; i < size() || i < p.size(); i++)
    ans[i] = coeffs[i] - p[i];

  return ans;
}

Polynomial Polynomial::operator*(const Polynomial &p)
{
  Polynomial ans;

  for (int i = 0; i < size(); i++)
    for (int j = 0; j < p.size(); j++)
      ans[i + j] += coeffs[i] * p[j];

  return ans;
}

double &Polynomial::operator[](const int i)
{
  while (i >= size())
    coeffs.push_back(0);

  return coeffs[i];
}

double Polynomial::operator[](const int i) const
{
  if (i >= size())
    return 0;

  return coeffs[i];
}

std::ostream &operator<<(std::ostream &cout, const Polynomial &p)
{
  for (int i = p.grade(); i >= 0; i--)
  {
    if (p[i])
    {
      cout << p[i];

      if (i)
        cout << "x";

      if (i > 1)
        cout << "^" << i;
    }

    if (i >= 1 && p[i - 1])
      cout << " + ";
  }
  return cout;
}

Polynomial Polynomial::operator+=(const Polynomial &p) { (*this) = (*this) + p; }
Polynomial Polynomial::operator-=(const Polynomial &p) { (*this) = (*this) - p; }
Polynomial Polynomial::operator*=(const Polynomial &p) { (*this) = (*this) * p; }