#pragma region head
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
#define test(s) \
  if (!(s))     \
    cout << "Line " << __LINE__ << ": [" << #s << "] is false" << endl;
#define int long long
typedef long long ll;
#define double long double
typedef double ld;
const int INF = 1001001001001001001ll;
const ll LINF = 1001001001001001001ll;
const int MOD = 1000000007;
const double EPS = 1e-9;
const double PI = acos(-1.0);

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
#pragma endregion


#pragma region LazySegmentTree
template <typename T, typename E>
struct LazySegmentTree {
  using F = function<T(T, T)>;
  using G = function<T(T, E)>;
  using H = function<E(E, E)>;
  int n, height;
  F f;
  G g;
  H h;
  T ti;
  E ei;
  vector<T> dat;
  vector<E> laz;
  LazySegmentTree(F f, G g, H h, T ti, E ei)
      : f(f), g(g), h(h), ti(ti), ei(ei) {
  }

  void init(int n_) {
    n = 1;
    height = 0;
    while (n < n_)
      n <<= 1, height++;
    dat.assign(2 * n, ti);
    laz.assign(2 * n, ei);
  }
  void build(const vector<T>& v) {
    int n_ = v.size();
    init(n_);
    for (int i = 0; i < n_; i++)
      dat[n + i] = v[i];
    for (int i = n - 1; i; i--)
      dat[i] = f(dat[(i << 1) | 0], dat[(i << 1) | 1]);
  }
  inline T reflect(int k) {
    return laz[k] == ei ? dat[k] : g(dat[k], laz[k]);
  }
  inline void eval(int k) {
    if (laz[k] == ei)
      return;
    laz[(k << 1) | 0] = h(laz[(k << 1) | 0], laz[k]);
    laz[(k << 1) | 1] = h(laz[(k << 1) | 1], laz[k]);
    dat[k] = reflect(k);
    laz[k] = ei;
  }
  inline void thrust(int k) {
    for (int i = height; i; i--)
      eval(k >> i);
  }
  inline void recalc(int k) {
    while (k >>= 1)
      dat[k] = f(reflect((k << 1) | 0), reflect((k << 1) | 1));
  }
  void update(int a, int b, E x) {
    thrust(a += n);
    thrust(b += n - 1);
    for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1)
        laz[l] = h(laz[l], x), l++;
      if (r & 1)
        --r, laz[r] = h(laz[r], x);
    }
    recalc(a);
    recalc(b);
  }
  void set_val(int a, T x) {
    thrust(a += n);
    dat[a] = x;
    laz[a] = ei;
    recalc(a);
  }
  T query(int a, int b) {
    thrust(a += n);
    thrust(b += n - 1);
    T vl = ti, vr = ti;
    for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1)
        vl = f(vl, reflect(l++));
      if (r & 1)
        vr = f(reflect(--r), vr);
    }
    return f(vl, vr);
  }

  template <typename C>
  int find(int st, C& check, T& acc, int k, int l, int r) {
    if (l + 1 == r) {
      acc = f(acc, reflect(k));
      return check(acc) ? k - n : -1;
    }
    eval(k);
    int m = (l + r) >> 1;
    if (m <= st)
      return find(st, check, acc, (k << 1) | 1, m, r);
    if (st <= l && !check(f(acc, dat[k]))) {
      acc = f(acc, dat[k]);
      return -1;
    }
    int vl = find(st, check, acc, (k << 1) | 0, l, m);
    if (~vl)
      return vl;
    return find(st, check, acc, (k << 1) | 1, m, r);
  }
  template <typename C>
  int find(int st, C& check) {
    T acc = ti;
    return find(st, check, acc, 1, 0, n);
  }
};
#pragma endregion LazySegmentTree


signed main() {
  int N, M;
  cin >> N >> M;

  vector<int> A(N);
  vector<int> cnt(N + 1);
  rep(i, N) {
    cin >> A[i];
    A[i]--;
    cnt[A[i]]++;
  }


  using P = pair<int, int>;
  // first:sum, second:# of including elem
  auto f = [](P t1, P t2) { return P(t1.fi + t2.fi, t1.se + t2.se); };
  auto ti = P(0, 0);
  auto g = [](P t, int e) { return P(t.fi + t.se * e, t.se); };
  auto h = [](int e1, int e2) { return e1 + e2; };
  int ei = 0;

  LazySegmentTree<P, int> lz(f, g, h, ti, ei);
  lz.build(vector<P>(N, P(0, 1)));

  rep(i, N) {
    int r = i + 1;
    int l = max(r - cnt[i], 0ll);
    lz.update(l, r, 1);
  }

  int ans = 0;
  rep(i, N) {
    ans += (lz.query(i, i + 1).fi == 0);
  }


  vector<int> X(M), Y(M);
  rep(i, M) {
    cin >> X[i] >> Y[i];
    Y[i]--;
    X[i]--;

    int x = A[X[i]];
    int l = x + 1 - cnt[x];
    if (l >= 0) {
      lz.update(l, l + 1, -1);
      if (lz.query(l, l + 1).fi == 0)
        ans++;
    }
    cnt[x]--;

    int y = Y[i];
    l = y + 1 - cnt[y] - 1;
    if (l >= 0) {
      lz.update(l, l + 1, 1);
      if (lz.query(l, l + 1).fi == 1)
        ans--;
    }
    cnt[y]++;

    A[X[i]] = y;
    cout << ans << endl;
  }
}