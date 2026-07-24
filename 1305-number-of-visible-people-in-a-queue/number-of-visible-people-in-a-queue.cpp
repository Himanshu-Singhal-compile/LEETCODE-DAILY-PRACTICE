class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int>st  ; 
        int n = heights.size();
        vector<int> ans ( n ) ; 
        ans[n-1] = 0 ;
        st.push(n-1) ; 
        for( int i = n-2 ; i>= 0; i--){
            int cnt = 0 ; 
            while( !st.empty() && heights[st.top()] < heights[i] ){
                cnt++ ; 
                st.pop() ; 
            }
            if( !st.empty()){
                cnt++ ; 
            }
            ans[i] = cnt ; 
            st.push( i ) ; 

        }
        return ans ; 
    }
};