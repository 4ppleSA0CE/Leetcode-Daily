class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        map<int, vector<int>> mp;
        int n = grid.size();
        for (int i = 0; i<n; i++){
            for (int j = 0; j<n; j++) mp[i-j].emplace_back(grid[i][j]);
        }
        for (auto& [k, v]: mp){
            if (k<0) sort(v.begin(), v.end());
            else sort(v.begin(), v.end(), greater<int>());
        }
        for (auto& [k, v]: mp) reverse(v.begin(), v.end());
        for (int i = 0; i<n; i++){
            for (int j = 0; j<n; j++){
                grid[i][j] = mp[i-j].back();
                mp[i-j].pop_back();
            }
        }
        return grid;
    }
};
