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
#define len(x) ((ll)(x).size())
typedef long long ll;
const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;
const int MOD = 1000000007;
const double EPS = 1e-9;

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

__attribute__((constructor)) void initial() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
}


signed main() {
  ll N;
  cin >> N;
  typedef pair<ll, ll> P;
  vector<P> XL(N);
  rep(i, N) {
    cin >> XL[i].fi >> XL[i].se;
    XL[i].fi += XL[i].se;
  }
  sort(all(XL));

  ll L = -LINF;
  int ans = 0;
  rep(i, N) {
    if (XL[i].fi - 2 * XL[i].se >= L) {
      ans++;
      L = XL[i].fi;
    }
  }
  cout << ans << "\n";
}