class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;
        for( const string str: strs){
            ans+=to_string(str.length());
            ans+='#';
            ans+=str;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int current = 0;
        string temp;
        int num;
        while(current < s.length()){
            for(int i = current; i < s.length(); i++){
                if(s[i] == '#'){
                    temp = s.substr(current, i-current);
                    num = stoi(temp);
                    ans.push_back(s.substr(i+1,num));
                    current = i+1+num;
                    temp = "";
                    break;
                }
            }
        }
        return ans;
    }
};
