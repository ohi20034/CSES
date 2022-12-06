#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;
const int MAX = 1e6+6;
int dp[MAX];
int ans(vector<int>&ar,int n)
{
    if(n==0) return dp[n]=1;
    if(n < 0) return 0;
    if(dp[n]!=-1){
        return dp[n];
    }
    int a=0;
    for(int i=0; i<(ar.size()<=6?ar.size():6); ++i)
    {
        a += ans(ar,n-ar[i]);
        if(a >= MOD) a%=MOD;
    }
    return dp[n]=a;
}
int32_t main()
{
    memset(dp,-1,sizeof dp);
    int n;
    cin >> n;
    vector <int> v(n);
    for(int i=0; i<n; ++i)
    {
        v[i] = 1+i;
    }
    cout << ans(v,n) <<"\n";
}
