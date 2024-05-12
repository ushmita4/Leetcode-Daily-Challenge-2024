class Solution {
    int maxi(vector<vector<int>> &grid,int i,int j){
        int maxElement=INT_MIN;
        for(int i1=i;i1<i+3;i1++){
            for(int j1=j;j1<j+3;j1++){
                maxElement=max(maxElement,grid[i1][j1]);
            }
        }
        return maxElement;
    }
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
      int n=grid.size();
      vector<vector<int>> maxLocal(n-2,vector<int>(n-2,0));
      for(int i=0;i<n-2;i++){
        for(int j=0;j<n-2;j++){
            maxLocal[i][j]=maxi(grid,i,j);
        }
      }
      return maxLocal;  
    }
};
