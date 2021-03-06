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
  ll N, M;
  cin >> N >> M;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];

  vector<ll> sum(N);
  sum[0] = A[0] % M;
  repp(i, 1, N - 1) {
    sum[i] = sum[i - 1] + A[i];
    sum[i] %= M;
  }

  map<ll, int> m;
  vector<ll> dupl;
  rep(i, N) {
    if (m[sum[i]] == 1)
      dupl.pb(sum[i]);
    m[sum[i]]++;
  }

  ll ans = 0;
  ans += m[0];
  rep(i, dupl.size()) {
    ll d = m[dupl[i]];
    ans += d * (d - 1) / 2;
  }
  cout << ans << endl;
}
