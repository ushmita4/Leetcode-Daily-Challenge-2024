class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n=nums.size();
        map<int,int> p1;
        map<int,int> n1;
        for(int i=0;i<n;i++){
            if(nums[i]>0)
                p1[nums[i]];
            if(nums[i]<0)
                n1[nums[i]];
        }
        int maxi=-1;
        for(auto it : p1)
        {
            int x=it.first;
            int x1=-x;
            if(n1.find(x1)!=n1.end()&&x>maxi)
                maxi=x;
        }
        return maxi;
    }
};
