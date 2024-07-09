class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n=customers.size();
        int idle=0;
        long long total=0;
        for(int i=0;i<n;i++){
            idle=max(customers[i][0],idle)+customers[i][1];
            total+=idle-customers[i][0];
        }
        double average=static_cast<double>(total)/n;
        return average;
    }
};
