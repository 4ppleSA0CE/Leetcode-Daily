class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int top = -1, bot = -1, l = -1, r = -1, m = grid.size(), n = grid[0].size();
        for (int i = 0; i<m; i++){
            for (int j = 0; j<n; j++){
                if (grid[i][j] == 1){
                    if (top == -1)top = i;
                    bot = i;
                    if (l == -1){
                        l = j; r = j;
                    }
                    if (j < l) l = j;
                    if (j > r) r = j;
                }
            }
        }
        return (r-l+1)*(bot-top+1);
    }
};
