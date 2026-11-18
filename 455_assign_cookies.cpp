class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int contentChildren = 0
        //Sort both arrays.
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        //Check edge cases:
        //No cookie or no children.
        if (g.size() == 0 || s.size() == 0) {
            return 0;
        }

        //Initiate currentChild, currentCookie
        int currentChild = g[0];
        int currentCookie = s[0];

        //Compare
        //jump
        
        //Return the solution.
        return contentChildren;
        
    }
};