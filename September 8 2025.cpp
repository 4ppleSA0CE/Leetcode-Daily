class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int a = 1, b = n-1;
        string temp = to_string(b), temp2 = to_string(a);
        sort(temp.begin(), temp.end()); sort(temp2.begin(), temp2.end());
        //cout << temp << "\n";
        while (temp[0] == '0' || temp2[0] == '0'){
            a++;b--;
            temp = to_string(b); temp2 = to_string(a);
            sort(temp.begin(), temp.end()); sort(temp2.begin(), temp2.end());
        }
        return {a, b};
    }
};
