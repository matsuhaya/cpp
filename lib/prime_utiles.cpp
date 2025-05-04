#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long N) {
  if (N < 2) return false;
  for (long long i = 2; i * i <= N; ++i) {
    if (N % i == 0) return false;
  }
  return true;
}