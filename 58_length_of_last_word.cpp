class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        bool word = false;
        //Iterate backwards from the end.
        for(int i = s.size() - 1; i >= 0; i--){
            if(s[i] != ' ') {
                word = true;
            }
            //Once a word has started
            if(word) {
                if(s[i] == ' ') {
                    return length;
                } else length ++;
            }
        }
        //If the string was just one word.
        return length;
    }
};