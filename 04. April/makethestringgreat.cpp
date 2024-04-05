class Solution {
public:
    std::string makeGood(std::string s) {
        int endPosition = 0; 
        char charArray[s.size()]; 

        for (int i = 0; i < s.size(); ++i) {
            charArray[i] = s[i];
        }

      
        for (int currentPosition = 0; currentPosition < s.size(); currentPosition++) {
           
            if (endPosition > 0 && abs(charArray[currentPosition] - charArray[endPosition - 1]) == 32)
                endPosition--; 
            else {

                charArray[endPosition] = charArray[currentPosition];
                endPosition++;
            }
        }

        // Convert the modified character array to a string and return only the valid portion
        return std::string(charArray, charArray + endPosition);
    }
};
