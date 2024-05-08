class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<n;i++)
        pq.push({score[i],i});

        vector<string> rank(n);
        int pos=1;
        while(!pq.empty()){
          int index=pq.top().second;
          pq.pop();
          if(pos==1)
          rank[index]="Gold Medal";
          else if(pos==2)
          rank[index]="Silver Medal";
          else if(pos==3)
          rank[index]="Bronze Medal";
          else
          rank[index]=to_string(pos);

          pos++;
        }
        return rank;
    }
};
