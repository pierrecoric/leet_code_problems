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
        
        //We will use currentChild and currentCookie to traverse the two vectors.
        int currentChild = 0;
        int currentCookie = 0;

        //While there are still either children or cookies to look at:
        while(currentChild < g.size() && currentCookie < s.size()) {
            //If cookie can be assigned
            if (g[currentChild] <= s[currentCookie]) {
                contentChildren ++;
                currentChild ++;
                currentCookie ++;
            }
            //Else, if the current cookie is too small.
            else {
                //Check for the next suitable cookie
                bool found = false;
                while (!found) {
                    currentCookie ++
                    //If we have considered all the cookies, return the solution.
                    if(currentCookie > s.size() - 1) {
                        return contentChildren;
                    }
                    else if(s[currentCookie >= g[currentChild]]) {
                        found = true;
                    }
                }
            }
        }

        //Return the solution.
        return contentChildren;
        
    }
};