#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long result = 0;
        int n = nums.size();
        int i = 0; 
        multiset<int> window; 

        for (int j = 0; j < n; ++j) {
            
            window.insert(nums[j]);

            
            while (*window.rbegin() - *window.begin() > 2) {
                window.erase(window.find(nums[i]));
                i++;
            }

           
            result += (j - i + 1);
        }

        return result;
    }
};
