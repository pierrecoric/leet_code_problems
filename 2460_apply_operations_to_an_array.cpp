class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] == nums[i+1]) {
                nums[i] *=2;
                nums[i+1] = 0;
            }
        }
        int index(0), zeroes(nums.size());
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                nums[index] = nums[i];
                index ++;
                zeroes --;
            }
        }
        for(int i = 0; i < zeroes; i++) {
            nums[index] = 0;
            index ++;
        }
        return nums;
    }
};