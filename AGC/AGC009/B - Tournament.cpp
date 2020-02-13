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
#define debug(var) cout << "[" << #var << "]\n" << var << endl
typedef long long ll;
const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;
const int MOD = 1000000007;
const double EPS = 1e-9;

template <typename T>
ostream& operator<<(ostream& s, const vector<T>& v) {
  int len = v.size();
  for (int i = 0; i < len; ++i) {
    s << v[i];
    if (i < len - 1)
      s << ' ';
  }
  return s;
}

template <typename T>
ostream& operator<<(ostream& s, const vector<vector<T>>& vv) {
  int len = vv.size();
  for (int i = 0; i < len; ++i) {
    s << vv[i];
    if (i != len - 1)
      s << '\n';
  }
  return s;
}

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

vector<vector<int>> G;

int solve(int now) {
  if (len(G[now]) == 0)
    return 0;

  vector<int> childs;
  for (auto next : G[now]) {
    childs.pb(solve(next));
  }

  sort(all(childs), greater<int>());
  int mx = 0;
  rep(i, len(childs)) {
    childs[i] += i;
    chmax(mx, childs[i]);
  }

  return mx + 1;
}

signed main() {
  int N;
  cin >> N;
  vector<int> a(N - 1);
  rep(i, N - 1) {
    cin >> a[i];
    a[i]--;
  }


  G = vector<vector<int>>(N);
  rep(i, N - 1) {
    G[a[i]].pb(i + 1);
  }

  cout << solve(0) << endl;
}