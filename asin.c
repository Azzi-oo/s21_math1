#include "s21_math.h"

long double s21_asin(double x) {
  long double rez = x, y = x;
  long double i = 1;
  while (s21_fabs(rez) > S21_EPS) {
    if (x < -1 || x > 1) {
      y = S21_NaN;
      break;
    }
    if (x == 1 || x == -1) {
      y = S21_PI / 2 * x;
      break;
    }
    rez *= x * x * (2 * i - 1) * (2 * i - 1) / ((2 * i + 1) * 2 * i);
    i += 1;
    y += rez;
  }
  return y;
}
