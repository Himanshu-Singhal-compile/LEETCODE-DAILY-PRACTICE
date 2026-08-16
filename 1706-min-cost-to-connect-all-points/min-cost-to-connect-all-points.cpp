class DSU{
private:
    vector<int> rank , parent ; 
public:
    DSU( int n ){
        rank.resize(n , 1 ) ; 
        parent.resize(n) ; 
        for( int i = 0 ; i< n ; i++){
            parent[i] = i ; 
        }
    }
    int findP( int node ){
        if( node == parent[node])return node ; 
        return parent[node] = findP( parent[node]) ; 
    }
    void unite( int u , int v ){
        int up = findP( u) , uv = findP( v ) ;
        if( up == uv )return ; 
        if( rank[up] > rank[uv]){
            parent[uv] = up ; 
        }
        else if ( rank[uv] > rank[up ]){
            parent[up] = uv ; 
        }
        else{
            parent[uv] = up ; 
            rank[up]++; 
        }
        return ; 
    }
    
};


class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size() ;
        vector<vector<int>> edges ;  
        for( int i = 0 ; i< n ; i++){
            for( int j = i+1 ; j< n ; j++){
                //nodes are i , j , 
                // find the cost , 
                int cost = abs(points[i][0] - points[j][0] )+ abs( points[j][1] - points[i][1] ) ; 
                edges.push_back( { cost , i , j }) ; 

            }
        }
        sort( edges.begin() , edges.end()) ; 
        int total = 0 ; 
        DSU ds( n ) ; 
        for( auto edge: edges){
            int val = edge[0] , u = edge[1] , v = edge[2] ;
            if( ds.findP( u ) != ds.findP( v )){
                ds.unite( u , v ) ; 
                total+= val ; 
            } 
        }
        return total; 
    }
};