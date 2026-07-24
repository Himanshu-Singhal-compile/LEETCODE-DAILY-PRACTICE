class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        // first remove the all duplicates ; 
        int maxi = *max_element( nums.begin() , nums.end()) ; 

        int u =1 ; 
        while( u <= maxi ){
            u<<=1  ; 
        }
        vector<int> s( u+1, 0  ) ; 

        for( int i = 0 ; i< nums.size() ; i++){
            for( int j = i ;j< nums.size() ; j++){
                s[nums[i]^nums[j] ] = 1; 
            }
        }
        vector<int> is_there( u+1 , 0  ) ; 
        for( int i = 0 ; i<= u ; i++){
            if( !s[i])continue ; 
            for( int v : nums ){
                is_there[i^v] =1 ; 
            }
        }
        int ans = 0 ; 
        for( int i = 0 ; i< u ; i++){
            if( is_there[i] )ans++ ;
        }
        return ans ; 
        
        
    }
};