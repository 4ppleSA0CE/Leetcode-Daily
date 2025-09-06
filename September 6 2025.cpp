class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans=0;
        for(auto q: queries){
            long long i=log(q[0])/log(4) + 1, j=pow(4,i), op=(q[1]-q[0] +1)*i;
            while(q[1]>=j){
                op+=q[1]-j+1;
                j*=4;
            }
            ans+=(op+1)/2;
        }
        return ans;
    }
};
