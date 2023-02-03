class Solution {
    int n;
    int dp[50];
public:
    int rec(int level) {
        // pruning
        if (level > n)
            return 0;

        // basecase
        if (level == n) return 1;

        // dp check
        if (dp[level] != -1)
            return dp[level];

        // compute
        int ways = rec(level + 1) + rec(level + 2);

        // save and return
        return dp[level] = ways;
    }

    int climbStairs(int x) {
        // 1 or 2 steps
        this->n = x;
        memset(dp, -1, sizeof(dp));
        return rec(0);
    }
};