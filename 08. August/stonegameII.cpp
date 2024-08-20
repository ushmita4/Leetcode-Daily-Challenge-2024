class Solution {
public:
    int dp[101][101];
    int rec(vector<int> &p, int i, int m){
      if(i>= p.size()) return 0;
      if(dp[i][m]!=-1) return dp[i][m];
      int ans = INT_MIN;
      int sum = 0;
      for(int j=0; j<2*m; j++){
        if(i+j<p.size()){
          sum += p[i+j];
          ans = max(ans, sum-rec(p, i+j+1, max(m,j+1)));
        }
      }
      return dp[i][m] = ans;
    }    
    int stoneGameII(vector<int>& p) {
      memset(dp,-1,sizeof(dp));
      int diff =  rec(p, 0, 1);
      int sum = 0;
      for(int i=0; i<p.size(); i++) sum+= p[i];
      return (sum+diff)/2;
    }
};
