class Solution {
public:

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>>adj(numCourses);
    vector<int>indegree(numCourses,0);
    queue<int>q;
    vector<int>courses;
    int finish=0;
    for(auto pre:prerequisites)
    {
        indegree[pre[0]]++;
        adj[pre[1]].push_back(pre[0]);
    }
    for(int i=0;i<numCourses;i++)
    {
        if(indegree[i]==0)
        q.push(i);
    }
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        courses.push_back(node);
        finish++;
        for(auto it:adj[node])
        {
            indegree[it]--;
            if(indegree[it]==0)
            q.push(it);
        }
    }
    return finish==numCourses?courses:vector<int>{};

        
    }
};
