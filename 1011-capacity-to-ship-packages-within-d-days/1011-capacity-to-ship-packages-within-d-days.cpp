class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0;
        int right = 0;
        for(int i : weights){
            left = max(left, i);
            right += i;
        }
        int mid;
        int ans = right;
        while(left <= right){
            mid = (left + right) / 2;
            if(canShip(weights, days, mid)){
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }

    bool canShip(vector<int>& weights, int days, int capacity){
        int ships = 1;
        int currWeight = 0;
        for(int i : weights){
            if(currWeight + i > capacity){
                ships++;
                currWeight = 0;
            }
            currWeight += i;
        }
        if(ships > days) return false;
        return true;
    }
};