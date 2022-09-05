/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if (!root){
            return ans;
        }
        
        queue<Node *> q;
        q.push(root);
        while (!q.empty()){
            ans.push_back({});
            int size=q.size();
            for (int i=0;i<size;i++){
                Node *curr=q.front();
                q.pop();
                ans.back().push_back({curr->val});
                for (Node* child : curr->children) {
                    q.push(child);
                } 
            }
        }
        return ans;
        
    }
};