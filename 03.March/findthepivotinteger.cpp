class Solution {
public:
    int pivotInteger(int n) {
        int totalSum = n * (n + 1) / 2;
        int leftSum = 0;
        
        for (int i = 1; i <= n; i++) {
            leftSum += i;
            int rightSum = totalSum - leftSum + i; 
            if (leftSum == rightSum) {
                return i;
            }
        }
        
        return -1; 
    }
};
