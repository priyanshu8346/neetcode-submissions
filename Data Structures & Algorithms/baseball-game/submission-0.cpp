class Solution {
public:
    int calPoints(vector<string>& operations) {
        int ans=0;
        vector<int> arr;
        int temp;
        for(auto& it: operations){
            if(it=="+"){
                temp = arr[arr.size() - 1] + arr[arr.size() - 2];
                arr.push_back(temp);
                ans+=temp;
            }
            else if(it == "D"){
                temp = 2*arr[arr.size() - 1];
                arr.push_back(temp);
                ans+=temp;
            }
            else if(it == "C"){
                ans-=arr[arr.size() - 1];
                arr.pop_back();
            }
            else{
                temp = stoi(it);
                arr.push_back(temp);
                ans+=temp;
            }
        }
        return ans;
    }
};