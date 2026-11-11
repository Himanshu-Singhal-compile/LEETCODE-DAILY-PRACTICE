class Solution {
public:
    long long minimumCost(long long cost1, long long cost2, long long costBoth, long long need1, long long need2) {
        long long ans = 0 ; 
        if( cost1 + cost2 <= costBoth){
            return (long long)( cost1*need1 + cost2*need2 ) ;
        }
        long long x = (long long ) min( need1 , need2 ) ; 
        ans+= ( long long )( x*costBoth) ; 
        
        need2 -= x ; 
        need1 -= x ; 
        ans+= (long long)need1*min( cost1  , costBoth) + (long long)need2*min( cost2 , costBoth) ; 
        return ans ; 

    }
};