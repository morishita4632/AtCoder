#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

template <typename T>
struct SegmentTree {
  using F = function<T(T, T)>;
  int n;
  F f;
  T ti;
  vector<T> dat;
  SegmentTree(){};
  SegmentTree(F f, T ti) : f(f), ti(ti) {}

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

  void set_val(int k, T x) {
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

/*
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
*/
int main() {
  int n, q;
  cin >> n >> q;
  vector<int> com(q), x(q), y(q);
  rep(i, q) cin >> com[i] >> x[i] >> y[i];

  auto f = [](int a, int b) { return a + b; };
  SegmentTree<int> seg(f, 0);

  seg.init(n);

  rep(i, q) {
    if (com[i]) {
      x[i]--;
      y[i]--;
      cout << seg.query(x[i], y[i] + 1) << endl;
    } else {
      x[i]--;
      int now = seg.query(x[i], x[i] + 1);
      seg.set_val(x[i], now + y[i]);
    }
  }
}