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

        vector<vector<int> > v( n ) ; 
        
        for( int i = 0 ; i< n ; i++ ){
           int x = digit_sum( nums[i] ) ;
           v[i] = { x , nums[i], i } ; 
        }
        sort(v.begin(), v.end());

        vector<bool> vis(n, false);
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i] || v[i][2] == i) continue;
            int j = i, len = 0;
            while (!vis[j]) {
                vis[j] = true;
                j = v[j][2];
                len++;
            }
            swaps += len - 1;
        }
        return swaps;



    }
};