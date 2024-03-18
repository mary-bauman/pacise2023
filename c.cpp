#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int x1, y1, z1, r1, x2, y2, z2, r2;
  cin >> x1 >> y1 >> z1 >> r1 >> x2 >> y2 >> z2 >> r2;

  int dist = pow(x2-x1, 2) + pow(y2-y1, 2) + pow(z2-z1, 2);
  dist = pow(dist, 0.5);

  cout << (dist <= r1 + r2) << nl;
}
