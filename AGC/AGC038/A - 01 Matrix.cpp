#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repp(i, a, b) for (int i = a; i <= (b); ++i)
#define repr(i, a, b) for (int i = a; i >= (b); --i)
#define bit(n) (1LL << (n))
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
  int H, W;
  cin >> H >> W;
  int A, B;
  cin >> A >> B;

  int AA = W - A;
  int BB = H - B;

  rep(i, B) {
    rep(j, A) {
      cout << 1;
    }
    rep(j, AA) {
      cout << 0;
    }
    cout << endl;
  }
  rep(i, BB) {
    rep(j, A) {
      cout << 0;
    }
    rep(j, AA) {
      cout << 1;
    }
    cout << endl;
  }
}