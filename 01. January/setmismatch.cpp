
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int xorAll = 0;
        int xorArray = 0;

     
        for (int i = 1; i <= n; i++) {
            xorAll ^= i;
        }

        
        for (int num : nums) {
            xorArray ^= num;
        }

       
        int xorResult = xorArray ^ xorAll;

        
        int rightmostSetBit = xorResult & -xorResult;

        int xorSet = 0;
        int xorNotSet = 0;

        
        for (int i = 1; i <= n; i++) {
            if (i & rightmostSetBit) {
                xorSet ^= i;
            } else {
                xorNotSet ^= i;
            }
        }

        for (int num : nums) {
            if (num & rightmostSetBit) {
                xorSet ^= num;
            } else {
                xorNotSet ^= num;
            }
        }

        
        for (int num : nums) {
            if (num == xorSet) {
                return {xorSet, xorNotSet};
            }
        }

        
        return {xorNotSet, xorSet};
    }
};


