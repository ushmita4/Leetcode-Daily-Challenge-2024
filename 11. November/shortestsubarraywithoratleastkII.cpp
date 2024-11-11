class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int> hash(32,0);
        int l=0,r=0;
        int n=nums.size();
        int num=0;
        int ans=INT_MAX;

        while(r<n){
            num |=nums[r];
            for(int i=0;i<32;i++){
                if(nums[r] & (1 << i)){
                    hash[i]++;
                }
            }

            while(l<=r && num>=k){
                ans=min(ans,r-l+1);
                for(int i=0;i<32;i++){
                    if(nums[l] & (1 << i)){
                        hash[i]--;
                        if(hash[i]==0){
                            num -= (1 << i);
                        }
                    }
                }
                l++;
            }
            r++;
        }
        return (ans == INT_MAX) ? -1:ans; 
    }
};
