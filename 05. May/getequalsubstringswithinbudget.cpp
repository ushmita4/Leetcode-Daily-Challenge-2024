class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.size();
        int maxi=0;
        int start=0;
        int curr=0;
        for(int i=0;i<n;i++){
            curr+=abs(s[i]-t[i]);
            while(curr>maxCost){
                curr-=abs(s[start]-t[start]);
                start++;
            }
            maxi=max(maxi,i-start+1);
        }
        return maxi;
    }
};
