class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;

   
    for (int num : nums) {
        mp[num]++;
    }

    int maxFrequency = 0;
    int tc = 0;

    
    for (const auto& [element, frequency] : mp) {
        if (frequency > maxFrequency) {
            maxFrequency = frequency;
            tc = 1;
        } else if (frequency == maxFrequency) {
            tc++; 
        }
    }

    return maxFrequency * tc;
    }
};
