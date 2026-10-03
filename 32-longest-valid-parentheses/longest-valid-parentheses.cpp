class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length() ; 
        
        int ans = 0 ; 
        int valid = 0 , l = 0 ; 

        for( int i = 0 ; i< n ; i++){
            if( valid < 0 ){
                valid = 0 ; 
                l = i ; 
            }

            if( s[i] =='(')valid++ ; 
            else valid -- ; 

            if( valid == 0 ) ans = max( ans , i-l +1) ; 
        }
        valid = 0 ; 
        l = n-1 ; 
        for( int i =n-1 ; i>=0  ; i--){
            if( valid < 0 ){
                valid = 0 ; 
                l = i ; 
            }

            if( s[i] ==')')valid++ ; 
            else valid -- ; 

            if( valid == 0 ) ans = max( ans , l-i+1) ; 
        }
        return ans ; 
    }
};