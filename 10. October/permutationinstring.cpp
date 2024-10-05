class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       int s1Length=s1.length();
       int s2Length=s2.length();

       if(s1Length>s2Length)
       return false;

       vector<int> s1Count(26,0);
       vector<int> s2Count(26,0);

       for(char c:s1){
        s1Count[c-'a']++;
       }
       for(int i=0;i<s1Length;i++){
        s2Count[s2[i]-'a']++;
       }
       if(s1Count==s2Count)
       return true;

       for(int i=s1Length;i<s2Length;i++){
        s2Count[s2[i]-'a']++;
        s2Count[s2[i-s1Length]-'a']--;
        if(s1Count==s2Count)
        return true;
       }
       return false;
    }
};
