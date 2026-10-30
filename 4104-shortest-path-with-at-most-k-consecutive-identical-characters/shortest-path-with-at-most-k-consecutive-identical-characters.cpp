class Solution {
public:
    int shortestPath(int n, vector<vector<int >>& edges, string labels, int k) {

        using T = tuple<long long, int,  int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        
        vector<vector<long long>> dist(n, vector<long long>(k + 2, LLONG_MAX));

        vector<vector<pair<long long , long long>>> adj( n ) ; 
        for( auto edge : edges ){
            adj[edge[0]].push_back( { edge[1] , edge[2] }) ; 
        }
        if (1 <= k) {
            dist[0][1] = 0;
            pq.push({0, 0, 1});
        }

        
        while( !pq.empty()){
             auto [weight, node, count] = pq.top(); pq.pop(); 
            
            if( count > k  )continue ; 
            if (weight > dist[node][count]) continue;

            if( node == n-1 ){
                return (int)weight ; 
            } 
            
            for( auto ajw : adj[node]){
                long long w = ajw.second , adjnode = ajw.first   ; 
                int new_cnt = (labels[adjnode] == labels[node]) ? count + 1 : 1;
                if (new_cnt > k) continue; // violates constraint
                
                long long new_w = weight + w;
                if (new_w < dist[adjnode][new_cnt]) {
                    dist[adjnode][new_cnt] = new_w;
                    pq.push({new_w, adjnode, new_cnt});
                }
            }
        }
        return -1 ; 
        
        
    }
};