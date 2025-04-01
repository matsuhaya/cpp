// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
template <typename T>
inline void print(const vector<T>& v, string s = " ") {
  rep(i, v.size()) cout << v[i] << (i != (ll)v.size() - 1 ? s : "\n");
}
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
ll div_ceil(ll a, ll b) { return (a >= 0 ? (a + b - 1) : a) / b; }
vector<int> di = {-1, 0, 0, 1}, dj = {0, -1, 1, 0};

int main() {
  // code
  return 0;
}
