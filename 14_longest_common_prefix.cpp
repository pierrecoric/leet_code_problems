class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        int indexCurrent = 0;
        bool longestFound  = false;
        while (longestFound == false) {
            char currentChar = strs[0][indexCurrent];
            bool addChar = true;
            for(auto &s : strs) {
                if(s.size() == indexCurrent) {
                    return prefix;    
                }
                if(currentChar != s[indexCurrent]) {
                    addChar = false;
                    longestFound = true;
                    break;
                }
            }
            if(addChar) {
                prefix += strs[0][indexCurrent];
                indexCurrent ++;
            }
        }
        return prefix;
    }
};