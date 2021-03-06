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
  int N, M;
  cin >> N >> M;
  vector<int> l(N), r(N), s(N);
  ll sum = 0;
  vector<int> d(M + 1);
  rep(i, N) {
    cin >> l[i] >> r[i] >> s[i];
    l[i]--, r[i];
    sum += s[i];

    d[l[i]] -= s[i];
    d[r[i]] += s[i];
  }

  ll ans = 0;
  rep(i, M) {
    sum += d[i];
    chmax(ans, sum);
  }
  cout << ans << endl;
}