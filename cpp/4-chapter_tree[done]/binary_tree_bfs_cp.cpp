#include "../utils/common.hpp"

vector<int> levelOrder(TreeNode *root) {
    // 队列用于存储待访问的节点
    queue<TreeNode *> queue;
    // 将根节点加入队列
    queue.push(root);

    vector<int> vec;
    while(!queue.empty()) {
        // 取出队列中的第一个节点
        TreeNode *node = queue.front();
        // 将该节点从队列中删除
        queue.pop();
        // 访问该节点，将其值存入结果中
        vec.push_back(node->val);

        // 如果该节点存在左子节点，则将其加入队列
        if (node->left != nullptr)
            queue.push(node->left);
        // 同理，右子节点
        if (node->right != nullptr)
            queue.push(node->right);
    }
    return vec;
}

int main() {
    TreeNode *root = vectorToTree(vector<int>{1, 2, 3, 4, 5, 6, 7});
    cout << endl << "initialize binary tree" << endl;
    printTree(root);

    vector<int> vec = levelOrder(root);
    cout << endl << "层序遍历的打印结果 = ";
    printVector(vec);

    return 0; 
}