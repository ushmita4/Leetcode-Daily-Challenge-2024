class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        stack<int> indicesStack;
        for(int i=0;i<n;i++){
            if(indicesStack.empty() || nums[indicesStack.top()]>nums[i]){
                indicesStack.push(i);
            }
        }
        int maxWidth=0;
        for(int i=n-1;i>=0;i--){
            while(!indicesStack.empty() && nums[indicesStack.top()]<=nums[i]){
                maxWidth=max(maxWidth,i-indicesStack.top());
                indicesStack.pop();
            }
        }
        return maxWidth;
    }
};
