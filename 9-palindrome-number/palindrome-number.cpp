class Solution {
public:
    bool isPalindrome(int x) {
        long long temp = x ; 
        long long rev = 0 ; 
        if( x < 0 ) return false ; 
        while( temp ){
            int digit = temp%10 ; 
            rev = rev*10 +digit ; 
            temp/=10 ; 
        }
        return x == rev ; 
    }
};