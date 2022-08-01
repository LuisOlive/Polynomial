#include "Polynomial.h"

Polynomial Polynomial::operator=(const Polynomial &p)
{
  coeffs = p.coeffs;
  return *this;
}

Polynomial Polynomial::operator+(const Polynomial &p) const
{
  Polynomial ans;

  for (int i = 0; i <= grade() || i <= p.grade(); i++)
    ans[i] = (*this)[i] + p[i];

  return ans;
}

Polynomial Polynomial::operator-(const Polynomial &p) const
{
  Polynomial ans;

  for (int i = 0; i <= grade() || i <= p.grade(); i++)
    ans[i] = (*this)[i] - p[i];

  return ans;
}

Polynomial Polynomial::operator*(const Polynomial &p) const
{
  Polynomial ans;

  for (int i = 0; i <= grade(); i++)
    for (int j = 0; j <= p.grade(); j++)
      ans[i + j] += coeffs[i] * p[j];

  return ans;
}

Polynomial Polynomial::operator/(const Polynomial &p) const
{
  Polynomial ans, _;
  writeDivision(p, ans, _);
  return ans;
}

Polynomial Polynomial::operator%(const Polynomial &p) const
{
  Polynomial ans, _;
  writeDivision(p, _, ans);
  return ans;
}

Polynomial Polynomial::operator^(int n) const
{
  Polynomial ans = 1;

  while (n-- > 0)
    ans *= *this;
  
  return ans;
}

Polynomial Polynomial::operator<<(const int n) const
{
  Polynomial ans;

  for (int i = grade(); i + n >= 0 && i >= 0; i--)
    ans[i + n] = coeffs[i];

  return ans;
}

Polynomial Polynomial::operator>>(const int n) const
{
  return *this << -n;
}

double Polynomial::operator()(const double x) const
{
  double ans = 0;

  for (int i = 0; i < size(); i++)
    ans += coeffs[i] * pow(x, i);

  return ans;
}

double &Polynomial::operator[](const int i)
{
  if (i < 0 && -i <= grade() + 1)
    return coeffs[grade() + 1 + i];

  while (i >= size())
    coeffs.push_back(0);

  return coeffs[i];
}

double Polynomial::operator[](const int i) const
{
  if (i < 0 && -i <= grade() + 1)
    return coeffs[grade() + 1 + i];

  if (i >= size() || i < 0)
    return 0;

  return coeffs[i];
}

std::ostream &operator<<(std::ostream &cout, const Polynomial &p)
{
  bool hasPrinted = false;

  for (int i = p.grade(); i >= 0; i--)
  {
    if (p[i])
    {
      cout << p[i];

      if (i)
        cout << "x";

      if (i > 1)
        cout << "^" << i;

      hasPrinted = true;
    }

    if (i >= 1 && p[i - 1])
      cout << " + ";
  }

  if (!hasPrinted)
    cout << 0;

  return cout;
}