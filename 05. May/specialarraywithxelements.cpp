class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=1;i<=n;i++){
            int c=0;
            for(int j=n-1;j>=0;j--){
                if(nums[j]>=i)
                c++;
                else
                break;
            }
            if(c==i)
            return i;
        }
        return -1;
    }
};
