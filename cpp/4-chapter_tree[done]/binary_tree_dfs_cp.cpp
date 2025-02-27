#include "../utils/common.hpp"

vector<int> vec;

void preOrder(TreeNode *root) {
    if (root == nullptr)
        return;
    vec.push_back(root->val);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(TreeNode *root) {
    if (root == nullptr)
        return;
    inOrder(root->left);
    vec.push_back(root->val);
    inOrder(root->right);
}

void postOrder(TreeNode *root) {
    if (root == nullptr) 
        return;
    postOrder(root->left);
    postOrder(root->right);
    vec.push_back(root->val);
}

int main() {
    TreeNode *root = vectorToTree(vector<int>{1, 2, 3, 4, 5, 6, 7});
    cout << endl << "initialize binary tree:\n" << endl;
    printTree(root);

    vec.clear();
    preOrder(root);
    cout <<endl << "前序遍历结果 = ";
    printVector(vec);

    vec.clear();
    inOrder(root);
    cout << endl << "中序遍历结果 = ";
    printVector(vec);

    vec.clear();
    postOrder(root);
    cout << endl << "后序遍历结果 = ";
    printVector(vec);

    return 0; 
}