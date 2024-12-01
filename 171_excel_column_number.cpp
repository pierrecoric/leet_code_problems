class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n(0); 
        long rank(1);
        for(int i = columnTitle.size() -1; i >= 0; i--) {
            n += rank * (columnTitle[i] - 'A' + 1);
            rank *= 26;
        }
        return n;
    }
};