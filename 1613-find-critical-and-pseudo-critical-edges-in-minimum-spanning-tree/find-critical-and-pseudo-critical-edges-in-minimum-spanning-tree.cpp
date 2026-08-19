typedef long long ll;

struct DSU {
    vector<int> par, rnk;
    DSU(int n) : par(n), rnk(n, 0) { iota(par.begin(), par.end(), 0); }
    int find(int x) { return par[x] == x ? x : par[x] = find(par[x]); }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y)
            return false;
        if (rnk[x] < rnk[y])
            swap(x, y);
        par[y] = x;
        if (rnk[x] == rnk[y])
            rnk[x]++;
        return true;
    }
};

class Solution {
public:
    vector<vector<int>>
    findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        vector<vector<int>> ans(2);
        vector<vector<int>> final;

        for (int i = 0; i < edges.size(); i++) {
            auto edge = edges[i];
            int u = edge[0], v = edge[1], w = edge[2];
            final.push_back({w, u, v, i});
        }
        sort(final.begin(), final.end());

        // find the MST,
        DSU dsu(n);
        ll mst_weight = 0;
        for (auto& p : final) {
            int w = p[0], u = p[1], v = p[2];
            if (dsu.unite(u, v)) {
                mst_weight += w;
            }
        }

        for (int r_idx = 0; r_idx < final.size(); r_idx++) {
            DSU ds(n);
            ll r_mst = 0;
            int cnt = 0;
            for (int i = 0; i < m; i++) {
                if (i == r_idx)
                    continue;
                int w = final[i][0], u = final[i][1], v = final[i][2];
                if (ds.unite(u, v)) {
                    r_mst += w;
                    cnt++;
                }
            }
            bool critical = (cnt != n - 1) || (r_mst > mst_weight);
            if (critical) {
                ans[0].push_back(final[r_idx][3]);
                continue;
            }
            DSU ds2(n);
            ll f_mst = final[r_idx][0];
            ds2.unite(final[r_idx][1], final[r_idx][2]);
            for (int i = 0; i < m; i++) {
                if (i == r_idx)
                    continue;
                int w = final[i][0], u = final[i][1], v = final[i][2];
                if (ds2.unite(u, v))
                    f_mst += w;
            }
            if (f_mst == mst_weight) {
                ans[1].push_back(final[r_idx][3]);
            }
        }

        return ans;
    }
};