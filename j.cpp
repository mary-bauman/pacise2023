#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int* dp = new int[n+1];
  dp[0] = 1;

  for (int i = 0; i < n; i++) {
    if (i + 1 <= n) dp[i+1] += dp[i];
    if (i + 2 <= n) dp[i+2] += dp[i];
  }

  cout << dp[n] << nl;
}
