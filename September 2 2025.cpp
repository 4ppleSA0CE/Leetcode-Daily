class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        int res = 0, n = points.size();
        for (int i = 0; i < n - 1; i++) {
            int xlo = points[i][0] - 1;
            int ylo = INT_MIN;
            int xhi = INT_MAX;
            int yhi = points[i][1] + 1;
            for (int j = i + 1; j < n; j++) {
                if (points[j][0] > xlo && points[j][0] < xhi &&
                    points[j][1] > ylo && points[j][1] < yhi) {
                    res++;
                    xlo = points[j][0];
                    ylo = points[j][1];
                }
            }
        }
        return res;
    }
};
