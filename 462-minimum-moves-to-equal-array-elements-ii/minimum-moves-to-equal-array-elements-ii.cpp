class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size() ;
        sort( nums.begin() , nums.end()) ; 
        int i =0 , j = n- 1;
        int ans = 0 ;  
        while( i< j ){
            ans+= ( nums[j--] - nums[i++] ) ; 
        }
        return ans ; 
        
    }
};