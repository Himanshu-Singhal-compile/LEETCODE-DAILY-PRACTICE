class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& seats ) {
        int m = seats.size() ; 
        sort( seats.begin() , seats.end() , []( const auto& a , const auto& b ){
            return a[1] < b[1] ; 
        }) ; 
        long long last_seat = 0 ; 
        long long ans = 0 ; 
        map<int , vector<int> > row_wise ; 
        for( int i = 0 ; i< m ; i++){
            row_wise[seats[i][0]].push_back( seats[i][1] ) ; 
        }

        for( auto& p : row_wise ){
            int current_seat = p.first ; 
            vector<int> row_reserve_seat = p.second ; 
            vector<int> vis ( 11 , 0 ) ; 
            for( int s : row_reserve_seat )vis[s] =1 ; 

            // check for all 3 cases 
            int cnt = 0 ; 
            if( !vis[2] && !vis[3] && !vis[4] && !vis[5] && !vis[6] && !vis[7] && !vis[8] && !vis[9] )cnt+=2 ; 
            else if( !vis[2] && !vis[3] && !vis[4] && !vis[5] )cnt++ ; 
            else if( !vis[4] && !vis[5] && !vis[6] && !vis[7] ) cnt++ ; 

            else if(!vis[6] && !vis[7] && !vis[8] && !vis[9]) cnt++ ; 

            ans+= cnt ; 
            ans+= (current_seat - last_seat - 1)*2; 
            last_seat = current_seat ; 
        }
        if( last_seat != n ){
            ans+= ( n- last_seat)*2 ; 
        }
        return ( int)ans ; 


    }
};