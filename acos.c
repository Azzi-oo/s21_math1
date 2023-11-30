#include "s21_math.h"

long double s21_acos(double x) {
  if (x <= 1 && x >= -1) {
    x = S21_PI / 2. - s21_asin(x);
  } else {
    x = S21_NaN;
  }
  return x;
}
