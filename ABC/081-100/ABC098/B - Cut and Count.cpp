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
const int MOD = 1e9 + 7;

template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;

  int ans = 0;
  rep(cut, N - 1) {
    set<char> l;
    repp(i, 0, cut) { l.insert(S[i]); }
    set<char> r;
    repp(i, cut + 1, N - 1) { r.insert(S[i]); }

    int temp = 0;
    for (char ch = 'a'; ch <= 'z'; ch++) {
      if (l.find(ch) != l.end() && r.find(ch) != r.end()) temp++;
    }

    chmax(ans, temp);
  }
  cout << ans << endl;
}