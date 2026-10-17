class Solution {
public:
    int digit_sum( int k ){
        int ans = 0 ; 
        while( k > 0 ){
            ans+= k%10; 
            k/=10 ; 
        }
        return ans ; 
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size() ;

        vector<vector<int> > sums( n ) ; 
        
        for( int i = 0 ; i< n ; i++ ){
           int x = digit_sum( nums[i] ) ;
           sums[i] = { x , nums[i]} ; 
        }
        sort( sums.begin() , sums.end() , []( const auto& a , const auto& b ){
            if( a[0] != b[0] )return a[0] < b[0] ; 
            else return a[1] < b[1] ; 
        });

        map<int,int> pos;
        for (int i = 0; i < n; i++) pos[sums[i][1]] = i;
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            // jab tak i pe galat element hai, usse sahi jagah bhejo
            while (pos[nums[i]] != i) {
                swap(nums[i], nums[pos[nums[i]]]);
                swaps++;
            }
        }
        return swaps;



    }
};