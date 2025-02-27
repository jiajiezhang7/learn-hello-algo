#include "../utils/common.hpp"

int main() {
    // 在堆上动态分配内存，创建TreeNode对象，n1等都是指向TreeNode结构体对象的指针
    TreeNode *n1 = new TreeNode(1);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n4 = new TreeNode(4);
    TreeNode *n5 = new TreeNode(5);

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->left = n5;
    cout << endl << "initialize binary tree\n" << endl;
    printTree(n1);


    // insert node P
    TreeNode *P = new TreeNode(0);
    n1->left = P;
    P->left = n2;
    cout << endl << "after insert node P:\n" << endl;
    printTree(n1);
    

    // delete node P
    n1->left = n2;
    delete P;
    cout << endl << "after delete node P:\n" << endl;
    printTree(n1);

    freeMemoryTree(n1);

    return 0;

}