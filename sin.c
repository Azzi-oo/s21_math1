#include "s21_math.h"

long double s21_sin(double x) {
  long double result = x;
  long int factorial = 1;
  if (x == S21_ZERO_POS) {
    result = S21_ZERO_POS;
  } else if (x == S21_ZERO_NEG) {
    result = S21_ZERO_NEG;
  }
  if (S21_IS_POS_INF(x) || S21_IS_NEG_INF(x) || S21_IS_NAN(x)) {
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
  long double temp = x;
  for (int i = 0; i < 500; i++) {
    temp = (-temp * x * x) / ((2 * factorial + 1) * (2 * factorial));
    result += temp;
    factorial++;
  }
  return result;
}
