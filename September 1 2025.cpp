class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<vector<double>> pq;
        for (auto &c : classes) {
            double p = c[0], t = c[1], gain = (p + 1) / (t + 1) - p / t;
            pq.push({gain, p, t});
        }
        while (extraStudents--) {
            auto top = pq.top(); pq.pop();
            double p = top[1], t = top[2];
            p++; t++;
            double gain = (p + 1) / (t + 1) - p / t;
            pq.push({gain, p, t});
        }
        double sum = 0.0;
        while (!pq.empty()) {
            auto top = pq.top(); pq.pop();
            sum += top[1] / top[2];
        }
        return sum / classes.size();
    }
};
