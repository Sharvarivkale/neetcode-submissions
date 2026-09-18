class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int buy = prices[0];
        int profit = 0;

        for(int i = 1; i < prices.size(); i++) {
            
            // Update minimum buying price
            buy = min(buy, prices[i]);

            // Calculate profit if we sell today
            profit = max(profit, prices[i] - buy);
        }

        return profit;
    }
};
