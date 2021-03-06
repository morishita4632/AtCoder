#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repp(i, a, b) for (int i = a; i <= (b); ++i)
#define repr(i, a, b) for (int i = a; i >= (b); --i)
typedef long long ll;
const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;
const int MOD = 1000000007;

template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  string S;
  cin >> S;

  reverse(all(S));
  vector<string> sub = {"dream", "dreamer", "erase", "eraser"};
  rep(i, 4) {
    reverse(all(sub[i]));
  }

  int i = 0;
  while (i < S.size()) {
    int match = false;
    rep(s, 4) {
      int len = sub[s].size();
      if (S.substr(i, len) == sub[s]) {
        i += len;
        match = true;
      }
    }
    if (!match) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}