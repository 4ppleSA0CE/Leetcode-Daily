class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), ans = 0;
        for (int i = 0; i<m; i++){
            vector<int> dp(n, 0);
            for (int j = i; j<m; j++){
                int cnt = 0;
                for (int k = 0; k<n; k++){
                    dp[k] += mat[j][k];
                    if (dp[k] == (j-i+1))cnt++;
                    else{
                        ans+= cnt*(cnt+1)/2;
                        cnt = 0;
                    }
                }
                ans+= cnt*(cnt+1)/2;
            }
        }
        return ans;
    }
};
