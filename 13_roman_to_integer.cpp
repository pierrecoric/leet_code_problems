class Solution {
public:
    int romanToInt(string s) {
        //Check if the number is negative
        bool negative = false;
        if (s[0] == '-') {
            negative = true;
        }
        //Initialize the total to 0 and the index to 0 or 1 if the string starts with a negative sign
        int total(0);
        int startIndex(0);
        if (negative) {
            startIndex = 1;
        }
        for (int i = startIndex; i < s.size() - 1; i++) {
            int nA = charToRoman(s[i]);
            int nB = charToRoman(s[i + 1]);
            //If nA is greater than or equal to the next digit in the string.
            if (nA >= nB) {
                total += nA;
            }
            //Otherwise remove nA from the total.
            else total -= nA;
        }
        //Last number
        total += charToRoman(s[s.size() - 1]);
        //Return the solution.
        if(negative) {
            return - total;
        } else return total;
    }

    //Function that returns an int from a roman character.
    int charToRoman(char c) {
        //Defining constants for each roman digit.
        const int M(1000), D(500), C(100), L(50), X(10), V(5), I(1);
        switch (c)
        {
        case 'I':
            return I;
            break;
        
        case 'V':
            return V;
            break;
        
        case 'X':
            return X;
            break;
        
        case 'L':
            return L;
            break;
        
        case 'C':
            return C;
            break;
        
        case 'D':
            return D;
            break;
        
        case 'M':
            return M;
            break;

        default:
            return 0;
            break;
        }
    }

};