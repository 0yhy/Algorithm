#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *l, *r;
    Node(int d = 0, Node *l = nullptr, Node *r = nullptr) : data(d), l(l), r(r) {}
    void AddLeft(int d)
    {
        l = new Node(d);
    }
    void Addright(int d)
    {
        r = new Node(d);
    }
};

void preorder(Node *x)
{
    if (x == nullptr)
        return;
    else
    {
        cout << x->data << " ";
        preorder(x->l);
        preorder(x->r);
    }
}
void inorder(Node *x)
{
    if (x == nullptr)
        return;
    else
    {
        preorder(x->l);
        cout << x->data << " ";
        preorder(x->r);
    }
}
void postorder(Node *x)
{
    if (x == nullptr)
        return;
    else
    {
        preorder(x->l);
        preorder(x->r);
        cout << x->data << " ";
    }
}

Node *root;

int main()
{
    root = new Node(0);
    root->AddLeft(1);
    root->Addright(2);
    root->l->AddLeft(3);
    root->r->Addright(4);
    preorder(root);
    return 0;
}