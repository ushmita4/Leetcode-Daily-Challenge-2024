class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=difficulty.size();
        int m=worker.size();
        vector<pair<int,int>> job;
        for(int i=0;i<n;i++){
            job.push_back({difficulty[i],profit[i]});
        }
        sort(job.begin(),job.end());
        sort(worker.begin(),worker.end());
        int j=0,profitC=0,sum=0;

        for(int i=0;i<m;i++){
            while(j<n && worker[i]>=job[j].first){
                profitC=max(profitC,job[j].second);
                j++;
            }
            sum+=profitC;
        }
        return sum;
    }
};