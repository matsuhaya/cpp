// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_cg
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  int L = 1500;
  vector A(L, vector<int>(L));

  rep(i, N) {
    int X, Y;
    cin >> X >> Y;
    X--;
    Y--;
    A[X][Y]++;
  }

  vector S(L + 1, vector<int>(L + 1));
  rep(i, L) rep(j, L) S[i + 1][j + 1] = S[i + 1][j] + A[i][j];
  rep(i, L) rep(j, L + 1) S[i + 1][j] += S[i][j];

  int Q;
  cin >> Q;
  rep(i, Q) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--;
    b--;
    cout << S[c][d] - S[a][d] - S[c][b] + S[a][b] << endl;
  }

  return 0;
}
