// https://atcoder.jp/contests/abc209/tasks/abc209_d
#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

vector<int> dist;

void bfs(Graph &G, int s) {
  queue<int> que;
  dist[s] = 0;
  que.push(s);

  while (!que.empty()) {
    int v = que.front();
    que.pop();

    for (auto &&nv : G[v]) {
      if (dist[nv] != -1) continue;
      dist[nv] = dist[v] + 1;
      que.push(nv);
    }
  }
  return;
}

int main() {
  int n, q;
  cin >> n >> q;

  dist.assign(n, -1);
  Graph G(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  bfs(G, 0);

  for (int i = 0; i < q; i++) {
    int c, d;
    cin >> c >> d;
    c--;
    d--;
    if (abs(dist[d] - dist[c]) % 2 == 0) {
      cout << "Town" << endl;
    } else {
      cout << "Road" << endl;
    }
  }

  return 0;
}
