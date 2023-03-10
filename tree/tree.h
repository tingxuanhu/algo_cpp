#ifndef TREENODE
#define TREENODE

struct Node
{
    int val;
    Node* left;
    Node* right;
    Node(int x): val(x), left(nullptr), right(nullptr) {}
};
#endif

/*
结构体和类的定义通常是在头文件中进行的，而不需要在源文件中进行定义。
这是因为结构体和类的定义通常包含了成员变量和成员函数的声明和定义，
而在C++中，成员函数的定义通常需要放在类的定义之内。
将结构体和类的定义放在头文件中可以使得多个源文件可以共享这个结构体或类的定义，
并且可以在不同的源文件中实现这个结构体或类的成员函数。

如果结构体或类的实现比较复杂，需要包含大量的源代码，
可以将它们的定义放在头文件中，而将实现放在源文件中。
这种情况下，我们通常会将头文件分为两部分：头文件（.h）和实现文件（.cpp）。
头文件中包含结构体或类的定义和成员函数的声明，而实现文件中包含成员函数的实现。
总之，结构体和类的定义通常是放在头文件中进行的，而不需要在源文件中进行定义。
如果结构体或类的实现比较复杂，可以将实现放在源文件中，而将头文件分为头文件和实现文件两部分。
*/