#include "Polynomial.h"

void Polynomial::writeDivision(const Polynomial &divisor, Polynomial &resultTarget, Polynomial &residualTarget)
{
  /*
    Example:

    P(x) = 10x^5 + 27x^4 + 52x^3 + 61x^2 + 53x + 34
    Q(x) = 2x^2 + 3x + 4

    R(x) = P(x) / Q(x)
    S(x) = P(x) % Q(x)

             5  6  7  8
           -------------------
    2 3 4 | 10 27 52 61 53 34
            10 27 52
             0 12 32 61
                0 14 37 53
                   0 16 25 34
                      0  1  2

    values:  (10, 27, 52, 61, 53, 34) / (2, 3, 4)
    indexes: [ 5,  4,  3,  2,  1,  0]   [2, 1, 0]
     = also: [-1, -2, -3, -4, -5, -6]   [2, 1, 0]
  */
  const int N = grade(), M = divisor.grade(), L = N - M; // N = 5, M = 2, L = 3

  // cleaning previous values
  resultTarget = residualTarget = 0;
  
  // std::cout << "divisor: " << divisor << std::endl;
  // std::cout << "result: " << resultTarget << std::endl;
  // std::cout << "residual: " << residualTarget << std::endl;
  // std::cout << "N: " << N << std::endl;
  // std::cout << "M: " << M << std::endl;
  
  // if divisor has a larger grade, can't divide this more
  if(M > N) {
    residualTarget = *this;
    return;
  } 
  
  // copying some numbers to the residual
  for (int i = 0; i <= M; i++) // 0, 1, 2
    residualTarget[M - i] = (*this)[-i -1]; // (10,,), (10,27,), (10,27,52),
    

  for (int i = 1; i <= M + 1; i++) // 1, 2, 3
  {
    resultTarget[L - i + 1] = residualTarget[-i] / divisor[-i]; // (5,,,)
    
    for(int j = 1; j <= M + 1; j++) // 1, 2, 3
    {
      //                        10     -      2      *        5        ; 27 - 3 * 5 ; 52 - 4 * 5
      residualTarget[L - j] = (*this)[-j] - divisor[1 -i -j] * resultTarget[1 -i -i]; // (0,12,32)
      std::cout  << i << ", "<<j<< ", "<< (*this)[-j] << ", " << divisor[-j] << ", " << resultTarget[-i] << std::endl;
    }
    
    residualTarget = (residualTarget << 1) + (*this)[-M -i -1];
    std::cout << residualTarget << std::endl
              << std::endl;
    // break;
  }
}

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
  while (coeffs[i] == 0)
    i--;

  return i;
}

int Polynomial::size() const
{
  return coeffs.size();
}

/*

    # i = 0
    >>> R[3 - i = 3] = P[5 - i = 5] / Q[2 - i = 2] = 10 / 2 = 5
    R = (5, #, #, #)

      # j = 0
      >>> S[2 - j = 2] = P[5 - j = 5] - Q[2 - j = 2] * R[3 - i = 3] = 10 - 2 * 5 = 0
      S = (0, #, #)

      # j = 1
      >>> S[2 - j = 1] = P[5 - j = 4] - Q[2 - j = 1] * R[3 - i = 3] = 27 - 3 * 5 = 12
      S = (0, 12, #)

      # j = 2
      >>> S[2 - j = 0] = P[5 - j = 3] - Q[2 - j = 0] * R[3 - i = 3] = 52 - 4 * 5 = 32
      S = (0, 12, 32)

    >>> S = (12, 32, 0) + (61) = (12, 32, 61)
*/