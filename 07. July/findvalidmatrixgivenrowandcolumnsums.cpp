class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n=rowSum.size();
        int m=colSum.size();

        vector<vector<int>> originalMatrix(n,vector<int>(m,0));
        int i=0,j=0;
        while(i<n && j<m){
            originalMatrix[i][j]=min(rowSum[i],colSum[j]);

            rowSum[i] -=originalMatrix[i][j];
            colSum[j] -=originalMatrix[i][j];

            rowSum[i]==0?i++:j++;
        }
        return originalMatrix;
    }
};
