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
NOTE: the problem does not ask to keep track of the indexes!
Here is a waaaaay better solution than mine
*/

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int buy = prices[0];
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < buy) {
                buy = prices[i];
            } else if (prices[i] - buy > profit) {
                profit = prices[i] - buy;
            }
        }
        return profit;
    }
};

/*

I traverse the vector once and I keep 4 indexes: tmp_min & tmp_max
are the last best couple I found. When i find a new maximum I update 
tmp_max. When I find a new min compared to tmp_min, I check if 
tmp_min and tmp_max perform better than min & max. If so I 
overwrite min & max and set tmp_min and tmp_max to the last
element. The condition that tells me if one of the 2 couples
is not valid, is if they are equal.

*/

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        
        int min = 0, max = 1;
        int tmp_min, tmp_max;

        if (prices.size() == 0)
            return 0;

        if (prices.size() == 1)
            return 0;

        if (prices[0] > prices[1]){
            min = 1; 
        }

        tmp_min = min;
        tmp_max = max;
        for (int i = 2; i < prices.size(); i++){
            if (tmp_max == tmp_min){
                if (prices[i] < prices[tmp_min]){
                    tmp_min = i;
                }

                tmp_max = i;
                continue;
            }

            if (prices[i] > prices[tmp_max]){
                tmp_max = i;
                continue;
            }
            
            if (prices[i] > prices[tmp_min])
                continue;
            
            if (max == min){
                
                min = tmp_min;
                max = tmp_max;
  
            } else{
                
                int tmp_profit = prices[tmp_max] - prices[tmp_min];
                int profit = prices[max] - prices[min];
    
                if(tmp_profit > profit){
                    min = tmp_min;
                    max = tmp_max;
                }
            }

            tmp_min = i;
            tmp_max = i;

        }
        
        if (tmp_max == tmp_min){
            return max == min ? 0 : prices[max] - prices[min];
        }

        int tmp_profit = prices[tmp_max] - prices[tmp_min];
        int profit = prices[max] - prices[min];

        return tmp_profit > profit ? tmp_profit : profit;
    }
};