class Solution {
public:
    long long dfs( int i , int j , vector<vector<int> > & vis , vector<vector<int>>& grid ){
        int m = grid.size() , n = grid[0].size() ;
        
        if( grid[i][j] == 0 )return 0 ;
        vis[i][j] = 1 ; 
        int dr[4] = { -1 , 0 , 1 , 0 } , dc[4] = { 0 , -1 , 0 ,1 } ;
        long long xp = grid[i][j]  ;
        for( int k = 0 ; k< 4 ; k++){
            int nr = i + dr[k] , nc = j+ dc[k] ; 
            if( nr>= 0 && nc>=0 && nr< m && nc< n && grid[nr][nc] != 0 && !vis[nr][nc]){
                xp+= ( dfs( nr , nc  , vis , grid  )) ; 
            }
        } 
        return xp ; 
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size() , n = grid[0].size() ; 
        vector<vector<int> > vis( m , vector<int> ( n ,0 )) ; 
        int ans = 0 ; 
        for( int i = 0 ; i< m ; i++){
            for( int j = 0 ; j< n ; j++){
                if( vis[i][j ] ||  grid[i][j] == 0  ) continue ; 
                long long x = dfs( i , j , vis , grid ) ; 
                cout<< x << " "; 
                if( x!= 0 && x%k == 0 ){
                    ans++ ; 
                }
            }
        }
        return ans ; 
    }
};