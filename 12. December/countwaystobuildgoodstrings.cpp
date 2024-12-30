class Solution {
public:
const int mod = 1000000007;
vector<long long> dp;

    void makedp(vector<int>& opt, int high){
        dp.resize(high+1, 0);
        sort(opt.begin(), opt.end());
        
        for(auto c: opt) dp[c]++; 

        for(int i=0; i<=high; i++){
            for(auto c: opt){
                if(i<c) break;
                if(dp[i-c]) dp[i] = (dp[i]%mod + dp[i-c]%mod)%mod; 
            }
        }
    }


    int countGoodStrings(int low, int high, int zero, int one) {

       

        vector<int> opt = {zero, one}; 
        
        makedp(opt, high); 

        long long sum =0;
        for(int i=low; i<=high; i++){
            sum = (sum%mod + dp[i]%mod)%mod; 
        }

        return sum;
    }
};
