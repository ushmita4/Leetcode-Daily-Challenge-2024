class Solution {
public:
    int minOperations(vector<int>& nums) {
      unordered_map<int,int> mp;
      int res=0;
      for(int i:nums){
       mp[i]++;
      }
      for(auto &x: mp){
          if(x.second==1)
          return -1;
          else
          res+=ceil(double(x.second)/3);
      }
      return res;  
    }
};
