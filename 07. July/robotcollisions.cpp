class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<int> result;
        vector<int> indices(positions.size()); 
        iota(indices.begin(), indices.end(), 0); 
        sort(indices.begin(),indices.end(), 
            [&positions](int indexA,int indexB){ 
                return positions[indexA]<positions[indexB];  
            }
        );
        stack<int> st;
        for(int index : indices){
            if(directions.at(index)=='R') st.push(index);  
            else {
                if(st.empty()) continue; 
                while(!st.empty() && healths.at(st.top())<=healths.at(index)){ 
               
                    if(healths.at(st.top())==healths.at(index)){
                        healths.at(index)=-1; 
                        healths.at(st.top())=-1;
                        st.pop();
                        break;
                    }
                    else{
                        healths.at(st.top())=-1;
                        st.pop();
                        healths.at(index)--;
                    }
                }
                if(!st.empty() && healths.at(index)>0 && healths.at(st.top())> healths[index]){
                    healths.at(st.top())--;
                    healths.at(index)=-1;
                }
            }
        }
        for(int health : healths)
            if(health > 0) result.push_back(health); 
        return result;
    }
};
