class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i = 0, j = 0, n = nums.size();
        unordered_map<int, int> mp;
        int res = 0;

        while (i < n) {
            mp[nums[i]]++;
            if (mp[nums[i]] > k) {
                while (j < i && mp[nums[i]] > k) {
                    mp[nums[j]]--;
                    if (mp[nums[j]] == 0)
                        mp.erase(nums[j]);
                    j++;
                }
            }
            res = max(res, i - j + 1);
            i++;
        }

        return res;
    }
};
