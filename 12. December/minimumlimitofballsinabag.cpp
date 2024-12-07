class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

           
            if (canAchievePenalty(nums, maxOperations, mid)) {
                result = mid;  
                right = mid - 1;  
            } else {
                left = mid + 1;  
            }
        }

        return result;
    }

private:
    bool canAchievePenalty(const vector<int>& nums, int maxOperations, int penalty) {
        int operations = 0;
        for (int balls : nums) {
            if (balls > penalty) {
                
                operations += (balls - 1) / penalty;
            }
        }
        return operations <= maxOperations;
    }
};
