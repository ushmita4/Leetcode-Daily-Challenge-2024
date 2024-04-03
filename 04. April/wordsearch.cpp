class Solution {
private:
    bool check(int i, int j, int k, int& len, int& n, int& m,
               vector<vector<char>>& board, string word) {
        if (k == len)
            return true;
        if (i < 0 || i >= n || j < 0 || j >= m)
            return false;
        
        if (board[i][j] != word[k])
            return false;
        
     
        k++;
        
       
        char letter = board[i][j];
        board[i][j] = '1';
        
        bool flag = check(i + 1, j, k, len, n, m, board, word) ||   
                    check(i - 1, j, k, len, n, m, board, word) ||   
                    check(i, j + 1, k, len, n, m, board, word) ||   
                    check(i, j - 1, k, len, n, m, board, word);    
        
        board[i][j] = letter;
        
        return flag;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int len = word.length();
        int n = board.size();
        int m = board[0].size();
        
    
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
               
                if (check(i, j, 0, len, n, m, board, word))
                    return true;
            }
        }
        return false;
    }
};
