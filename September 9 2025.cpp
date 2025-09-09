typedef long long ll;
class Solution {
    const int MOD = 1e9+7;
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<ll> dp(n, 0);
        dp[0] = 1;
        ll share = 0;
        for (int i = 1; i<n; i++){
            if (i-delay>=0)share = (share + dp[i-delay])%MOD;
            if (i-forget >=0)share = (share - dp[i-forget] + MOD)%MOD;
            dp[i] = share;
        }
        ll ans = 0;
        for (int i = n-forget; i<n; i++)if (i>=0)ans = (ans + dp[i])%MOD;
        return (int)ans;
    }
};
