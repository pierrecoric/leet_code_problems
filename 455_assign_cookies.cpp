class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        //Sort both arrays.
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        //Check edge cases:
        //No cookie or no children.
        if (g.size() == 0 || s.size() == 0) {
            return 0;
        }
        
        //Initialize currentChild and currentCookie to traverse the two vectors.
        //CurrentChid is also the amount of content children.
        int currentChild = 0;
        int currentCookie = 0;

        //While there are still either children or cookies to look at:
        while(currentChild < g.size() && currentCookie < s.size()) {
            //If a cookie can be assigned.
            if (g[currentChild] <= s[currentCookie]) {
                currentChild ++;
                currentCookie ++;
            }
            //Otherwise consider the next cookie.
            else {
                currentCookie ++;
            }
        }
        //Return the solution.
        return currentChild;
    }
};