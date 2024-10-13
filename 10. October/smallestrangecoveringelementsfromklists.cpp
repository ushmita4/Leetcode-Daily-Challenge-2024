class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> merged; 
        
      
        for (int i = 0; i < nums.size(); ++i) {
            for (int num : nums[i]) {
                merged.push_back({num, i});
            }
        }
        
      
        sort(merged.begin(), merged.end());
        
     
        unordered_map<int, int> count;  
        int left = 0, right = 0;
        int k = nums.size(); 
        int numListsCovered = 0;  
        int minRange = INT_MAX;
        pair<int, int> result;
        
        while (right < merged.size()) {
           
            int listIdx = merged[right].second;
            count[listIdx]++;
            if (count[listIdx] == 1) numListsCovered++;  
            right++;
            
            
            while (numListsCovered == k) {
                int rangeStart = merged[left].first;
                int rangeEnd = merged[right - 1].first;
                
                if (rangeEnd - rangeStart < minRange) {
                    minRange = rangeEnd - rangeStart;
                    result = {rangeStart, rangeEnd};
                }
                
              
                int leftListIdx = merged[left].second;
                count[leftListIdx]--;
                if (count[leftListIdx] == 0) numListsCovered--;  
                left++;
            }
        }
        
        return {result.first, result.second};
    }
};
