class Solution {
public:
    int minOperations(vector<string>& logs) {
      int folder=0;
        for(int i=0;i<logs.size();i++){
            if(logs[i]=="../"){
               folder=max(0,folder-1);
            }
            else{
                if(logs[i]!="./")
                folder++;
            }
        }
        return folder;
    }
};
