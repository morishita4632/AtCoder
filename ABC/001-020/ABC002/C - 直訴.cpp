#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repp(i, a, b) for (int i = a; i <= (b); ++i)
#define repr(i, a, b) for (int i = a; i >= (b); --i)
#define bit(n) (1LL << (n))
#define sz(x) ((ll)(x).size())
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
  vector<vector<double>> xy(3, vector<double>(2));
  rep(i, 3) {
    rep(j, 2) {
      cin >> xy[i][j];
    }
  }
  repp(i, 1, 2) {
    rep(j, 2) {
      xy[i][j] -= xy[0][j];
    }
  }


  double ans = abs(xy[1][0] * xy[2][1] - xy[1][1] * xy[2][0]) / 2.0;

  printf("%.14f\n", ans);  // Lf?
}