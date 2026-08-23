/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node,unordered_map<Node*,Node*>&oldtonew)
    {
        if(node == nullptr)return nullptr;
        if(oldtonew.count(node))
        return oldtonew[node];
        Node *clone_node=new Node(node->val);
        oldtonew[node]=clone_node;
        for(auto nei:node->neighbors)
        {
            clone_node->neighbors.push_back(dfs(nei,oldtonew));
        }
        return clone_node;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*>oldtonewNode;
        return dfs(node,oldtonewNode);
        
    }
};
