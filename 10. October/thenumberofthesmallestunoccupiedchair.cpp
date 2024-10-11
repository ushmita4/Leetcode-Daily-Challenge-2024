class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector<pair<int, int>> arrival, departure;

        int n = times.size();

        for (int i = 0; i < n; i++) {
            arrival.push_back({times[i][0], i}); 
            departure.push_back({times[i][1], i});
        }

        sort(arrival.begin(), arrival.end());
        sort(departure.begin(), departure.end());
        priority_queue<int, vector<int>, greater<int>> freeChairs;

        for (int i = 0; i < n; i++)
            freeChairs.push(i); 

        vector<int> chairAssigned(n, 0);
        int i = 0, j = 0;
        while (i < n) {
           
            while (j < n && departure[j].first <= arrival[i].first) {
                freeChairs.push(chairAssigned[departure[j].second]);
                j++;
            }

            
            int currentFriend = arrival[i].second;
            int assigned = freeChairs.top();
            freeChairs.pop();
            chairAssigned[currentFriend] = assigned;

           
            if (currentFriend == targetFriend)
                return chairAssigned[targetFriend];
            i++;
        }

        return -1;
    }
};
