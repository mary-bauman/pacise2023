#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  double RF = pow(5, 0.5);

  int n, fib;
  cin >> n;

  for (int i = 0; i < n-1; i++) {
    fib = (pow((1+RF)/2, i) - pow((1-RF)/2, i))/RF;
    cout << fib << " ";
  }

  // Need to calculate one more time to get the output right
  fib = (pow((1+RF)/2, n-1) - pow((1-RF)/2, n-1))/RF;
  cout << fib << nl;
}
