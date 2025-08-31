class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        fun(board);
    }
    bool fun(vector<vector<char>>& board){
        for (int r = 0; r<9; r++){
            for (int c = 0; c<9; c++){
                if (board[r][c] == '.'){
                    for (char i = '1'; i<='9'; i++){
                        if (check(board, r, c, i)){
                            board[r][c] = i;
                            if (fun(board))return true;
                            board[r][c] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool check(vector<vector<char>>& board, int r, int c, char ch){
        for(int i= 0; i<9; i++) if (board[r][i] == ch || board[i][c] == ch)return false;
        int srow = (r/3)*3, scol = (c/3)*3;
        for (int i = srow; i<srow+3; i++){
            for (int j = scol; j<scol+3; j++){
                if (board[i][j] == ch)return false;
            }
        }
        return true;
    }
};
