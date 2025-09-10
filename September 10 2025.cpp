class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size(); 
        vector<unordered_set<int>> l(m);
        for (int i = 0; i < m; i++) {
            for (int x : languages[i]) l[i].insert(x);
        }
        unordered_set<int> p;
        for (auto& f : friendships) {
            int a = f[0] - 1, b = f[1] - 1;
            bool ok = false;
            for (int x : l[a]) {
                if (l[b].count(x)) { ok = true; break; }
            }
            if (!ok) { p.insert(a); p.insert(b); }
        }
        if (p.empty()) return 0;
        vector<int> cnt(n + 1, 0);
        for (int u : p) {
            for (int x : l[u]) cnt[x]++;
        }
        int mx = 0;
        for (int i = 1; i <= n; i++) mx = max(mx, cnt[i]);
        return (int)p.size() - mx;
    }
};
