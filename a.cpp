#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

int sumOfDuplicateElements(int arr[], int len) {
  int p = 0;
  int total = 0;

  for (int i = 0; i < len; i++) {
    if (arr[i] == p) total += 2 * p;
    p = arr[i];
  }

  return total;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int arr1[] {1, 2, 2, 3, 4, 4, 5};
  cout << "Output: " << sumOfDuplicateElements(arr1, 7) << nl;

  int arr2[] {10, 20, 20, 30, 30, 40, 50, 50};
  cout << "Output: " << sumOfDuplicateElements(arr2, 8) << nl;
}
