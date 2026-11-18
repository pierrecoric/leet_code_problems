class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        //There is always enough space for no flower.
        if (n == 0) return true;
        for (int i = 0; i < flowerbed.size(); i++) {
            //The first check.
            if(i == 0) {
                //Check for array of size 1.
                if (flowerbed.size() == 1) {
                    if (flowerbed[i] == 0) {
                        n--;
                    }
                }
                //Can place flower in the first position.
                else if (flowerbed[i] == 0 && flowerbed[i+1] == 0) {
                    n--;
                    i++;
                }
            }
            else if (i == flowerbed.size() - 1) {
                //Can place flower in the last position.
                if (flowerbed[i] == 0 && flowerbed[i - 1] == 0) {
                    n--;
                }
            }
            //All the other positions:
            else {
                //Can place flower, decrement n, increment i since we have placed a flower there.
                if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
                    n--;
                    i++;
                }
            }
            //Check at each itteration if we can place all the flowers.
            if (n == 0) {
                return true;
            }
        }
        //If we are here, n is still greater than 0.
        return false;
    }
};