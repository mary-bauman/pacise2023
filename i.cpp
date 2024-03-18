#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  int len_rules, n;
  cin >> s >> len_rules;
  unordered_map<char, string> rules(len_rules);

  char a;
  string b;
  for (int i = 0; i < len_rules; i++) {
    cin >> a >> b;
    rules.insert({a, b});
  }

  string step = "";
  for (cin >> n; n > 0; n--) {
    for (long unsigned int i = 0; i < s.length(); i++) { // long unsigned bc str::length returns size_type
      if (rules.find(s[i]) != rules.end()) step += rules[s[i]];
      else step += s[i];
    }

    s = step;
    step = "";
  }

  cout << s << nl;
}
