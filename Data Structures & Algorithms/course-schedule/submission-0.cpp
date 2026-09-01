class Solution {
public:
bool contains_cycle(int i,vector<vector<int>>&adj,vector<bool>&visited)
    {
        visited[i]=true;
        for(auto it:adj[i])
        {
            if(visited[it])return true;
            if(contains_cycle(it,adj,visited))return true;
        }
        visited[i]=false;
        adj[i].clear();
        return false;
    }
bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>>adj(numCourses);
        for(auto it:pre)
        {
            adj[it[1]].push_back(it[0]);
        }
        vector<bool>visited(numCourses,false);
        for(int i=0;i<numCourses;i++)
        {
            if(contains_cycle(i,adj,visited))
            return false;
        }
        return true;
    }
};
