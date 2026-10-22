class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size() ; 
        // find the 0th position 
        int pivot = 0 ; 
        for( int i =0 ; i < n ; i++){
            if( nums[i] == 0 ){
                pivot = i ; 
                break ; 
            }
        }
        int num = 0 ;
        bool f1 = true , f2 = true ; 
        for( int i = pivot ; i< n ; i++){
            if( nums[i] != num) f1 = false ; 
            num++ ; 
        }
        for( int i = 0 ; i<pivot ; i++){
            if( nums[i] != num) f1 = false ; 
            num++ ; 
        }
        num = 0 ; 
        for( int i = pivot  ; i>=0 ; i--){
            if( nums[i] != num) f2 = false ; 
            num++ ; 
        }
        for( int i =n-1 ; i>pivot ; i--){
            if( nums[i] != num) f2 = false ; 
            num++ ; 
        }
        if( !f1 && !f2 ) return -1 ;

        if( f1 ){
            return min( pivot , n-pivot+2) ; 
        }
        else {
            return min( pivot+2 , n-pivot ) ; 
        }
        
        
    }
};