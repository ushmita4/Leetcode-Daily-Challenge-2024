class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        double totalCost = INT_MAX;
        double totalCurrentQuality = 0;
        vector<pair<double,int>> wageToQualityRatio;
        
        // Populate the vector of pairs
        for(int i = 0; i < n; i++)
            wageToQualityRatio.push_back(make_pair((double)wage[i] / quality[i], quality[i]));

        // Sort based on wage-to-quality ratio
        sort(wageToQualityRatio.begin(), wageToQualityRatio.end());

        // Define a priority queue to keep track of highest quality workers
        priority_queue<int> highestQualityWorkers;

        // Comparison function for the priority queue
        auto comp = [](const pair<double, int>& a, const pair<double, int>& b) {
            return a.second < b.second;
        };

        for(int i = 0; i < n; i++) {
            highestQualityWorkers.push(wageToQualityRatio[i].second);
            totalCurrentQuality += wageToQualityRatio[i].second;

            if(highestQualityWorkers.size() > k) {
                totalCurrentQuality -= highestQualityWorkers.top();
                highestQualityWorkers.pop();
            }

            if(highestQualityWorkers.size() == k)
                totalCost = min(totalCost, totalCurrentQuality * wageToQualityRatio[i].first);
        }
        return totalCost;
    }
};
