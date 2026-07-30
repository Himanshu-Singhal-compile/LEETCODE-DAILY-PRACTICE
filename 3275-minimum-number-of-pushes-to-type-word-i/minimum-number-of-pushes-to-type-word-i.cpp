class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size() ; 
        if( n>=1 && n<= 8 )return n ; 
        if( n < 16 && n> 8 )return 8+ ( n%8 )*2 ; 
        if( n < 24 && n>= 16)return 24+ ( n%8)*3 ; 
        else return 48 + (n%8)*4 ; 
    }
};