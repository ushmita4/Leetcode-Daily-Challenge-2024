class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> res;
        vector<int> subset;
        backTrack(res,0,subset,nums,n);
        return res;
    }
    void backTrack(vector<vector<int>> &res,int index,vector<int> subset,vector<int> &nums,int &n){
        if(index==n)
        {
            res.push_back(subset);
            return;
        }
        backTrack(res,index+1,subset,nums,n);
        subset.push_back(nums[index]);
        backTrack(res,index+1,subset,nums,n);
    }
};
