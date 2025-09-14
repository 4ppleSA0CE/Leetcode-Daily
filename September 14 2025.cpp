#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> spellchecker(vector<string>& wl, vector<string>& q) {
        unordered_set<string> ex(wl.begin(), wl.end());
        unordered_map<string, string> ci;
        unordered_map<string, string> vi;
        auto dv = [](string s) {
            for (char& c : s) {
                if (string("aeiou").find(c) != string::npos) c = '*';
            }
            return s;
        };
        for (string w : wl) {
            string lw = w;
            transform(lw.begin(), lw.end(), lw.begin(), ::tolower);

            if (!ci.count(lw)) ci[lw] = w;
            string vw = dv(lw);
            if (!vi.count(vw)) vi[vw] = w;
        }
        vector<string> res;
        for (string w : q) {
            if (ex.count(w)) {
                res.push_back(w);
                continue;
            }
            string lw = w;
            transform(lw.begin(), lw.end(), lw.begin(), ::tolower);
            if (ci.count(lw)) {
                res.push_back(ci[lw]);
                continue;
            }
            string vw = dv(lw);
            if (vi.count(vw)) {
                res.push_back(vi[vw]);
                continue;
            }
            res.push_back("");
        }
        return res;
    }
};
