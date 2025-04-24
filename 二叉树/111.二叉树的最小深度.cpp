#include<iostream>
#include<algorithm>
#include<queue>

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
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        queue<TreeNode*>q;
        q.push(root);
        // root 本身就是一层，depth 初始化为 1
        int depth = 1;

        while(!q.empty()){          
            int cap = q.size();
            // 遍历当前层的节点
            for(int i=0; i < cap;i++){
                TreeNode* cur = q.front();
                q.pop();
                // 判断是否到达叶子结点
                if(cur->left==nullptr && cur->right==nullptr){
                    return depth;
                }
                // 将下一层节点加入队列
                if(cur->left!=nullptr){
                    q.push(cur->left);
                }
                if(cur->right!=nullptr){
                    q.push(cur->right);
                }
            }
             // 这里增加步数
            depth++;
        }
        return depth;
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
    
    cout << "最大深度: " << solution.minDepth(root) << endl;
    
    // 释放内存
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;
    
    return 0;
}