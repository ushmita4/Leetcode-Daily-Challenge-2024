class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string s) {
        // your code here
        unordered_map<char,int>mp;
        for(auto x:s)
        {
            if(isalpha(x)) mp[tolower(x)]++;
        }
        return mp.size()==26;
    }

};
