class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xorf=k;
        for(int n:nums){
            xorf ^=n;
        }
        return __builtin_popcount(xorf);
    }
};
