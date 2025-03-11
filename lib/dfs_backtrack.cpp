// https://atcoder.jp/contests/abc396/tasks/abc396_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll N, M;
  cin >> N >> M;
  vector G(N, vector<ll>()), W(N, vector<ll>(N));
  rep(i, M) {
    ll u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    G[u].push_back(v);
    G[v].push_back(u);
    W[u][v] = w;
    W[v][u] = w;
  }

  ll ans = 1LL << 61;
  auto dfs = [&](auto dfs, ll v, ll cost, vector<ll> seen) -> void {
    seen[v] = 1;
    if (v == N - 1) {
      ans = min(ans, cost);
      return;
    }

    for (auto&& nv : G[v]) {
      if (seen[nv] != 1) {
        cost ^= W[v][nv];
        dfs(dfs, nv, cost, seen);  // seenは値渡しなのでbacktrack不要
        cost ^= W[v][nv];          // backtrackする
      }
    }
    return;
  };

  vector<ll> seen(N);
  dfs(dfs, 0, 0, seen);
  cout << ans << endl;

  return 0;
}