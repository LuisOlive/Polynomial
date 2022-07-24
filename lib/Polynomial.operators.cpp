#include "Polynomial.h"

Polynomial Polynomial::operator=(const Polynomial &p)
{
  coeffs = p.coeffs;
  return *this;
}

Polynomial Polynomial::operator+(const Polynomial &p) const
{
  Polynomial ans;

  for (int i = 0; i < size() || i < p.size(); i++)
    ans[i] = coeffs[i] + p[i];

  return ans;
}

Polynomial Polynomial::operator-(const Polynomial &p) const
{
  Polynomial ans;

  for (int i = 0; i < size() || i < p.size(); i++)
    ans[i] = coeffs[i] - p[i];

  return ans;
}

Polynomial Polynomial::operator*(const Polynomial &p) const
{
  Polynomial ans;

  for (int i = 0; i < size(); i++)
    for (int j = 0; j < p.size(); j++)
      ans[i + j] += coeffs[i] * p[j];

  return ans;
}

Polynomial Polynomial::operator/(const Polynomial &p) const
{
  Polynomial ans;
  
  for(int i=0; i<=grade(); i++)
    ans[i] = coeffs[i];
  
  return ans;
}

Polynomial Polynomial::operator ^ (int n) const { // 3
  Polynomial ans = 1;

  while (n--) // 3; 2; 1;
    ans *= *this;
  
  return ans;
}

Polynomial Polynomial::operator<<(const int n) const
{
  return *this * (Polynomial::x ^ n);
}

double Polynomial::operator()(const double x) const
{
  double ans = 0;
  
  for(int i=0; i<size(); i++) 
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
  if(i < 0 && -i <= grade() + 1)
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
  
  if(!hasPrinted)
    cout << 0;
  
  return cout;
}