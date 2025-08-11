class Solution {
public:
    const long long MOD = 1e9 + 7;
    vector<long long> arr;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        arr.clear();
        for (int bit = 0; bit < 64; bit++) {
            if (n & (1LL << bit)) {
                arr.push_back(1LL << bit);
            }
        }
        vector<int> ans;
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            long long prod = 1;
            for (int i = l; i <= r; i++) {
                prod = (prod * arr[i]) % MOD;
            }
            ans.push_back((int)prod);
        }
        return ans;
    }
};
