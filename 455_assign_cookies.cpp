class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        //Sort both arrays.
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        //Initialize currentChild and currentCookie to traverse the two vectors.
        //CurrentChid is also the amount of content children.
        int currentChild = 0;
        int currentCookie = 0;

        //While there are still either children or cookies to look at:
        //(This also handles edge cases with no child or no cookie).
        while(currentChild < g.size() && currentCookie < s.size()) {
            //If a cookie can be assigned.
            if (g[currentChild] <= s[currentCookie]) {
                currentChild ++;
            }
            //Check the next cookie
            currentCookie ++;
        }
        //Return the solution.
        return currentChild;
    }
};