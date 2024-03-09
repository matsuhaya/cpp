#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

// first降順, firstが同値の場合second昇順
bool desc_asc(pair<int, int>& left, pair<int, int>& right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

int main() {
  vector<pair<int, int>> vp = {{0, 3}, {0, 2}, {10, 1}, {5, 4}};

  sort(vp.begin(), vp.end(), desc_asc);
  for (auto&& nvp : vp) {
    cout << nvp.second << " ";
  }
  cout << endl;
  return 0;
}
