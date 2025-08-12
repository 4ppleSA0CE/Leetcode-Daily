typedef long long ll;
class Solution {
public:
    const ll mod = 1e9+7;
    int numberOfWays(int n, int x) {
        vector<ll> dp(n+1, 0); dp[0] = 1;
        for (int i = 1; i<=n; i++){
            ll prod = pow(i, x);
            if (prod>n)break;
            for (int j = n; j>=prod; j--) dp[j] = (dp[j] + dp[j-prod])%mod;
        }
        return dp[n]%mod;
    }
};
