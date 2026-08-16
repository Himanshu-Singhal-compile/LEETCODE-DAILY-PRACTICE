class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int n = stones.size() ;
        if( n  ==1 )return false ; 
        vector<int> cnt( 3 , 0);  
        for( int i = 0 ; i< n ; i++){
            cnt[stones[i]%3]++ ;
        } 
        // have cnt of those three
        
        if( cnt[0]%2 == 0 ){
            return cnt[1] >= 1 && cnt[2] >=1 ; 
        }
        return abs(cnt[1] -cnt[2]) >2 ;

        
    }
};