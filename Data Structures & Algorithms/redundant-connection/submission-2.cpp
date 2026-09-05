class Solution {
private:
    vector<vector<int>>adj;
    vector<bool>visit;
    int cyclestart;
    set<int>cycle_nodes;

public:
    bool contains_cycle(int node,int parent)
    {
        if(visit[node])
        {
            cyclestart=node;
            return true;
        }
        
        visit[node]=true;
        for(auto it:adj[node])
        {
            if(it == parent)continue;
            if(contains_cycle(it,node))
            {
                if(cyclestart!=-1)
                cycle_nodes.insert(node);
                if(cyclestart==node)
                cyclestart=-1;
                return true;

            }
        }
        return false;

    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //Build adjacency list
        int n=edges.size();
        adj.resize(n+1);
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        visit.resize(n+1,false);
        cyclestart=-1;
        contains_cycle(1,-1);
        for(int i=n-1;i>=0;i--)
        {
            if(cycle_nodes.count(edges[i][0])&&cycle_nodes.count(edges[i][1]))
            return vector<int>{edges[i][0],edges[i][1]};
        }




    }
};
