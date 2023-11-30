
#include "s21_math.h"

long double s21_cos(double x) {
  long double result = 1.0;
  long double num = 1.0;
  double factorial = 0.0;

  if (x == S21_ZERO_POS || x == S21_ZERO_NEG) {
    result = 1;
  } else if (S21_IS_POS_INF(x) || S21_IS_NEG_INF(x)) {
    result = S21_NaN;
  } else {
    x = s21_fmod(x, 2.0 * S21_PI);
    while (x > S21_PI) {
      x -= 2 * S21_PI;
    }
    while (x < -S21_PI) {
      x += 2 * S21_PI;
    }
  }
  while (s21_fabs(num / result) > S21_EPS) {
    factorial = factorial + 2.0;
    num = (-num * x * x) / ((factorial - 1) * (factorial));
    result += num;
  }
  return result;
}
