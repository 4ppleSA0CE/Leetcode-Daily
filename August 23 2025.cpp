class Solution {
public:
    int minimumSum(vector<vector<int>>& arr) {
        int res = INT_MAX;
        for (int rotcnt = 0; rotcnt < 4; rotcnt++) {
            int n = arr.size(), m = arr[0].size();
            for (int i = 1; i < n; i++) {
                vector<vector<int>> slice(arr.begin(), arr.begin() + i);
                int a1 = box(slice);
                for (int j = 1; j < m; j++) {
                    vector<vector<int>> part2(n - i, vector<int>(j));
                    vector<vector<int>> part3(n - i, vector<int>(m - j));
                    for (int r = 0; r < n - i; r++) {
                        copy(arr[i + r].begin(), arr[i + r].begin() + j, part2[r].begin());
                        copy(arr[i + r].begin() + j, arr[i + r].end(), part3[r].begin());
                    }
                    int a2 = box(part2), a3 = box(part3);
                    res = min(res, a1 + a2 + a3);
                }
                for (int i2 = i + 1; i2 < n; i2++) {
                    vector<vector<int>> part2(arr.begin() + i, arr.begin() + i2);
                    vector<vector<int>> part3(arr.begin() + i2, arr.end());
                    int a2 = box(part2), a3 = box(part3);
                    res = min(res, a1 + a2 + a3);
                }
            }
            arr = rot(arr);
        }
        return res;
    }
    int box(vector<vector<int>>& arr) {
        if (arr.empty() || arr[0].empty()) return 0;
        int n = arr.size(), m = arr[0].size(), l = INT_MAX, top = INT_MAX, r = -1, bot = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == 1) {
                    l = min(l, j);
                    top = min(top, i);
                    r = max(r, j);
                    bot = max(bot, i);
                }
            }
        }
        if (r == -1) return 0;
        return (r - l + 1) * (bot - top + 1);
    }
    vector<vector<int>> rot(vector<vector<int>>& arr) {
        int n = arr.size(), m = arr[0].size();
        vector<vector<int>> rotated(m, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                rotated[j][n - 1 - i] = arr[i][j];
            }
        }
        return rotated;
    }
};
