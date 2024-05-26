class Solution {
public:
    int M=1e9+7;
    int fun(int i, int a, int consecutiveL, int n,vector<vector<vector<int>>> &dp)
    {
        if(i==n) return 1;

        if(dp[i][a][consecutiveL] !=-1)return dp[i][a][consecutiveL];

        long long ans=0;

        if(a>0) // Absent
        { 
            ans+=fun(i+1,a-1,0,n,dp);
            ans%=M;
        }

        if(consecutiveL<2) // Late
        { 
            ans+=fun(i+1,a,consecutiveL+1,n,dp);
            ans%=M;
        }

        // Present

        ans+=fun(i+1,a,0,n,dp);
        ans%=M;

        return dp[i][a][consecutiveL]=ans;
    }

    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return fun(0,1,0,n,dp);
    }
};
