#include<iostream>
#include<queue>

using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class CBTInserter {
private:
    queue<TreeNode*>q;
    TreeNode* root;
public:
    CBTInserter(TreeNode* root) {
        this->root = root;
        queue<TreeNode*> temp;
        temp.push(root);

        while(!temp.empty()){
            TreeNode* cur = temp.front();
            temp.pop();

            if(cur->left!=nullptr){
                temp.push(cur->left);
            }
            if(cur->right!=nullptr){
                temp.push(cur->right);
            }
            if(cur->left==nullptr||cur->right==nullptr){
                q.push(cur);
            }
        } 
    }
    
    int insert(int val) {
        TreeNode* node = new TreeNode(val);
        TreeNode* cur = q.front();
        if(cur->left==nullptr){
            cur->left = node;
        }
        if(cur->right==nullptr){
            cur->right = node;
            q.pop();
        }
        q.push(node);
        return cur->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

// 层序遍历打印树
void printTree(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = q.front();
            q.pop();
            cout << node->val << " ";
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << endl;
    }
}

int main() {
    // 构建初始完全二叉树：
    //        1
    //       / \
    //      2   3
    //     /
    //    4
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    cout << "初始树结构：" << endl;
    printTree(root);

    // 创建 CBTInserter
    CBTInserter inserter(root);

    // 插入新节点
    cout << "\n插入 5，返回父节点值: " << inserter.insert(5) << endl;
    cout << "插入 6，返回父节点值: " << inserter.insert(6) << endl;
    cout << "插入 7，返回父节点值: " << inserter.insert(7) << endl;

    // 获取插入后的完整树
    TreeNode* finalRoot = inserter.get_root();
    cout << "\n最终树结构：" << endl;
    printTree(finalRoot);
    return 0;
}