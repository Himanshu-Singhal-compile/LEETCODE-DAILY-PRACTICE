class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int mod = 1e9 +7 ; 
        int m = grid.size() , n = grid[0].size() ; 
        vector<vector<vector<int>>> dp( m , vector<vector<int>> ( n , vector<int > ( 2 , 0 ))) ; 
        dp[0][0][0] = 1 ; 

        for( int i = 0 ; i< m ;  i++){
            for( int j = 0 ; j< n ;j++){

                if( i > 0 ){
                    if( grid[i-1][j] == 0 ){
                        dp[i][j][0] = ( dp[i-1][j][0] + dp[i-1][j][1] )%mod ; 
                    }
                    else{
                        dp[i][j][0] = dp[i-1][j][1] ; 
                    }
                }
                if( j > 0 ){
                    if( grid[i][j-1] == 0 ){
                        dp[i][j][1] = ( dp[i][j-1][0] + dp[i][j-1][1] )%mod ; 
                    }
                    else{
                        dp[i][j][1] = dp[i][j-1][0] ; 
                    }
                }
            }
        }
        return( dp[m-1][n-1][0] + dp[m-1][n-1][1])%mod ; 
        


    }
};