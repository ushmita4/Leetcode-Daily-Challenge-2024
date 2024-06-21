class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        int unCustomers=0;
        for(int i=0;i<minutes;i++){
            unCustomers+=customers[i]*grumpy[i];
        }
        int maxunCustomers=unCustomers;
        for(int i=minutes;i<n;i++){
            unCustomers +=customers[i]*grumpy[i];
            unCustomers -=customers[i-minutes]*grumpy[i-minutes];

            maxunCustomers=max(maxunCustomers,unCustomers);
        }
        int tC=maxunCustomers;
        for(int i=0;i<n;i++)
        tC +=customers[i]*(1-grumpy[i]);

        return tC;
    }
};
