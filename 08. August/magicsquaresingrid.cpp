class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i + 2 < m; i++) {
            for (int j = 0; j + 2 < n; j++) {
                if (isMagicSquare(grid, i, j)) {
                    count++;
                }
            }
        }
        return count;
    }

private:
    bool isMagicSquare(vector<vector<int>>& grid, int row, int col) {
       
        if (grid[row + 1][col + 1] != 5) {
            return false;
        }

       
        vector<int> borderIndices = {0, 1, 2, 5, 8, 7, 6, 3};
        string border = "";
        for (int i : borderIndices) {
            int num = grid[row + i / 3][col + i % 3];
            border += to_string(num);
        }

        string expectedSequence1 = "2943816729438167";
        string expectedSequence2 = "7618349276183492";

        
        return (expectedSequence1.find(border) != string::npos ||
                expectedSequence2.find(border) != string::npos);
    }
};
