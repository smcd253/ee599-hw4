#include "solution.h"

 

TreeNode* find_helper(TreeNode*& node, int key)
{
    TreeNode* result = node;
    if (node != nullptr) 
    {
        if (key < node->val) 
        {
            result = find_helper(node->left, key);
        } 
        else if (key > node->val) 
        {
            result = find_helper(node->right, key);
        }
    }
    return result;
}

// Runtime = &theta;(H), where H &isin;[log(n), n] --> O(n)
bool BST::find(int key)
{   
    bool result = true;
    TreeNode* node = find_helper(this->root_, key);
    if(node == nullptr)
    {
        result = false;
    }
    return result;
}

TreeNode* get_min(TreeNode*& node)
{
    TreeNode* result = node;
    while(result->left != nullptr)
    {
        result = result->left;
    }
    return result;
}

bool BST::erase(int key)
{
    bool result = true;
    TreeNode* node = find_helper(this->root_, key);
    if(node != nullptr)
    {
        printf("node->val = %d\n", node->val);
        // if one or no children
        if (node->left == nullptr && node->right == nullptr)
        {
            delete node;
        }
        else if(node->left == nullptr) 
        {
            node->val = node->right->val;
            delete node->right;
        }
        else if(node->right == nullptr) 
        {
            node->val = node->left->val;
            delete node->left;
        }
        else 
        {
            TreeNode* temp = get_min(node->right);
            node->val = temp->val;
            delete temp;
        }
    }
    else
    {
        result = false;
    }
    return result;
}

bool BST::insert(TreeNode*& node, int key)
{
    bool result = true;
    if (node == nullptr) 
    {
        node = new TreeNode(key);
    } 
    else if (key < node->val) 
    {
        insert(node->left, key);
        printf("node->left->val = %d\n", node->left->val);
    } 
    else if (key > node->val) 
    {
        insert(node->right, key);
        printf("node->right->val = %d\n", node->right->val);
    }
    else // key == node->val
    {
        result = false;
    }
    return result;
}

// Runtime = &theta;(H), where H &isin;[log(n), n] --> O(n)
void BST::push(int key)
{
    if (!insert(this->root_, key))
    {
        printf("BST already contains key %d.\n", key);
    }
}

void BST::destroy(TreeNode*& node)
{
    if (node != nullptr)
    {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

void in_order(TreeNode* node)
{
    if (node != nullptr)
    {
        in_order(node->left);
        printf("%d ", node->val);
        in_order(node->right);
    }
}

void BST::print_in_order()
{
    in_order(this->root_);
    printf("\n");
}
