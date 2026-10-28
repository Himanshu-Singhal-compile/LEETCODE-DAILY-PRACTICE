class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size() ;
         // How to proceed with 3D DP ? 
        vector<vector<vector<int>>> dp ( m , vector<vector<int>>( n , vector<int>( 1024 , 0 ))) ; 

        // base cases  
        int x = grid[0][0] ;
        dp[0][0][x] =1 ;  
        for( int i =1  ; i< m ; i++){
            x^= grid[i][0] ;
            dp[i][0][x]= 1 ;
        }
        x = grid[0][0] ; 
        for( int j = 1 ; j< n ; j++){
            x^= grid[0][j] ;
            dp[0][j][x] = 1 ;  
        }
        
        for( int i = 1 ; i< m ; i++){
            for( int j = 1 ; j< n ; j++){
                // we can get items from i-1 , j , and i , j- 1, so procedd 
                for( int k = 0 ; k < 1024 ; k++){
                    dp[i][j][k^grid[i][j] ] |= dp[i-1][j][k] ; 
                    dp[i][j][k^grid[i][j] ] |= dp[i][j-1][k] ; 
                }
            }
        }
        for( int k = 0 ; k< 1024 ; k++){
            if( dp[m-1][n-1][k] ) return k ;  
        }
        return 0 ; 
    }
};