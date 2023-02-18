class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> maxTillLeft(n);
        int mxp = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1) {
                maxTillLeft[i] = prices[i];
            }
            else {
                maxTillLeft[i] = max(maxTillLeft[i + 1], prices[i]);
                mxp = max(mxp, maxTillLeft[i] - prices[i]);// Profit = SP - CP
            }
        }

        return mxp;
    }
};
// TC: O(N), SC: O(N)
// [7,1,5,3,6,4] if we say that we will sell at i, then CosrPrice will be min from the left
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // if we say we sell at i, then we buy at the min from [0..i]
        int n = prices.size();
        int minp = INT_MAX;
        int maxp = 0;
        for (int i = 0; i < n; i++) {
            if (prices[i] < minp) {
                minp = prices[i];// maintain minp till i
            }
            maxp = max(maxp, prices[i] - minp);// update max profit if you sell at i here
        }

        return max(0, maxp);// min value of maxp can be 0
    }
};

