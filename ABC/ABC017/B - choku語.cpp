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
  string X;
  cin >> X;
  reverse(all(X));

  int i = 0;
  rep(iter, 55) {
    if (X[i] == 'o')
      i++;
    if (X[i] == 'k')
      i++;
    if (X[i] == 'u')
      i++;
    if (i < sz(X) - 1 && X[i] == 'h' && X[i + 1] == 'c')
      i += 2;
  }

  if (i == sz(X))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}