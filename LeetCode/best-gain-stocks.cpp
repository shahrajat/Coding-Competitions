class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int deal= 0,low;
        if(prices.size()>0)
            low = prices[0];
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]-low > deal)
                deal = prices[i]-low;
            if(prices[i] < low)
                low = prices[i];
        }
        return deal;
    }
};
