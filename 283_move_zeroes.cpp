class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index(0), zeros(nums.size());
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                nums[index] = nums[i];
                index ++;
                zeros --;
            }
        }
        for(int i = 0; i < zeros; i++) {
            nums[index] = 0;
            index ++;
        }
    }
};