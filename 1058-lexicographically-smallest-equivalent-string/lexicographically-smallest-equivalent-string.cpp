class DSU {
    vector<int> rank, parent, size;
    public:
    DSU(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = i;
        }
    }

    int findP(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findP(parent[node]);
    }

    void unite(int u, int v) {
        int ulp_u = findP(u);
        int ulp_v = findP(v);
        if (ulp_u == ulp_v) return;
        if (ulp_u > ulp_v) {
            parent[ulp_u] = ulp_v;
        }
        else if (ulp_v > ulp_u ) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
        }
        
    }
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DSU ds( 26 ) ; 
        string ans = "" ; 
        
        for( int i = 0 ; i< s1.length() ; i++){
            ds.unite(s1[i]-'a', s2[i] -'a' ) ; 
        }

        for( char ch :baseStr){
            ans+= ( ds.findP( ch-'a') +'a') ; 
        }
        return ans ; 

    }
};