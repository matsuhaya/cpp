#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

void printV(vector<int> v) {
  for (int i = 0; i < (int)v.size(); i++) {
    if (i > 0) cout << " ";
    cout << v[i];
  }
  cout << endl;
}

void printVLL(vector<ll> v) {
  for (ll i = 0; i < (ll)v.size(); i++) {
    if (i > 0) cout << " ";
    cout << v[i];
  }
  cout << endl;
}

int main() {
  int N;
  cin >> N;

  cout << N << endl;
  return 0;
}
