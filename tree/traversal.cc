#include <iostream>
#include <stack>
#include <queue>

#include "traversal.h"

using namespace std;


void preTraversal(Node *root)
{
    cout << "先序非递归 迭代遍历" << endl;
    stack<Node *> s;
    s.push(root);
    while (!s.empty())
    {
            Node* cur = s.top();
            s.pop();
            cout << cur->val << " ";
            if (cur->right != nullptr) s.push(cur->right); 
            if (cur->left != nullptr) s.push(cur->left);
    }
    cout << endl;
}

void postTraversal(Node *root)
{
    cout << "后序迭代遍历" << endl;
    stack<Node *> s;
    stack<Node*> s1;
    s.push(root);
    while (!s.empty()) 
    {
        Node* cur = s.top();
        s.pop();
        s1.push(cur);
        // cout << cur->val << " ";
        if (cur->left != nullptr) s.push(cur->left);
        if (cur->right != nullptr) s.push(cur->right);
    }
    while (!s1.empty())
    {
        Node* ptr = s1.top();
        s1.pop();
        cout << ptr->val << " ";
    }
    cout << endl;
}

void inTraversal(Node *cur)
{
    cout << "中序迭代遍历" << endl;
    stack<Node *> s;
    while (!s.empty() || cur != nullptr) 
    {
        if (cur != nullptr)   // 一开始是cur不空(root)，但cur会不断往左右孩子移动因此下一次继续循环要判断，如果是空的话压栈就不必要了
        {
            s.push(cur);
            cur = cur->left;
        }
        else
        {
            cur = s.top();
            s.pop();
            cout << cur->val << " ";
            cur = cur->right;
        }
    }
    cout << endl;
}



void level(Node *cur)
{
    cout << "level traversal" << endl;
    queue<Node *> q;
    q.push(cur);
    while (!q.empty())
    {
        Node * n = q.front();
        q.pop();
        cout << n->val << " ";
        if (n->left != nullptr) q.push(n->left);
        if (n->right != nullptr) q.push(n->right);

    }

}


// int main()
// {
//     Node* root = new Node(1);
//     root->left = new Node(2);
//     root->right = new Node(3);
//     root->left->left = new Node(4);
//     root->left->right = new Node(5);
//     root->right->left = new Node(6);
//     root->right->right = new Node(7);

//     preTraversal(root);
//     postTraversal(root);
//     inTraversal(root);
//     level(root);
// }
