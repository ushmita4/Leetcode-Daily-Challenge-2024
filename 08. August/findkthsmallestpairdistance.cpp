class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0, right = nums[n-1] - nums[0];

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (countPairs(mid, nums) < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return left;
    }

private:
    int countPairs(int mid, const vector<int>& nums) {
        int count = 0;
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            while (j < nums.size() && nums[j] - nums[i] <= mid) {
                ++j;
            }
            count += j-i-1;
        }
        return count;
    }
};
