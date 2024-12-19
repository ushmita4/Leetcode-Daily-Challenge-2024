class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int chunk_max = arr[0];
        int cnt = 0 ;
        for(int i=0;i<arr.size();++i){
            chunk_max = max(chunk_max,arr[i]);
            if(chunk_max == i){
                cnt++;
            }
        }
        return cnt ;
    }
};
