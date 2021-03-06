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
#define sz(x) ((int)(x).size())
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
  int N, A, B;
  cin >> N >> A >> B;
  vector<string> s(N);
  vector<int> d(N);
  rep(i, N) cin >> s[i] >> d[i];

  int pos = 0;
  rep(i, N) {
    int temp = d[i];
    chmin(temp, B);
    chmax(temp, A);
    if (s[i][0] == 'E')
      pos += temp;
    else
      pos -= temp;
  }

  if (pos > 0)
    cout << "East" << ' ';
  else if (pos < 0)
    cout << "West" << ' ';
  cout << abs(pos) << endl;
}