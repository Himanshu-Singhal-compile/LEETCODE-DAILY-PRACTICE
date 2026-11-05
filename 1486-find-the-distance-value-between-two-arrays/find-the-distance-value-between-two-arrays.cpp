class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n = arr1.size() , m = arr2.size() ;
        int ans = 0 ; 
        for( int i = 0 ; i< n ; i++){
            int x = arr1[i] ;
            bool f = true ;  
            for( int j = 0 ; j < m  ; j++){
                if( abs( x  - arr2[j]) <= d ){
                    f = false ; 
                    break ; 
                }
            }
            if( f ) ans++ ; 
        }
        return ans ; 
    }
};