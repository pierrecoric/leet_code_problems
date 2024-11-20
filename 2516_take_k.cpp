class Solution {
public:
    int takeCharacters(string s, int k) {
        if(k == 0) {
            return 0;
        }
        //The max depth in which we have to scan
        int maxDepth = 0;
        int min = k * 3;
        int smallest;
        bool isOdd;
        if(s.size() % 2 != 0) {
            isOdd = true;
        }

        //Variables to count the letters.
        int A(0), B(0), C(0);

        //Iterate over the string once to make sure that the problem is solvable.
        //From both side
        for(int i = 0; i < s.size() / 2; i++) {
            //Count from both sides
            countAdd(s[i], A, B, C);
            countAdd(s[s.size() - i - 1], A, B, C);
            //if we found that the problem is solvable we move on.
            if(checkCount(A, B, C, k)) {
                maxDepth = A + B + C;
                break;
            }
        }
        //if there is still a value in the middle.
        if(s.size() % 2 != 0) {
            if (maxDepth == 0) {
                countAdd(s[s.size() / 2], A, B, C);
                if(checkCount(A, B, C, k)) {
                    maxDepth = A + B + C;
                }
            }
        }

        //If it is impossible to solve
        if(maxDepth == 0) {
            return -1;
        }

        //If it is possible
        else {
            //The worst case is that the max Depth is the solution
            smallest = maxDepth;

            int L(0), R(0);
            A = 0;
            B = 0;
            C = 0;
            //move left and right to the max depth.
            while(L < maxDepth / 2) {
                countAdd(s[L], A, B, C);
                countAdd(s[s.size() - R - 1], A, B, C);
                if(checkCount(A, B, C, k)) {
                    if(A + B + C < smallest) {
                        smallest = A + B + C;
                    }
                }
                cout << "smallest " << smallest << " L: " << L << " R: " << s.size() - R - 1 << "    ABC  " << A <<  B << C << endl;
                L++;
                R++;
            }
            cout << endl;

            R -= 2;
            //Move each cursor separetadeldelady
            //Left goes forward
            while(L < maxDepth) {
                countAdd(s[L], A, B, C);
                if( R > 0) {
                    countDelete(s[s.size() - R - 1], A, B, C);
                }
                if(checkCount(A, B, C, k)) {
                    if(A + B + C < smallest) {
                        smallest = A + B + C;
                    }
                }
                cout << "smallest " << smallest << " L: " << L << " R: " << s.size() - R - 1 << "    ABC  " << A <<  B << C << endl;
                L++;
                R--;
            }

            cout << endl;

            //Back to center
            L = maxDepth / 2;
            R = maxDepth / 2;
            cout << "smallest " << smallest << " L: " << L << " R: " << s.size() - R - 1 << "    ABC  " << A <<  B << C << endl;
            cout << endl;

            //Right goes deeper
            while(R < maxDepth) {
                countDelete(s[L], A, B, C);
                if( R > 0) {
                    countAdd(s[s.size() - R - 1], A, B, C);
                }
                if(checkCount(A, B, C, k)) {
                    if(A + B + C < smallest) {
                        smallest = A + B + C;
                    }
                }
                cout << "smallest " << smallest << " L: " << L << " R: " << s.size() - R - 1 << "    ABC  " << A <<  B << C << endl;
                L--;
                R++;
            }
            
        return smallest;
        }
    }
    //Add value when we go deeper into the string
    void countAdd(char c, int &A, int &B, int &C) {
        if(c == 'a') {
            A++;
        }
        else if(c == 'b') {
            B++;
        }
        else if(c == 'c') {
            C++;
        }
    }

    //Retrieve value when we move back from the middle.
    void countDelete(char c, int &A, int &B, int &C) {
        if(c == 'a') {
            A--;
        }
        else if(c == 'b') {
            B--;
        }
        else if(c == 'c') {
            C--;
        }
    }

    bool checkCount(int A, int B, int C, int k) {
        if(A >= k && B >= k && C >= k) {
            return true;
        } else return false;
    }
};