// https://atcoder.jp/contests/arc031/tasks/arc031_2
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  vector<string> A(10);
  rep(i, 10) cin >> A[i];

  vector<int> dx = {-1, 0, 0, 1};
  vector<int> dy = {0, -1, 1, 0};

  auto dfs = [&](auto dfs, vector<vector<int>>& seen, int x, int y) -> bool {
    seen[x][y] = 1;
    bool isOK = true;
    rep(i, 10) rep(j, 10) {
      if (seen[i][j] == 0 && A[i][j] == 'o') isOK = false;
    }
    if (isOK) return true;

    rep(d, 4) {
      int nx = x + dx[d];
      int ny = y + dy[d];
      if (nx < 0 || 10 <= nx) continue;
      if (ny < 0 || 10 <= ny) continue;
      if (seen[nx][ny] == 1) continue;
      if (A[nx][ny] == 'o') {
        if (dfs(dfs, seen, nx, ny)) return true;
      }
    }
    return false;
  };

  rep(i, 10) rep(j, 10) {
    if (A[i][j] == 'x') {
      A[i][j] = 'o';
      vector seen(10, vector<int>(10));
      if (dfs(dfs, seen, i, j)) {
        cout << "YES" << endl;
        return 0;
      };
      A[i][j] = 'x';
    }
  }
  cout << "NO" << endl;
  return 0;
}
