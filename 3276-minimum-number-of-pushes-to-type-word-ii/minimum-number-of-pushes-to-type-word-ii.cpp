class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size() ; 
        vector<int> freq( 26, 0  ) ; 
        for( char c : word ){
            freq[c-'a']++ ; 
        }
        sort( freq.rbegin() , freq.rend()) ; 
        for( int i = 0 ; i< 26 ;  i++)cout<< freq[i] << " " ; 
        cout<< endl ; 
        int ans = 0 ; 
        int cnt = 0 ; 
        int mat =1 ; 
        for( int i = 0 ; i< 26 && freq[i]!= 0 ; i++){
            ans += (mat*freq[i])  ; 
            cnt++ ; 
            if( cnt >=8 ){
                mat++ ; 
                cnt%=8 ; 
            }
        }
        return ans ; 
    }
};