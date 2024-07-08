class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> circle;
        for(int i=1;i<=n;i++){
            circle.push_back(i);
        }
        int index=0;
        while(circle.size()>1){
            int remove=(index+k-1)%circle.size();
            circle.erase(circle.begin()+remove);
            index=remove;
        }
        return circle.front();
    }
};
