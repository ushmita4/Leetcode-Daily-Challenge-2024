class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result;
        result.reserve(s.size()+spaces.size());
        int space=0;
        for(int i=0;i<s.size();i++){
            if(space<spaces.size() && i==spaces[space]){
                result +=' ';
                space++;
            }
            result +=s[i];
        }
        return result;
    }
};
