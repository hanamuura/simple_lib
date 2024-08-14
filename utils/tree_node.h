namespace utils {
    class TreeNode;
}

class TreeNode {
public:
    TreeNode(int value);
    TreeNode(int value, TreeNode *left);
    TreeNode(int value, TreeNode *left, TreeNode *right);
    ~TreeNode();
    static void print(TreeNode *root);
    TreeNode *right;
    TreeNode *left;
    int value;
};