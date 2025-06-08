// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_bm
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
template <typename T>
inline void print(const vector<T>& v, string s = " ") {
  rep(i, v.size()) cout << v[i] << (i != (ll)v.size() - 1 ? s : "\n");
}

int main() {
  int N;
  cin >> N;

  vector G(N, vector<int>());
  rep2(i, 1, N) {
    int A;
    cin >> A;
    A--;
    G[i].push_back(A);
    G[A].push_back(i);
  }

  vector<int> dp(N);
  auto dfs = [&](auto dfs, int v, int pv = -1) -> void {
    for (auto&& nv : G[v]) {
      if (nv == pv) continue;
      dfs(dfs, nv, v);
    }

    dp[v] = 1;  // 自分自身
    for (auto&& nv : G[v]) {
      if (nv == pv) continue;
      dp[v] += dp[nv];
    }
  };

  dfs(dfs, 0);
  rep(i, N) dp[i]--;
  print(dp);
  return 0;
}