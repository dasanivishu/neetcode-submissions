class Solution {
public:
    bool contains_cycle(int node,int parent,vector<vector<int>>&adj,unordered_set<int>&visit)
    {
        if(visit.count(node)>0)
        return true;
        visit.insert(node);
        for(auto it:adj[node])
        {
            if(it==parent)continue;
           
            if(contains_cycle(it,node,adj,visit))
            return true;
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        //three conditions edges can be max n-1
        //no cycle and graph should be connected 
        if(edges.size()>n-1)return false;
        vector<vector<int>>adj(n);
        unordered_set<int>visit;
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        if(contains_cycle(0,-1,adj,visit))
        return false;
        return visit.size()==n;
        
    }
};
