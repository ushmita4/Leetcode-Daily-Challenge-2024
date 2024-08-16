class Solution
{
public:
    // Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        // dp array to store the maximum cuts for each length
        std::vector<int> dp(n + 1, -1);
        dp[0] = 0; // If length is 0, no cuts can be made

        // Iterate over all lengths from 1 to n
        for (int i = 1; i <= n; ++i)
        {
            if (i >= x && dp[i - x] != -1) // If we can make a cut of length x
                dp[i] = std::max(dp[i], dp[i - x] + 1);
            if (i >= y && dp[i - y] != -1) // If we can make a cut of length y
                dp[i] = std::max(dp[i], dp[i - y] + 1);
            if (i >= z && dp[i - z] != -1) // If we can make a cut of length z
                dp[i] = std::max(dp[i], dp[i - z] + 1);
        }

        // If no valid cuts could be made, return 0, otherwise return dp[n]
        return dp[n] == -1 ? 0 : dp[n];
    }
};
