class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue <int, vector<int>, greater<int> > pq;
       for(int i=0;i<nums.size();i++){
           pq.push(nums[i]);
       }
       vector<int> ans;
       for(int i=0;i<nums.size();i++){
           ans.push_back(pq.top());
           pq.pop();
       }
       //reverse(ans.begin(),ans.end());
       return ans;
    }
};
