class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size() ; 
        int a = -1001 , b = a , c = b ; 
        int x = 1001 , y = x ; 

        for( int num : nums ){
            int pa = a , pb = b , px = x ; 
            a = max( a , num ) ; 
            b = max( b , min( pa , num )) ; 
            c = max( c , min( pb , num )) ;

            x = min( x , num ) ; 
            y = min( y , max( px , num )) ; 


        }
        return max( a*b*c , a*x*y ) ; 
    }
};