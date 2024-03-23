// https://atcoder.jp/contests/typical90/tasks/typical90_a
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N, L;
  cin >> N >> L;
  int K;
  cin >> K;
  vector<int> A(N);
  rep(i, N) cin >> A[i];

  auto solve = [&](int m) -> bool {
    int cnt = 0, p = 0;
    for (auto&& na : A) {
      if (na - p >= m) {
        p = na;
        cnt++;
      }
      if (cnt >= K) {
        if (L - p >= m) return true;
      }
    }
    return false;
  };

  auto binary_search = [&]() -> int {
    int ok = -1;  // 解が存在する値
    int ng = L;   // 解が存在しない値

    while (abs(ok - ng) > 1) {
      int mid = (ok + ng) / 2;
      if (solve(mid))
        ok = mid;
      else
        ng = mid;
    }
    return ok;
  };

  cout << binary_search() << endl;
  return 0;
}
