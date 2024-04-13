class Solution {
public:

    int solve(vector<int> &heights){
        int n = heights.size();
        vector<int> nslr(n),nsrl(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(st.empty()) nslr[i] = -1;
            else nslr[i] = st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
          for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(st.empty()) nsrl[i] = n;
            else nsrl[i] = st.top();
            st.push(i);
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans,heights[i]*(nsrl[i]-nslr[i]-1));
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);
        int ans = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> heights(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == '0'){
                    heights[j] = 0;
                }else{
                    heights[j]+=1;
                }
            }
            ans = max(ans,solve(heights));
        }
        return ans;
        
    }
};
