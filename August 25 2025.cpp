class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> ans; ans.reserve(m*n);
        for (int i = 0; i<m+n-1; i++){
            int r = (i<n ? 0: i-n+1), c = (i<n ? i: n-1);
            vector<int> tmp;
            while (r<m && c>=0){
                tmp.emplace_back(mat[r][c]);
                r++; c--;
            }
            if (i%2 == 0) ans.insert(ans.end(), tmp.rbegin(), tmp.rend());
            else ans.insert(ans.end(), tmp.begin(), tmp.end());
        }
        return ans;
    }
};
