class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        vector<vector<int>> adj(n);

        for (auto &e : invocations) {
            adj[e[0]].push_back(e[1]);
        }

        vector<int> vis(n, 0);

        // DFS to mark suspicious methods
        function<void(int)> dfs = [&](int node) {
            vis[node] = 1;
            for (int nei : adj[node]) {
                if (!vis[nei])
                    dfs(nei);
            }
        };

        dfs(k);

        // Check if any outside method calls a suspicious one
        for (auto &e : invocations) {
            int u = e[0];
            int v = e[1];

            if (!vis[u] && vis[v]) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }

        // Remove suspicious methods
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!vis[i])
                ans.push_back(i);
        }

        return ans;
    }
};