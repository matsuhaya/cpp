// https://atcoder.jp/contests/typical90/tasks/typical90_bq
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
int binpower(int a, long long b) {
  int ans = 1;
  while (b != 0) {
    if (b % 2 == 1) {
      ans = (long long)(ans)*a % MOD;
    }
    a = (long long)(a)*a % MOD;
    b /= 2;
  }
  return ans;
}

int main() {
  int N, K;
  cin >> N >> K;
  cout << binpower(N, K) << endl;
}
