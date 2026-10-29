class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        else {
            long int mirror = 0;
            long int temp = x;
            while (temp != 0) {
                int current = temp % 10;
                mirror = (mirror * 10) + current;
                temp -= current;
                temp = temp / 10;
            }
            if (mirror == x) {
                return true;
            } else { return false; }
        }
    }
};

//The fun being: not converting the integer to a String.