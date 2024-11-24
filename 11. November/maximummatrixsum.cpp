class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long totalSum = 0;
        int minAbsValue = INT_MAX;
        int negativeCount = 0;
        
       
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                int val = matrix[i][j];
                totalSum += abs(val); 
                minAbsValue = min(minAbsValue, abs(val)); 
                if (val < 0) negativeCount++;  
            }
        }
        
       
        if (negativeCount % 2 != 0) {
            totalSum -= 2 * minAbsValue;
        }
        
        return totalSum;
    }
};
