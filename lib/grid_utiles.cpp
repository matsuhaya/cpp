#include <bits/stdc++.h>
using namespace std;

vector<string> cw_rot90(vector<string> S) {
  int N = (int)S.size();
  vector<string> res(N, string(N, '.'));
  for (int j = 0; j < N; j++) {
    string row = "";
    for (int i = N - 1; i >= 0; i--) {
      row += S[i][j];
    }
    res[j] = row;
  }
  return res;
};