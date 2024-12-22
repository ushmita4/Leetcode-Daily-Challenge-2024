class Solution {
public:
    static const int MXN = 50005;
    static const int LOG = 16;
    int m[MXN][LOG];
    
    int query(int l, int r) {
        int len = r - l + 1;
        int k = 0;
        while ((1 << (k + 1)) <= len) {
            k++;
        }
        return max(m[l][k], m[r - (1 << k) + 1][k]);
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        for (int i = 0; i < n; i++) {
            m[i][0] = heights[i];
        }

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i + (1 << j) - 1 < n; i++) {
                m[i][j] = max(m[i][j - 1], m[i + (1 << (j - 1))][j - 1]);
            }
        }

        vector<int> ret;

        for (auto& it : queries) {
            int a = it[0], b = it[1];

            if(a>b){
                swap(a,b);
            }

            if(heights[b]>heights[a]){
                ret.push_back(b);
                continue;
            }
            if (a == b) {
                ret.push_back(a);
                continue;
            }

            int low = b+1;
            int high = n - 1;
            int ans = -1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                int val = query(b+1, mid);
                if (val > heights[a] && val > heights[b]) {
                    ans = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            ret.push_back(ans);
        }

        return ret;
    }
};
