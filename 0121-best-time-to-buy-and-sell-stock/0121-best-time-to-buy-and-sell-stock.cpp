class Solution {
public:
    int bestBuy(vector<int>&prices, int currentday, bool canbuy, int transcount, vector<vector<vector<int>>>&vec){
        if(currentday>=prices.size() || transcount<=0)
            return 0;
        
        // String currentKey = Integer.toString(currentDay) + "" + Integer.toString(canBuy) + "" + Integer.toString(transCount);
        // We Can't Use this Approach as it is giving TLE
        if(vec[currentday][canbuy][transcount]!=-1)
            return vec[currentday][canbuy][transcount];
        
        if(canbuy){
            int idle = bestBuy(prices, currentday+1, canbuy, transcount, vec);
            int buy = -prices[currentday] + bestBuy(prices, currentday+1, !canbuy, transcount, vec);
            return vec[currentday][canbuy][transcount]=max(idle, buy);
        }
        else{
            int idle = bestBuy(prices, currentday+1, canbuy, transcount, vec);
            int sell = prices[currentday] + bestBuy(prices, currentday+1, canbuy, transcount-1, vec);
            return vec[currentday][canbuy][transcount]=max(idle, sell);
        }
    }
    
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>>vec(prices.size(), vector<vector<int>>(2, vector<int>(2,-1)));
        return bestBuy(prices, 0, 1, 1, vec);
    }
};