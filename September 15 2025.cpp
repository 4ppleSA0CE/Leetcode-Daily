class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_map<char, int> mp;
        for (char c: brokenLetters) mp[c]=1;
        int cnt = 0, flag = 1;
        for (int i = 0; i<text.size(); i++){
            if (mp[text[i]] == 1)flag = 0;
            if (text[i] == ' ' || i == text.size()-1){
                if (flag)cnt++;
                flag = 1;
            }
        }
        return cnt;
    }
};
