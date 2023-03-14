#include <iostream>
#include <vector>
#include <string>

#include "tree.h"

using namespace std;

// 用队列这种数据结构可以直接弹出，不需要记录vector的index，更方便，用队列写一版序列化反序列化


// 递归
void preSerial(Node* root, vector<string>& res)
{
    if (root == nullptr) 
    {
        res.push_back("#");
        return;
    }
    res.push_back(to_string(root->val));   // char可存int
    preSerial(root->left, res);
    preSerial(root->right, res);
}

vector<string> serialize(Node* node)
{
    vector<string> ans;
    preSerial(node, ans);
    return ans;
}

// 反序列化递归
Node* preRecon(vector<string>& data, int& index)
{
    if (index >= data.size() || data[index] == "#")
    {
        index++;
        return nullptr;
    }
    Node* node = new Node(stoi(data[index++]));
    node->left = preRecon(data, index);
    node->right = preRecon(data, index);
    return node; 
}

Node* deserialize(vector<string>& data)
{
    int index = 0;
    return preRecon(data, index);
}


// 比较两棵树是否相同
bool isSameTree(Node* p, Node* q)
{
    if (p == nullptr && q == nullptr) return true;
    if (p == nullptr || q == nullptr) return false;
    if (p->val != q->val) return false;
    return isSameTree(p->left, p->left) && isSameTree(p->right, p->right); 
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

    // preTraversal(root);
    // postTraversal(root);
    // inTraversal(root);
    // level(root);

    vector<string> vec = serialize(root);
    cout << "序列化结果" << endl;
    for (vector<string>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        cout << *it;
    }
    cout << endl;

    cout << "反序列化：" << endl;
    Node* newNode = deserialize(vec);
    if (isSameTree(newNode, root)) cout << "Same" << endl;


}


