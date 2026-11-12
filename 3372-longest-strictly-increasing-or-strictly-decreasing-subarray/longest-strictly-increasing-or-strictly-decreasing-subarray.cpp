class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int len  = 1 ; 
        int i = 0 ; 
        for( int j = 1 ; j < nums.size() ; j++){
            if( nums[j] > nums[j-1]){
                len = max( len , j-i +1) ; 
            }
            else{
                i = j ; 
            }
        }
        i= 0 ;
        for( int j = 1 ; j < nums.size() ; j++){
            if( nums[j] < nums[j-1]){
                len = max( len , j-i +1) ; 
            }
            else{
                i = j ; 
            }
        }
        return len ;
    }
};