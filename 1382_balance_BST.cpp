//https://leetcode.com/problems/balance-a-binary-search-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void Inorder(TreeNode *root,vector<int> &arr){
        if(root==NULL)
            return;
        Inorder(root->left,arr);
        arr.push_back(root->val);
        Inorder(root->right,arr);
    }
    TreeNode *buildTree(vector<int>arr,int start,int end){
        if(start>end)
            return NULL;
        int mid=(start+end)/2;
        TreeNode *root=new TreeNode(arr[mid]);
        root->left=buildTree(arr,start,mid-1);
        root->right=buildTree(arr,mid+1,end);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        Inorder(root,arr);
        TreeNode *new_root=buildTree(arr,0,arr.size()-1);
        return new_root;
    }
};