class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> is(128,0) , no(128,0);
        for(int i=0 ; i  < s.size() ; i++) {
            if(is[s[i]] != no[t[i]]) {
                return false;
            }
            is[s[i]] = i+ 1;
            no[t[i]] = i+ 1;
         }
        return true;
    }
};
