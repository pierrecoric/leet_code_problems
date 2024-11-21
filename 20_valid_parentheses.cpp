class Solution {
public:

    bool isValid(string s) {
        //if the string has an odd number of characters.
        if(s.size() % 2 != 0) {
            return false;
        }

        //Declare a vector to store the open brackets.
        vector<char> openBrackets = {};
        
        //Iterate over the string.
        for(int i = 0; i < s.size(); i++) {
            int indexO = indexOpen(s[i]);
            if (indexO != -1) {
                openBrackets.push_back(indexO);
            }
            else{
                int indexC = indexClosed(s[i]);
                if(openBrackets.size() == 0 || openBrackets[openBrackets.size() - 1] != indexC) {
                    return false;
                } else openBrackets.pop_back();
            }
        }
        //If we reached the end of the string and there are still unmatched open brackets.
        if(openBrackets.size() > 0) {
            return false;
        } else return true;
    }

    int indexOpen(char b) {
        switch(b) {
            case '(':
                return 0;
                break;

            case '[':
                return 1;
                break;
            
            case '{':
                return 2;
                break;
            
            default:
                return -1;
                break;
        }
    }

    int indexClosed(char b) {
        switch(b) {
            case ')':
                return 0;
                break;

            case ']':
                return 1;
                break;
            
            case '}':
                return 2;
                break;
            
            default:
                return -1;
                break;
        }
    }
};