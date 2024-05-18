// https://atcoder.jp/contests/typical90/tasks/typical90_bo
// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// N進数を10進数の long long に変換
ll baseN_to_long(int N, string S) {
  ll res = 0;
  for (int i = 0; i < S.size(); ++i) {
    res = res * N + int(S[i] - '0');
  }
  return res;
}

// 10進数をN進数の string に変換
string long_to_baseN(int N, ll x) {
  if (x == 0) {
    return "0";
  }
  string res;
  while (x > 0) {
    res = char(x % N + '0') + res;
    x /= N;
  }
  return res;
}

int main() {
  string N;
  int K;
  cin >> N >> K;

  rep(i, K) {
    ll n = baseN_to_long(8, N);
    string NN = long_to_baseN(9, n);
    rep(j, (int)NN.size()) {
      if (NN[j] == '8') NN[j] = '5';
    }
    N = NN;
  }
  cout << N << endl;
  return 0;
}
