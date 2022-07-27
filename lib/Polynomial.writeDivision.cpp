#include "Polynomial.h"

void Polynomial::writeDivision(const Polynomial &divisor, Polynomial &resultTarget, Polynomial &residualTarget) const
{
  /*
    Example:

    P(x) = 10x^5 + 27x^4 + 52x^3 + 61x^2 + 53x + 34
    Q(x) = 2x^2 + 3x + 4

    R(x) = P(x) / Q(x)
    S(x) = P(x) % Q(x)

             5  6  7  8                   # N <- grade 3 (+1 = 4)
           -------------------
    2 3 4 | 10 27 52 61 53 34             # L <- grade 2, M <-grade 5 (+1 = 3,6)
            10 27 52                      # inicial residual
             0 12 32 61
                0 14 37 53
                   0 16 25 34
                      0  1  2

    values:  (10, 27, 52, 61, 53, 34) / (2, 3, 4)
    indexes: [ 5,  4,  3,  2,  1,  0]   [2, 1, 0]
     = also: [-1, -2, -3, -4, -5, -6]   [2, 1, 0]
     
    L=6, M=3, N=4
  */
  const int L = grade() + 1,   // L is self grade() + 1
      M = divisor.grade() + 1, // M is divisor grade + 1
      N = L - M + 1;           // N is substract of grades + 1

  // cleaning previous values
  resultTarget = residualTarget = 0;

  // if divisor has a larger grade, can't divide this more
  if (N < 1) // case L=M, L-M = 0, +1 = 1
  {
    residualTarget = *this;
    return;
  }

  // take the same cuantity of terms of divisor and copy them to the inicial residual
  for (int i = 1; i <= M; i++)
    residualTarget[M - i] = coeffs[L - i]; // copy the last terms of this

  // std::cout << "copy: " << residualTarget << std::endl; // return;

  for (int i = 1; i <= N; i++)
  {

    // std::cout << "\ni: " << i << std::endl;
    // // std::cout << "residual: " << residualTarget << std::endl;
    // // std::cout << "residual[-1]: " << residualTarget[-1] << std::endl;
    // // std::cout << "divisor[-1]: " << divisor[-1] << std::endl;
    // std::cout << "residual[-1] / divisor[-1]: " << residualTarget[-1] / divisor[-1] << std::endl;

    // dividing the last term of residual over the last term of divisor and saving it in array
    resultTarget[N - i] = residualTarget[-1] / divisor[-1];
    // std::cout << "result[N - 1]: " << resultTarget[N - i] << std::endl;

    // std::cout << "residual: " << residualTarget << std::endl;
    // std::cout << "divisor * result[N - 1]: " << divisor * resultTarget[N - i] << std::endl;
    // std::cout << "residual - divisor * result[N - 1]: " << residualTarget - divisor * resultTarget[N - i] << std::endl;
    // std::cout << std::endl;

    // multiplying the obtained term by the divisor, residual is the sub of his self minus product
    residualTarget -= divisor * resultTarget[N - i];

    if (i >= N)
      break;
    // std::cout << i << " < " << N << std::endl;

    residualTarget = (residualTarget << 1) + coeffs[N - i - 1];
    // std::cout << "residual: " << residualTarget << std::endl;
    // std::cout << "end for\n\n";
  }
}
