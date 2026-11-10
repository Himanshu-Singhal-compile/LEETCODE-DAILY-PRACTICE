class Solution {
public:
    int climbStairs(int n, vector<int>& cost) {
        
        int x = 0;
        int y = x + cost[0] + 1;
        if (n == 1)
            return y;
        int z  = min(y + cost[1] + 1, x + cost[1] + 4);
        if (n == 2)
            return z ;

        for (int i = 3; i <= n; i++) {
            int x1 = z + cost[i - 1] + 1;
            int y1 = y + cost[i - 1] + 4;
            int z1 = x + cost[i - 1] + 9;
            x = y ; 
            y = z ;
            z = min(x1, min(y1, z1));
        }
        return z;
    }
};