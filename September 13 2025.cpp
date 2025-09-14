class Solution {
public:
    int maxFreqSum(string s) {
        int mxv= 0, mxc = 0; int arr[26];string ans = "";
        for (char c: s){
            arr[c-'a']++;
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')mxv = max(mxv, arr[c-'a']);
            else mxc = max(mxc, arr[c-'a']);
        } 
        return mxc+mxv;
    }
};
