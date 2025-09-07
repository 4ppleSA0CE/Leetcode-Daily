class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        if (n%2 == 1){ans.emplace_back(0);n--;}
        for (int i = 1; i<=n; i+=2){
            ans.emplace_back(i); ans.emplace_back(-1*i);
        }
        return ans;
    }
};
