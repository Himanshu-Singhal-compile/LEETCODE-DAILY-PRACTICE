class Solution {
public:
    int climbStairs(int n, vector<int>& cost) {
        vector<int> dp( n+1 ) ; 
        // j-1 - j 
        // dp[j-1] + cost[j-1] + 1  ; 
        // j-2- j 
        // dp[j-2] + cost[j-1] + 4 ; 
        // j-3 - j 
        // dp[j-3] + cost[j-1] + 9 ; 
        dp[0] = 0 ;
        dp[1] = dp[0] + cost[0] + 1  ;
        if( n ==1 )return dp[1] ;  
        dp[2] = min( dp[1] + cost[1] + 1, dp[0]+ cost[1] + 4 ) ; 
        if( n == 2 )return dp[2] ; 
        dp[3] = min( dp[0] + cost[2] + 9 , min( dp[1] + cost[2]+ 4 , dp[2] + cost[2] + 1 )) ; 
        if( n == 3 )return dp[3] ; 

        for( int i = 4 ; i<= n ; i++){
            int x = dp[i-1] + cost[i-1]+ 1 ; 
            int y = dp[i-2] + cost[i-1] +4 ; 
            int z = dp[i-3] + cost[i-1] + 9 ; 
            dp[i] = min( x , min( y, z )) ;           
        }
        return dp[n] ;


        
    }
};