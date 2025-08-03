/*
You are given an array prices where prices[i] is the price 
of a given stock on the ith day.

You want to maximize your profit by choosing a single day 
to buy one stock and choosing a different day in the future 
to sell that stock.

Return the maximum profit you can achieve from this transaction. 
If you cannot achieve any profit, return 0.
*/

#include <vector>

/*
NOT WORKING! 
counter example: 98,99, 2, 34, 0, 5
*/

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if (prices.size() == 0 || prices.size() == 1){
            return 0;
        }

        int min = 0, max = 1;

        for (int i = 2; i < prices.size(); i++){
            if(prices[i] < prices[min])
                min = i;
            else if (prices[i] > prices[max])
                max = i;
        }

        if (min < max)
            return prices[max] - prices[min];

        int min1 = 0, max1 = max + 1;

        for(int i = 0; i < max; i++){
            if(prices[i] < prices[min1])
                min1 = i;
        }

        for(int i = max + 2; i < prices.size(); i++){
            if (prices[i] > prices[max1])
                max1 = i;
        }

        int profit = prices[max] - prices[min1];
        int profit1 = prices[max1] - prices[min];

        return profit > profit1 ? profit : profit1; 
        

    }
};
        // int min = 0, max = 1;
        // int tmp_min, tmp_max;

        // if (prices.size() == 0)
        //     return 0;

        // if (prices.size() == 1)
        //     return 0;

        // if (prices[0] > prices[1]){
        //     max = 0;
        //     min = 1; 
        // }

        // tmp_min = min;
        // tmp_max = max;
        // for (int i = 2; i < prices.size(); i++){
        //     if (tmp_max == 0){
        //         if (prices[i] < prices[tmp_min]){
        //             tmp_min = i;
        //             continue;
        //         }

        //         tmp_max = i;
        //         continue;
        //     }

        //     if (prices[i] > prices[tmp_max]){
        //         tmp_max = i;
        //         continue;
        //     }

        //     if (prices[i] < prices[tmp_max]){
        //         int tmp_profit = prices[tmp_max] - prices[tmp_min];
        //         int profit = prices[max] - prices[min];

        //         if(tmp_profit > profit){
        //             min = tmp_min;
        //             max = tmp_max;
        //         }

        //         tmp_min = i;
        //         tmp_max = 0;

        //         continue;
        //     }
        // }
        
        // if (tmp_max == 0){
        //     return max == 0 ? 0 : prices[max] - prices[min];
        // }

        // int tmp_profit = prices[tmp_max] - prices[tmp_min];
        // int profit = prices[max] - prices[min];

        // return tmp_profit > profit? tmp_profit : profit;