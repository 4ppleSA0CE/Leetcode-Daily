class Solution {
public:
    string sortVowels(string s) {
        vector<char> v;
        for (char c: s){ if (check(c))v.emplace_back(c);}
        sort(v.begin(), v.end());
        int i = 0;
        for (char& c: s){ if (check(c))c = v[i++];}
        return s;
    }
    bool check(char c){
        switch (c){
            case 'A': case 'E': case 'I': case 'O': case 'U':
            case 'a': case 'e': case 'i': case 'o': case 'u':
                return true;
            default:
                return false;
        }
    }
};
