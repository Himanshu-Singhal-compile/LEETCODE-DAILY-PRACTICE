class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size() ; 
        int maxi = *max_element( nums.begin() , nums.end()) ; 
        int mini = *min_element( nums.begin() , nums.end()) ; 
        sort( nums.begin()  , nums.end()) ;
        return  min( maxi - nums[2]  , min(nums[n-3] - mini  , nums[n-2] - nums[1] )) ;  
        // do lowscore as 0 or High score as 0 , 


        
    }
};