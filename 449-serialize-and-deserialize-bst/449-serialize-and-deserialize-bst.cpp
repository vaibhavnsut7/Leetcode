/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    void dfsSerialize(TreeNode* root,string &ans){
        if(!root) {
            ans += " ";
            return;
        }
        ans += to_string(root->val) + " ";
        dfsSerialize(root->left,ans);
        dfsSerialize(root->right,ans);
    }
    string serialize(TreeNode* root) {
        string ans="";
        dfsSerialize(root,ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    
    TreeNode* dfsSerialize(string &data,int &i){
        string temp;
        while(data[i] != ' ') temp += data[i++];
        i++;
        if(temp == "") return nullptr;
        TreeNode* newNode = new TreeNode(stoi(temp));
        newNode->left = dfsSerialize(data,i);
        newNode->right = dfsSerialize(data,i);
        return newNode;
    }    
    TreeNode* deserialize(string data) {
        int i=0;
        return dfsSerialize(data,i);
        
 
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;