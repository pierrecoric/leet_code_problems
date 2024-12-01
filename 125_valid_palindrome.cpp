class Solution {
public:
    bool isPalindrome(string s) {
        int i(0), j(s.size()-1);
        while(i <= j) {
            //find the first letter of the string
            while(toLower(s[i]) == '-' && i <= j) {
                i ++;
                cout << i;
            }
            while(toLower(s[j]) == '-' && i <= j) {
                j --;
                cout << j;
            }
            if (i > j) {
                break;
            }
                if(toLower(s[i]) != toLower(s[j])) {
                    cout << toLower(s[i]);
                    cout << toLower(s[j]);
                    return false;
                }
                i++;
                j--;
                
        }
        return true;
    }


    char toLower(char c) {
        if(int(c) >= int('a') && int(c) <= int('z')) {
            return c;
        }
        //if c is upperCase
        else if(int(c) >= int('A') && int(c) <= int('Z')) {
            return char(c - 'A' + 'a');
        }
        else if(int(c) >= int('0') && int(c) <= int('9')){
            return c;
        }
        else return '-';
    }
};