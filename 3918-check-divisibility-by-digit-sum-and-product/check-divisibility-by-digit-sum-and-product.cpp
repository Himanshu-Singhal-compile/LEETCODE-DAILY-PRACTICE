class Solution {
public:
    bool checkDivisibility(int n) {
        int dsum = 0 ;
        int dp =  1 ;
        int temp = n;
        while( n ){
            int rem = n%10;
            dsum+= rem;
            dp= dp*rem;
            n = n/10;
        }
        int total = dsum+dp;
        if( temp%total == 0 ) return true ;
        return false ;
        
}
};