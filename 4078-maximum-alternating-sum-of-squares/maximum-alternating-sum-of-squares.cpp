class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size() ; 
        vector<long long> new_nums ; 
        for( int i = 0; i < n ; i++){
            new_nums.push_back((long long)nums[i]*nums[i]) ; 
        }
            
        
        sort( new_nums.begin() , new_nums.end()) ;

        long long ans = 0 ; 
        int i = 0 , j = n-1 ; 
        if( n&1 ){
            ans+= new_nums[j] ;
            j-- ;  
        } 
        // include i , j , 
        while( i < j ){
            ans+= new_nums[j--] - new_nums[i++] ; 
        }
        return ans ; 
        
        
    }
};