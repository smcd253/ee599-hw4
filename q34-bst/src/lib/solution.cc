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

TreeNode* erase_helper(TreeNode*& node, int key)
{
    if(node != nullptr)
    {
        if(key < node->val)
        {
            node->left = erase_helper(node->left, key);
        }
        else if(key > node->val)
        {
            node->right = erase_helper(node->right, key);
        }
        else
        {
            if(node->left == nullptr)
            {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }
            else
            {
                TreeNode* temp = get_min(node->right);
                node->val = temp->val;
                node->right = erase_helper(node->right, temp->val);
            }
            
        }
    }
    return node;
}

// Runtime = &theta;(2*H), where H &isin;[log(n), n] --> O(n)
bool BST::erase(int key)
{
    bool result = true;
    result = this->find(key);
    if(result)
    {
        this->root_ = erase_helper(this->root_, key);
    }
    return result;
}

// builds a new tree every time a key is added
TreeNode* BST::insert(TreeNode*& node, int key)
{
    if (node == nullptr) 
    {
        node = new TreeNode(key);
    } 
    else if (key < node->val) 
    {
        node->left = insert(node->left, key);
    } 
    else if (key > node->val) 
    {
        node->right = insert(node->right, key);
    }
    // else key already in BST
    return node;
}

// Runtime = &theta;(2*H), where H &isin;[log(n), n] --> O(n)
void BST::push(int key)
{
    if(!this->find(key))
    {
        this->root_ = insert(this->root_, key); 
    }
    else
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

void build_queue(TreeNode* node, std::queue<TreeNode*>& q_nodes, int level, int current_level)
{
    if(current_level != level)
    {
        if(node->left != nullptr)
        {
            build_queue(node->left, q_nodes, level, current_level++);
        }
        if(node->right != nullptr)
        {   
            build_queue(node->right, q_nodes, level, current_level++);
        }
    }
    if(node != nullptr)
    {
        q_nodes.push(node);
    }
}

// void BST::print_by_level()
// {
//     int level = 0;
//     std::queue<TreeNode*> q;
//     size_t old_q_size = -1;
//     while(old_q_size != q.size())
//     {   
//         old_q_size = q.size();
//         build_queue(this->root_, q, level, 0);
//         level++;
//     }

//     while(q.size() > 0)
//     {
//         printf("%d ", q.front()->val);
//         q.pop();
//     }
//     printf("\n");
// }