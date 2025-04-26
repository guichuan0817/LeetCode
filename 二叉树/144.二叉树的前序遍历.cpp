#include<iostream>
#include<vector>

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
private:
    vector<int>res;
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == nullptr){
            return {};
        }
        traverse(root);
        return res;
    }

    void traverse(TreeNode* root){
        if(root==nullptr){
            return;
        }
        res.push_back(root->val);
        traverse(root->left);
        traverse(root->right);
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

// 辅助函数：打印vector
void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i != vec.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main() {
    TreeNode* root = createTestTree();
    Solution solution;
    vector<int>res = solution.preorderTraversal(root);
    cout << "Recursive preorder traversal: ";
    printVector(res);
    
    
    // 释放内存
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;
    
    return 0;
}