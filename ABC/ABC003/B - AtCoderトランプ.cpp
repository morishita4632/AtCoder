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
  string S;
  cin >> S;
  string T;
  cin >> T;

  int N = sz(S);
  set<char> atcoder = {'a', 't', 'c', 'o', 'd', 'e', 'r', '@'};

  rep(i, N) {
    if (S[i] == T[i])
      continue;
    if (S[i] == '@') {
      if (atcoder.find(T[i]) != atcoder.end())
        continue;
    }

    if (T[i] == '@') {
      if (atcoder.find(S[i]) != atcoder.end())
        continue;
    }
    cout << "You will lose" << endl;
    return 0;
  }
  cout << "You can win" << endl;
}