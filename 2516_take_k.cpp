class Solution {
public:
    int takeCharacters(string s, int k) {

        if(k == 0) {
            return k;
        }
        
        //Array to count the letters.
        int totalLetters [3] = {0 ,0, 0};
        int size = s.size();
        int result = size;
        
        //Count the total of each letters.
        for(auto &c : s) {
            totalLetters[c - 'a'] ++;
        }
            
        //Return -1 if the count is not reachable.
        if(totalLetters[0] < k || totalLetters[1] < k || totalLetters[2] < k) {
            return -1;
        }

        //If there are enough letters to solve the problem
        else {
            //Sliding window
            int l = 0;
            for(int r = 0; r < size; r++) {
                totalLetters[s[r] - 'a'] --;
                while(totalLetters[0] < k || totalLetters[1] < k || totalLetters[2] < k) {
                    totalLetters[s[l] - 'a'] ++;
                    l ++;
                }
                //Check the size of the result.
                if (result > (size - (r - l + 1))) {
                    result = size - (r - l + 1);
                }
            }
        }
        //Return the result;
        return result;
    }
};