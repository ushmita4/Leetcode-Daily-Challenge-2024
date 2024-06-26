class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxnum = *max_element(begin(nums), end(nums));
        long long ans = 0;
        int n = nums.size();

        vector<int> maxind(1,-1);
        for (int i = 0; i < n; i++) {
            if (nums[i] == maxnum) {
                maxind.push_back(i);
            }
        }
       
        int indsize = maxind.size();

        long long l, r;
      
        for (int i = 1; i <= indsize - k; i++) {
            l = maxind[i] - maxind[i - 1] - 1;
  
            r = n - 1 - maxind[i + k - 1];
           
            ans += (l + 1) * (r + 1);
        }
        return ans;
    }
};
