class Solution {
public:
    string addBinary(string a, string b) {
        bool carry = false;
        int count(0), limit(0);
        string result = "";
        if(a.size() >  b.size()) {
            limit = a.size();
        } else limit = b.size();
        while(count < limit) {
            char ca, cb;
            if(count < a.size()) {
                ca = a[a.size() - 1 - count];
            } else ca = '0';
            if(count < b.size()) {
                cb = b[b . size() - 1 - count];
            } else cb = '0';
            //The different operations.
            if(ca == cb) {
                //If both are 0
                if(ca == '0'){
                    //If there is a 1 to carry.
                    if(carry) {
                        result = '1' + result;
                        //1 has been carried.
                        carry = false;
                        //Otherwise add 0.
                    } else result = '0' + result;
                }
                //If both are 1.
                else {
                    //If there is a 1 to carry
                    if(carry) {
                        //There is still a 1 to carry.
                        result = '1' + result;
                        //Otherwise add 0, and there is a 1 to carry
                    } else {
                        result = '0' + result;
                        carry = true;
                    }
                }
            }
            //If ca and cb are different
            else{
                if(carry) {
                    result = '0' + result;
                }
                else result = '1' + result;
            }
            count ++;
        }
        if(carry) {
            result = '1' + result;
        }
        return result;
    }
};