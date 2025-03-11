// https://atcoder.jp/contests/abc145/tasks/abc145_d
// 参考: https://drken1215.hatenablog.com/entry/2018/06/08/210000
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX = 5100000;
ll fac[MAX], finv[MAX], inv[MAX];
ll const MOD = 1000000007;

// テーブルを作る前処理
void COMinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

// 二項係数計算
ll COM(ll n, ll k) {
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
  ll X, Y;
  cin >> X >> Y;

  COMinit();

  ll total = X + Y;
  ll step = total / 3;
  ll ans = 0;
  ll diff = X - Y;
  if (total % 3 == 0 && abs(diff) <= step) {
    ans = COM(step, X - step);
  }
  cout << ans << endl;
  return 0;
}
