#include<bits/stdc++.h>
#include<vector>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;


ll mul(ll a, ll b){
    return ((a % mod) * (b % mod)) % mod;
}

ll add(ll a, ll b){
    ll sum = ((a % mod) + (b % mod)) % mod;
    return sum;
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0), cout.tie(0);
    ll l, r, k;
    cin>>l>>r;
    cin>>k;

    ll dp[k + 1][2];

    memset(dp, 0ll, sizeof dp);

    ll odds = 0, evens = 0;

    ll n = (r - l)/2;
    
    if((r % 2 != 0) or (l%2 != 0))n++;
    odds = n;
    evens = (r - l + 1 - odds);
 
    dp[1][0] = evens;
    dp[1][1] = odds;

    for(int i = 2; i <= k; i++){
        dp[i][0] = add(mul(evens, dp[i - 1][0]), mul(odds, dp[i - 1][1]));
        dp[i][1] = add(mul(odds, dp[i - 1][0]), mul(evens, dp[i - 1][1]));
    }

    cout<<dp[k][0];

    




}