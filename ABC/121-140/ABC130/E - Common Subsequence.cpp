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
  int N, M;
  cin >> N >> M;
  vector<int> S(N);
  rep(i, N) cin >> S[i];
  vector<int> T(M);
  rep(i, M) cin >> T[i];

  vector<vector<ll>> dp(N + 1, vector<ll>(M + 1, 0));
  dp[0][0] = 1;
  rep(i, N + 1) {
    rep(j, M + 1) {
      if (i >= 1 && j >= 1 && S[i - 1] == T[j - 1]) {
        dp[i][j] += dp[i - 1][j - 1];
        dp[i][j] %= MOD;
      }
      if (i >= 1) {
        dp[i][j] += dp[i - 1][j];
        dp[i][j] %= MOD;
      }
      if (j >= 1) {
        dp[i][j] += dp[i][j - 1];
        dp[i][j] %= MOD;
      }
      if (i >= 1 && j >= 1) {
        dp[i][j] -= dp[i - 1][j - 1];
        dp[i][j] %= MOD;
        if (dp[i][j] < 0) dp[i][j] += MOD;
      }
    }
  }
  cout << dp[N][M] << endl;
}