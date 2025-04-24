#include<iostream>
#include<algorithm>

using namespace std;

 //Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
    int res = 0;
    // 记录遍历到的节点的深度
    int depth = 0;
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        traverse(root);
        return res;
        
    }
    // 遍历二叉树
    void traverse(TreeNode* root) {
        if(root == nullptr){
            return;
        }
        // 前序遍历位置（进入节点）增加深度
        depth++;
        // 遍历到叶子节点时记录最大深度
        if(root->left == nullptr && root->right == nullptr){
            res = max(res, depth);
        }
        traverse(root->left);
        traverse(root->right);
        // 后序遍历位置（离开节点）减少深度
        depth--;
    }
};

TreeNode* createTestTree() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    return root;
}

int main() {
    TreeNode* root = createTestTree();
    Solution solution;
    
    cout << "最大深度: " << solution.maxDepth(root) << endl;
    
    // 释放内存
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;
    
    return 0;
}
