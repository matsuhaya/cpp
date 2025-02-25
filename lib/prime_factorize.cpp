// https://algo-method.com/descriptions/119
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 素因数分解
// 460 = 2^2 x 5 x 23 の場合
// 返り値は {{2, 2}, {5, 1}, {23, 1}}
vector<pair<ll, ll> > prime_factorize(ll N) {
  vector<pair<ll, ll> > res;

  for (ll p = 2; p * p <= N; ++p) {
    if (N % p != 0) {
      continue;
    }

    int e = 0;
    while (N % p == 0) {
      ++e;
      N /= p;
    }

    res.emplace_back(p, e);
  }

  if (N != 1) {
    res.emplace_back(N, 1);
  }
  return res;
}

int main() {
  // 460 を素因数分解する
  int N = 460;
  const auto& pf = prime_factorize(N);

  // 出力
  cout << N << " = ";
  for (auto [p, e] : pf) {
    cout << p << "^" << e << " ";
  }
  cout << endl;
}