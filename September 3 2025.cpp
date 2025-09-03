class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size(), c = 0;
        sort(points.begin(), points.end(), [](auto &a, auto &b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        for (int i = 0; i < n; i++) {
            int maxY = INT_MIN;
            for (int j = i + 1; j < n; j++) {
                if (points[j][1] <= points[i][1] && maxY < points[j][1]) {
                    c++;
                    maxY = points[j][1];
                }
            }
        }
        return c;
    }
};
