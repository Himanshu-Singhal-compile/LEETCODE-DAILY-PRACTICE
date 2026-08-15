class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        // if all element is 0 ,
        int cnt = 0 ;  
        int ans = 0 ; 
        for( int i = 0 ; i< nums.size() ; i++){
            ans^= nums[i] ;
            if( nums[i] !=0 ){ 
                cnt++ ;
            }
        }
        int n = nums.size() ; 
        if( cnt == 0 )return 0 ; 
        if( cnt == 1 )return n ;
        if( ans != 0 )return n ;  
        return n-1 ; 
    }
};