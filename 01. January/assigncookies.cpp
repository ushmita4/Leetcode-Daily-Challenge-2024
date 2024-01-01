class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int c=0,i=0;
        while(i<s.size() && c<g.size()){
          if(s[i]>=g[c])
          c++;

          i++;
        }
        return c;
    }
};
