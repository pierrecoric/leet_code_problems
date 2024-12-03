class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        //Prealocating memory to the string.
        string alter(s.size() + spaces.size(), 'x');

        //Pointer for the spaces array.
        int countSpaces(0);
        int index = spaces[countSpaces];

        //Iterate over the string.
        for(int i = 0; i < s.size(); i ++) {
            //When we reach a space in the array
            if(i == index) {
                //Add the space.
                alter [countSpaces + i] = ' ';
                //Increment the pointer and update the index of the next space.
                countSpaces ++;
                if(countSpaces < spaces.size()) {
                    index = spaces[countSpaces];
                }
            }
            //Add the current letter at index i + the count of spaces already encoutered.
            alter[countSpaces + i] = s[i];
        }
        return alter;
    }
};