class Solution {
public:
    int sumCounts(vector<int>& nums) {
        // find all the subarray , 
        // do the square , 
        int ans = 0;
        int n = nums.size() ; 
        for( int i= 0 ; i < n ; i++){
            for( int j =i ; j<n ; j++){
                unordered_map<int, int> freq ; 
                int count = 0 ; 
                for( int k = i ; k <=j  ; k++){
                    if( !freq.count(nums[k] )) count++  ; 
                    freq[nums[k]] =1 ; 
                }
                ans+= ( count*count) ; 
            }
        }
        return ans ; 
        
    }
};