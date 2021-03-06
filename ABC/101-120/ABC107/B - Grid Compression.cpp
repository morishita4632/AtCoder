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
const int MOD = 1e9 + 7;

template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> a(H);
  rep(i, H) { cin >> a[i]; }

  vector<int> H_use;
  rep(i, H) {
    if (a[i].find("#") != a[i].npos) {
      H_use.pb(i);
    }
  }

  vector<int> W_use;
  rep(j, W) {
    bool all_dot = true;
    rep(i, H) {
      if (a[i][j] == '#') all_dot = false;
    }
    if (all_dot == false) {
      W_use.pb(j);
    }
  }

  rep(i, H_use.size()) {
    rep(j, W_use.size()) { cout << a[H_use[i]][W_use[j]]; }
    cout << endl;
  }
}