class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        vector<pair<int,int>> vp;
        int n=profits.size();

        for(int i=0;i<n;i++)
        {
           
            vp.push_back({capital[i],profits[i]});

        }

        sort(vp.begin(),vp.end());
        int ans=w;
        int i=0;
        int m=vp.size();
        priority_queue<int> pq;


        while(i<m && k)
        {

           if(vp[i].first<=ans)
           {
             pq.push(vp[i].second);
           }else
           {
               while(!pq.empty()&& k && vp[i].first>ans)
               {
                ans=ans+pq.top();
                pq.pop();
                k--;
               }
               if(!k || ans<vp[i].first)
               {
                break;
               }
               else 
               {
                pq.push(vp[i].second);
               }
        
           }
           i++;

        }

        while(!pq.empty() && k)
        {
            ans=ans+pq.top();
            pq.pop();
            k--;

        }
      

        return ans;
    }
};
