#include "Polynomial.h"

Polynomial Polynomial::derivative() const
{
  Polynomial ans;

  for (int i = 1; i < size(); i++)
    ans[i - 1] = coeffs[i] * i;

  return ans;
}

Polynomial Polynomial::integral() const
{
  Polynomial ans;

  for (int i = 0; i < size(); i++)
    ans[i + 1] = coeffs[i] / (i + 1);

  return ans;
}

int Polynomial::grade() const
{
  int i = coeffs.size() - 1;

  // solving a bug, if the last terms are zeros, the polynomial shouldn't count them
  while (coeffs[i] == 0 && i > 0)
    i--;

  return i;
}

int Polynomial::size() const
{
  return coeffs.size();
}