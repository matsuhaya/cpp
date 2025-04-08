// https://zenn.dev/reputeless/books/standard-cpp-for-competitive-programming/viewer/dijkstra
// https://atcoder.jp/contests/typical90/tasks/typical90_m
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template <typename T>
inline void print(const vector<T>& v, string s = " ") {
  rep(i, v.size()) cout << v[i] << (i != (ll)v.size() - 1 ? s : "\n");
}

constexpr ll INF = (1LL << 60);

struct Edge {
  int to;
  int cost;
};

using Graph = vector<vector<Edge>>;

// { distance, from }
using Pair = pair<ll, int>;

// distances は頂点数と同じサイズ, 全要素 INF で初期化しておく
void dijkstra(const Graph& graph, vector<ll>& distances, int startIndex) {
  priority_queue<Pair, vector<Pair>, greater<Pair>> que;
  que.emplace((distances[startIndex] = 0), startIndex);

  while (!que.empty()) {
    const ll distance = que.top().first;
    const int from = que.top().second;
    que.pop();

    // 最短距離でなければ処理しない（ゴミである）
    if (distances[from] < distance) {
      continue;
    }

    // 現在の頂点からの各辺について
    for (const auto& edge : graph[from]) {
      // to までの新しい距離
      const ll d = (distances[from] + edge.cost);

      // d が現在の記録より小さければ更新
      if (d < distances[edge.to]) {
        que.emplace((distances[edge.to] = d), edge.to);
      }
    }
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<ll> distance(N, INF);
  vector<ll> distanceN(N, INF);
  Graph G(N);
  rep(i, M) {
    int A, B, C;
    cin >> A >> B >> C;
    A--;
    B--;
    G[A].push_back({B, C});
    G[B].push_back({A, C});
  }

  dijkstra(G, distance, 0);
  dijkstra(G, distanceN, N - 1);
  // print(distance);
  // print(distanceN);

  rep(i, N) cout << distance[i] + distanceN[i] << endl;

  return 0;
}