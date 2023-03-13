#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class Node
{
public:
    int val;
    Node* left;
    Node* right;
    Node(int x): val(x) {left = nullptr; right = nullptr;}
};


/* ======================== 用栈实现前中后序遍历（迭代，非递归）=================== */ 

/**
 * 先序遍历
 * 1）栈顶元素（root）弹出，
 * 2）有右孩压入，有左压入,先右再左保证弹栈先左在右
*/
void preTraversal(Node *root)
{
    cout << "preorderTraversal" << endl;
    if (root != nullptr) 
    {
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
}

/**
 * 后序遍历   左右头
 * 用栈来实现    先序时先压右再压左，弹出是先左再右；那么后序反着，可以先压入左再压入右弹出右再弹出左   造成头右左
 * 这个结果和期待的后序左右头正好相反，所以可以把这个结果放在新的栈里，那么再弹新栈就能达到目的
*/
void postTraversal(Node *root)
{
    cout << "post order traversal" << endl;
    if (root != nullptr)
    {
        stack<Node *> s1;
        stack<Node *> s2;
        s1.push(root);
        while (!s1.empty())
        {
            Node * cur = s1.top();
            s1.pop();
            s2.push(cur);
            if (cur->left != nullptr) s1.push(cur->left);
            if (cur->right != nullptr) s1.push(cur->right);
        }
        while (!s2.empty())
        {
            Node * cur = s2.top();
            s2.pop();
            cout << cur->val << " ";
        }
    }
}

/**
 * 中序遍历
 * 二叉树可以通过左子树的不断切割而划分干净
 * 把左子树不断压入栈，直到没有孩子，而后弹栈，弹栈同时进入右子树重复划分左子树的动作
 * 通过这种方式能够分解掉整棵树
 * 
*/
void inTraversal(Node *cur)
{
    cout << "inTraversal" << endl;
    if (cur != nullptr)
    {
        stack<Node *> s;
        while (!s.empty() || cur != nullptr)     /*为了统筹安排一开始把头结点放入而此时栈空，添加一个cur != nullptr也能进循环的条件*/
        {
            if (cur != nullptr) 
            {
                s.push(cur);
                cur = cur->left;
            }     
            else {
                cur = s.top();
                s.pop();
                cout << cur->val << " ";
                cur = cur->right;
            }
        }
    }
}



/* ============================  按层 bfs   遍历  ================================== */
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


int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    preTraversal(root);
    postTraversal(root);
    inTraversal(root);
    level(root);
}
