class Solution {
public:
    int strStr(string haystack, string needle) {
        //Iterate over the haystack
        for(int i = 0; i < haystack.size(); i++) {
            //When the start of the needle is encountered.
            if(haystack[i] == needle[0]) {
                bool found = true;
                //Iterate over the needle. If there is a difference, found is set back to false.
                for(int j = 1; j < needle.size(); j ++) {
                    if(haystack[i + j] != needle[j]) {
                        found = false;
                        break;
                    }
                }
                if(found) {
                    return i;
                }
            }
        }
        //If the needle is not in the haystack
        return -1;
    }
};