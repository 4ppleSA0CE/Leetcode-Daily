class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int mxdia = 0, mx = 0;
        for (const auto& i: dimensions){
            int dia = i[0] * i[0] + i[1]*i[1], area = i[0] * i[1];
            if (dia > mxdia){
                mxdia = dia;
                mx = area;
            }else if (dia == mxdia) mx = max(mx, area);
        }
        return mx;
    }
};
