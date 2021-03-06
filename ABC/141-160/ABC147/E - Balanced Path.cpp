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
  int H, W;
  cin >> H >> W;
  vector<vector<int>> A(H, vector<int>(W));
  rep(i, H) {
    rep(j, W) {
      cin >> A[i][j];
    }
  }
  vector<vector<int>> B(H, vector<int>(W));
  rep(i, H) {
    rep(j, W) {
      cin >> B[i][j];
    }
  }

  vector<vector<int>> diff(H, vector<int>(W));
  rep(i, H) {
    rep(j, W) {
      diff[i][j] = abs(A[i][j] - B[i][j]);
    }
  }

  int dpzero = 80 * 2 * (80 + 80);
  int dpmax = 80 * 4 * (80 + 80);
  vector<vector<vector<bool>>> dp(
      H, vector<vector<bool>>(W, vector<bool>(dpmax, false)));
  dp[0][0][dpzero + diff[0][0]] = true;
  dp[0][0][dpzero - diff[0][0]] = true;

  rep(i, H) {
    rep(j, W) {
      rep(k, dpmax) {
        if (dp[i][j][k] == false)
          continue;

        if (i + 1 < H) {
          dp[i + 1][j][k + diff[i + 1][j]] = true;
          dp[i + 1][j][k - diff[i + 1][j]] = true;
        }


        if (j + 1 < W) {
          dp[i][j + 1][k + diff[i][j + 1]] = true;
          dp[i][j + 1][k - diff[i][j + 1]] = true;
        }
      }
    }
  }

  int ans = INF;
  rep(k, dpmax) {
    if (!dp[H - 1][W - 1][k])
      continue;
    chmin(ans, abs(dpzero - k));
  }
  cout << ans << endl;
}