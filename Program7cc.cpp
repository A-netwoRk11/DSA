#include <iostream>
#include <vector>

class TreeNode 
{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    std::vector<TreeNode*> children;
    TreeNode(int val)
    {
        this->val = val;
        this->left = this->right = nullptr;
    }
};

TreeNode* convert(TreeNode* root)
{
    if (!root) 
    {
        return nullptr;
    }
    if (root->children.size() == 0)
    {
        return root;
    }
    if (root->children.size() == 1)
    {
        root->left = convert(root->children[0]);
        return root;
    }
    root->left = convert(root->children[0]);
    root->right = convert(root->children[1]);
    for (int i = 2; i < root->children.size(); i++)
    {
        TreeNode* rightTreeRoot = root->right;
        while (rightTreeRoot->left != nullptr)
        {
        rightTreeRoot = rightTreeRoot->left;
        }   
        rightTreeRoot->left = convert(root->children[i]);
    }
    return root;
}

void printTree(TreeNode* root)
{
    if (!root)
    {
        return;
    }
    std::cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}
int main()
{
    TreeNode* root = new TreeNode(1);
    root->children.push_back(new TreeNode(2));
    root->children.push_back(new TreeNode(3));
    root->children.push_back(new TreeNode(4));
    root->children.push_back(new TreeNode(5));
    root->children[0]->children.push_back(new TreeNode(6));
    root->children[0]->children.push_back(new TreeNode(7));
    root->children[3]->children.push_back(new TreeNode(8));
    root->children[3]->children.push_back(new TreeNode(9));
    TreeNode* binaryTreeRoot = convert(root);
    // Output: 1 2 3 4 5 6 7 8 9
    printTree(binaryTreeRoot);
}