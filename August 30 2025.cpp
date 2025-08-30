class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i<9; i++){
            int cntr = 0;unordered_set<char> s;
            for (int j = 0; j<9; j++){
                if (board[i][j] == '.')continue;
                cntr++;s.insert(board[i][j]);
            }
            if (cntr != s.size())return false;
        }
        cout << 1;
        for (int j = 0; j<9; j++){
            int cntr = 0;unordered_set<char> s;
            for (int i = 0; i<9; i++){
                if (board[i][j] == '.')continue;
                cntr++;s.insert(board[i][j]);
            }
            if (cntr != s.size())return false;
        }
        cout << 2;
        for (int i = 0; i<9; i+=3){
            for (int j = 0; j<9; j+=3){
                int cntr = 0;unordered_set<char> s;
                for (int k = 0; k<3; k++){
                    for (int l = 0; l<3; l++){
                        if (board[i+k][j+l] == '.')continue;
                        cntr++;s.insert(board[i+k][j+l]);
                    }
                }
                if (cntr != s.size())return false;
            }
        }
        return true;
    }
};
