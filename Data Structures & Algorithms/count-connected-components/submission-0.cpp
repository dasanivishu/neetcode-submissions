class Solution {
public:
    void dfs(vector<vector<int>>&adj,int i,vector<int>&visited)
    {
        visited[i]=1;
        for(auto it:adj[i])
        {
            if(!visited[it])
            {
                dfs(adj,it,visited);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        int components=0;
        vector<int>visited(n,0);
        vector<vector<int>>adj(n);
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(adj,i,visited);
                components++;
            }
        }
        return components;

    }
};
