class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxi=0;
        for(int it : nums){
            maxi |=it;
        }
        return countSubsets(nums,0,0,maxi);
    }
    private:
    int countSubsets(vector<int> &nums,int index,int currentOr,int targetOr){
        if(index==nums.size()){
            return (currentOr==targetOr)?1:0;
        }
        int countWithout=countSubsets(nums,index+1,currentOr,targetOr);
        int countWith=countSubsets(nums,index+1,currentOr|nums[index],targetOr);

        return countWithout+countWith;
    }
};
