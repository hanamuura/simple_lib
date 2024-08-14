#include "tree_node.h"
#include <iostream>
#include <queue>

TreeNode::TreeNode(int value): value(value), left(nullptr), right(nullptr) {};
TreeNode::TreeNode(int value, TreeNode *left): value(value), left(left){};
TreeNode::TreeNode(int value, TreeNode *left, TreeNode *right): value(value), left(left), right(right){};


void TreeNode::print(TreeNode *root){
    if (root == nullptr) {
        return;
    }

    // Создаем очередь для хранения узлов
    std::queue<TreeNode*> nodeQueue;

    // Начинаем с корневого узла
    nodeQueue.push(root);

    while (!nodeQueue.empty()) {
        // Извлекаем узел из очереди
        TreeNode* current = nodeQueue.front();
        nodeQueue.pop();

        // Обрабатываем узел (выводим его значение)
        std::cout << current->value << "\n";

        // Добавляем левый дочерний узел в очередь, если он существует
        if (current->left != nullptr) {
            nodeQueue.push(current->left);
        }

        // Добавляем правый дочерний узел в очередь, если он существует
        if (current->right != nullptr) {
            nodeQueue.push(current->right);
        }
    }
    std::cout << std::endl;
}