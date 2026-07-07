class Solution {
public:
    bool contains_cycle(int node,int parent,unordered_set<int>&visit,vector<vector<int>>&adj)
    {
        if(visit.count(node))
        return false;
        visit.insert(node);
        for(int nei:adj[node])
        {
            if(nei==parent)continue;
            if(!contains_cycle(nei,node,visit,adj))
            return false;
        }
        return true;


    }
    bool validTree(int n, vector<vector<int>>& edges) {
        //basically this undirected graph should contain cycle
        if(edges.size()>n-1)
        return false;
        vector<vector<int>>adj(n);
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        unordered_set<int>visit;
        if(!contains_cycle(0,-1,visit,adj))
        return false;
        return visit.size()==n;
    }
};
