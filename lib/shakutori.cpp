// https://atcoder.jp/contests/abc032/tasks/abc032_c
// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll N, K;
  cin >> N >> K;
  vector<ll> S(N);
  rep(i, N) cin >> S[i];

  ll res = 0;
  ll right = 0;
  ll mul = 1;
  rep(left, N) {
    while (right < N && mul * S[right] <= K) {
      mul *= S[right];
      right++;
    }

    if (mul == 0) break;
    /* break した状態で right は条件を満たす最大なので、何かする */
    res = max(res, right - left);

    /* left をインクリメントする準備 */
    if (right == left) {
      right++;
    } else {
      mul /= S[left];
    }
  }

  cout << ((mul == 0) ? N : res) << endl;
  return 0;
}
