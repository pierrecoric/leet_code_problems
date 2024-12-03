class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int limitLow(0), limitHigh(nums.size() -1);
        
        while(limitLow <= limitHigh) {
            int index = limitLow + (limitHigh - limitLow) / 2;

            if(nums[index] == target) {
                return index;
            } 
            //if n at this index > target
            else if(nums[index] < target) {
                limitLow = index + 1;
            }
            //if n at this index < target
            else {
                limitHigh = index - 1;
            }
        }
        return limitLow;
    }
};