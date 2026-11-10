class Solution {
public:
    int climbStairs(int n, vector<int>& cost) {
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = dp[0] + cost[0] + 1;
        if (n == 1)
            return dp[1];
        dp[2] = min(dp[1] + cost[1] + 1, dp[0] + cost[1] + 4);
        if (n == 2)
            return dp[2];

        for (int i = 3; i <= n; i++) {
            int x = dp[i - 1] + cost[i - 1] + 1;
            int y = dp[i - 2] + cost[i - 1] + 4;
            int z = dp[i - 3] + cost[i - 1] + 9;
            dp[i] = min(x, min(y, z));
        }
        return dp[n];
    }
};