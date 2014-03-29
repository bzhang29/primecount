///
/// @file  pi_lehmer.cpp
///
/// Copyright (C) 2013 Kim Walisch, <kim.walisch@gmail.com>
///
/// This file is distributed under the BSD License. See the COPYING
/// file in the top level directory.
///

#include "pmath.hpp"
#include "Pk.hpp"

#include <primecount.hpp>
#include <stdint.h>

namespace primecount {

/// Calculate the number of primes below x using Lehmer's formula.
/// Run time: O(x/(log x)^4) operations, O(x^0.5) space.
///
int64_t pi_lehmer(int64_t x, int threads)
{
  if (x < 2)
    return 0;

  int64_t a = pi_meissel(iroot<4>(x), /* threads = */ 1);
  int64_t sum = 0;

  sum += phi(x, a, threads) + a - 1;
  sum -= P2 (x, a, threads);
  sum -= P3 (x, a, threads);

  return sum;
}

} // namespace primecount