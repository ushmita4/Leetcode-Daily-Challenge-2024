class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size();
    
    int ld = s.find_last_of('1');
    
 
  swap(s[ld], s[n-1]);
    
   
   sort(s.begin(), s.begin() + n - 1, greater<char>());
    
    return s;
    }
};
