
class Solution {
public:
    int climbStairs(int n) {
        //Less than three steps.
        //One step: one way.
        //Two steps: two ways.
        if (n <= 2) return n;
        
        //Then for each next step:
        //We can reach the next step either in one one step from the previous step, or in one two steps from the one before.

        //Initialize two variables:
        //previous_2 is 1 (the first step)
        //previous_1 is 2 (the second step)
        int previous_2 = 1;
        int previous_1 = 2;

        //Iterate from the third step to the nth step.
        for (int i = 3; i <= n; i++) {
            //Initialize a variable to climb the stairs.
            //It is equal to the sum ot the two previous steps (i.e. all the ways we had to get there).
            int current = previous_1 + previous_2;
            //Switch the variables for the next climb.
            //previous_2 is now previous_1 and previous_1 is now the current step
            previous_2 = previous_1;
            previous_1 = current;
        }
        
        //return the solution.
        return previous_1;
    }
};
