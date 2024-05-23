class Solution {
public:
    void generateValidParaentheses(string & s ,int index ,int count,string & temp, map<int,unordered_set<string>> &validParentheses){

        if(count<0)return ;

        if(index>=s.size()){
            if(count==0){
                validParentheses[temp.size()].insert(temp);
            }
            return ;
        }

        if(s[index]!=')' && s[index]!='('){
            temp+=s[index];
            generateValidParaentheses(s,index+1,count,temp,validParentheses);
             temp.pop_back();
        }
        else{
            generateValidParaentheses(s,index+1,count,temp,validParentheses)    ;
             temp+=s[index];
             
             generateValidParaentheses(s,index+1,count+((s[index]=='(')?  1:-1),temp,validParentheses);
             temp.pop_back();
        }
         

    }
    vector<string> removeInvalidParentheses(string s) {

     map<int,unordered_set<string>> validParentheses;
     string temp="";
     generateValidParaentheses(s,0,0,temp,validParentheses);
    return vector(validParentheses.rbegin()->second.begin(),validParentheses.rbegin()->second.end());
        
    }
};
