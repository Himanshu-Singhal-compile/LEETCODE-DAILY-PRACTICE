class Solution {
public:
    bool checkValidString(string s) {
        // we are using a range that is useful 
        int mini =0 , maxi =0 ; 
        for( char c : s ){
            if( c == '('){
                mini++ ; 
                maxi++ ; 
            }
            else if( c ==')'){
                mini-- ; 
                maxi-- ; 
            }
            else{
                mini = mini -1  ;
                maxi = maxi+1  ; 
            }
            if( mini == -1 ) mini = 0  ;
            if( maxi < 0 ) return false ; 
        }
        return mini == 0 ; 
        
        
    }
};