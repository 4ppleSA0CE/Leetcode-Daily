class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), ans = 0, l = 0;
        deque<int> dq;
        for (int i = 0; i<n; i++){
            if (nums[i] == 0)dq.push_back(i);
            while (dq.size() > 1){
                l = dq.front() + 1;
                dq.pop_front();
            }
            ans = max(ans, i-l);
        }
        return ans;
    }
};
