class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int> pq(happiness.begin(),happiness.end());
        long long sum=0;
        for(int i=0;i<k;i++){
         sum+=max(pq.top()-i,0);
         pq.pop();
        }
        return sum;
    }
};
