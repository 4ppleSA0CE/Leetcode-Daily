class Solution {
public:
    vector<double> arr;
    bool check = false;
    bool judgePoint24(vector<int>& cards) {
        arr.resize(4, 0.0);
        arr[0] = (double)cards[0];
        arr[1] = (double)cards[1];
        arr[2] = (double)cards[2];
        arr[3] = (double)cards[3];
        fun(4);
        return check;
    }
    void fun(int n){
        if (n == 1){
            if (abs(arr[0]-24) <= 0.0000001)check = true;
            return;
        }
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                double a = arr[i], b = arr[j];
                arr[i] = a + b;
                arr[j] = arr[n-1];
                fun(n-1);
                arr[i] = a - b;
                arr[j] = arr[n-1];
                fun(n-1);
                arr[i] = b - a;
                arr[j] = arr[n-1];
                fun(n-1);
                arr[i] = a * b;
                arr[j] = arr[n-1];
                fun(n-1);
                if(b != 0){
                    arr[i] = a / b;
                    arr[j] = arr[n-1];
                    fun(n-1);
                }
                if(a != 0){
                    arr[i] = b / a;
                    arr[j] = arr[n-1];
                    fun(n-1);
                }
                arr[i] = a;
                arr[j] = b;
            }
        }
    }
};
