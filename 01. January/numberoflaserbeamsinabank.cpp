class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
       int prev=0,c=0,ans=0;
       for(string s:bank){
           c=0;
           for(char c1:s){
               if(c1=='1')
               c++;
           }
           if(c!=0){
             ans+=(prev*c);
             prev=c;
           }
       }
       return ans; 
    }
};
