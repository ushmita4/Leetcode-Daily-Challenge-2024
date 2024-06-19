class Solution {
public:
int getNumofBouquets(vector<int> &bloomDay,int mid,int k){
    int num=0;
    int c=0;
    for(int i=0;i<bloomDay.size();i++){
        if(bloomDay[i]<=mid)
        c++;
        else
        c=0;
        if(c==k)
        {
            num++;
            c=0;
        }
    }
    return num;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        int start=0;
        int end=0;
        for(int day:bloomDay){
            end=max(end,day);
        }
        int mini=-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(getNumofBouquets(bloomDay,mid,k)>=m){
                mini=mid;
                end=mid-1;
            }
            else
            start=mid+1;
        }
        return mini;
    }
};
