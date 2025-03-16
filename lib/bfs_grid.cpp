// https://atcoder.jp/contests/abc088/tasks/abc088_d
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> di = {-1, 0, 0, 1}, dj = {0, -1, 1, 0};

using Grid = vector<string>;
vector<vector<int>> dist;
int H, W;

void bfs(Grid& G, int r, int c) {
  queue<pair<int, int>> que;
  dist[r][c] = 0;
  que.push({r, c});

  while (!que.empty()) {
    auto [r, c] = que.front();
    que.pop();
    rep(d, 4) {
      int nr = r + di[d], nc = c + dj[d];
      if (nr < 0 || H <= nr || nc < 0 || W <= nc) continue;
      if (G[nr][nc] == '#') continue;
      if (dist[nr][nc] >= 0) continue;
      que.push({nr, nc});
      dist[nr][nc] = dist[r][c] + 1;
    }
  }
  return;
}

int main() {
  cin >> H >> W;

  Grid G = vector<string>(H);
  dist = vector(H, vector<int>(W, -1));
  rep(i, H) cin >> G[i];

  bfs(G, 0, 0);

  if (dist[H - 1][W - 1] == -1) {
    cout << -1 << endl;
    return 0;
  }

  int ans = 0;
  rep(i, H) rep(j, W) {
    if (G[i][j] == '.') ans++;
  }
  cout << ans - (dist[H - 1][W - 1] + 1) << endl;

  return 0;
}
