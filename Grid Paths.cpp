#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
string grid[1010];
int n, dp[1010][1010];
int findWays(int r, int c)
{
    if (r == n - 1 && c == n - 1)
        return (grid[r][c] == '.');
    if (r >= n || c >= n || grid[r][c] == '*')
        return 0;
    if (dp[r][c] != -1)
        return dp[r][c];
    int res = findWays(r + 1, c) + findWays(r, c + 1);
    if (res >= MOD)
        res %= MOD;
    return dp[r][c] = res;
}
int32_t main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> grid[i];
    }
    memset(dp, -1, sizeof dp);
    cout << findWays(0, 0) << "\n";
}
