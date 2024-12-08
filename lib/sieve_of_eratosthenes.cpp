#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template <typename T>
inline void print(const vector<T> &v, string s = " ") {
  rep(i, v.size()) cout << v[i] << (i != (ll)v.size() - 1 ? s : "\n");
}

struct Sieve {
  int n;
  vector<int> f, primes;
  Sieve(int n = 1) : n(n), f(n + 1) {
    f[0] = f[1] = -1;
    for (ll i = 2; i <= n; ++i) {
      if (f[i]) continue;
      primes.push_back(i);
      f[i] = i;
      for (ll j = i * i; j <= n; j += i) {
        if (!f[j]) f[j] = i;
      }
    }
  }
  bool isPrime(int x) { return f[x] == x; }
  vector<int> factorList(int x) {
    vector<int> res;
    while (x != 1) {
      res.push_back(f[x]);
      x /= f[x];
    }
    return res;
  }
  vector<pair<ll, int>> factor(ll x) {
    vector<pair<ll, int>> res;
    for (int p : primes) {
      int y = 0;
      while (x % p == 0) x /= p, ++y;
      if (y != 0) res.emplace_back(p, y);
    }
    if (x != 1) res.emplace_back(x, 1);
    return res;
  }
};

int main() {
  ll n;
  cin >> n;
  Sieve sieve(n);
  auto primes = sieve.primes;
  print(primes);

  return 0;
}