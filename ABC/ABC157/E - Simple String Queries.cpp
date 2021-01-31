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
#define int long long
typedef long long ll;
const int INF = 1001001001001001001ll;
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


template <typename T>
struct cvector {
  vector<T> vec;
  cvector() : vec(26) {
  }
  cvector(T init) : vec(26, init) {
  }
  T& operator[](char c) {
    return vec[c - 'a'];
  }
};

template <typename T>
ostream& operator<<(ostream& s, const cvector<T>& cvector) {
  s << cvector.vec;
  return s;
}

template <typename T>
struct SegmentTree {
  using F = function<T(T, T)>;
  int n;
  F f;
  T ti;
  vector<T> dat;
  SegmentTree(){};
  SegmentTree(F f, T ti) : f(f), ti(ti) {
  }

  void init(int n_) {
    n = 1;
    while (n < n_)
      n <<= 1;
    dat.assign(n << 1, ti);
  }

  void build(const vector<T>& v) {
    int n_ = v.size();
    init(n_);
    for (int i = 0; i < n_; i++)
      dat[n + i] = v[i];
    for (int i = n - 1; i; i--)
      dat[i] = f(dat[(i << 1) | 0], dat[(i << 1) | 1]);
  }

  void update(int k, T x) {
    dat[k += n] = x;
    while (k >>= 1)
      dat[k] = f(dat[(k << 1) | 0], dat[(k << 1) | 1]);
  }

  // [a, b)
  T query(int a, int b) {
    T vl = ti, vr = ti;
    for (int l = a + n, r = b + n; l < r; l >>= 1, r >>= 1) {
      if (l & 1)
        vl = f(vl, dat[l++]);
      if (r & 1)
        vr = f(dat[--r], vr);
    }
    return f(vl, vr);
  }
};

signed main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  int Q;
  cin >> Q;
  auto f = [](int a, int b) { return a + b; };
  cvector<SegmentTree<int>> table(SegmentTree<int>(f, 0));

  repp(c, 'a', 'z') {
    table[c].init(N);
  }

  rep(i, N) {
    table[S[i]].update(i, 1);
  }

  rep(q, Q) {
    int query;
    cin >> query;

    if (query == 1) {
      int i;
      char c;
      cin >> i >> c;

      i--;

      char old = S[i];
      table[old].update(i, 0);
      table[c].update(i, 1);
      S[i] = c;
    } else {
      int l, r;
      cin >> l >> r;
      l--;

      int ans = 0;
      repp(c, 'a', 'z') {
        if (table[c].query(l, r) > 0)
          ans++;
      }
      cout << ans << endl;
    }
  }
}