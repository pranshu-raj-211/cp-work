#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node *parent;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
        this->parent = NULL;
    }
};

node *build_tree(node *root)
{
    cout << "Enter data" << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
        return NULL;

    cout << "Enter data for inserting into left of " << data << endl;
    root->left = build_tree(root->left);
    cout << "Enter data for inserting into right of " << data << endl;
    root->right = build_tree(root->right);
    return root;
}

void level_order_traversal(node *root)
{
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        cout << temp->data << " ";
        q.pop();

        if (temp == NULL) // older level traversed completely
        {
            cout << endl;
            if (!q.empty()) // child nodes present
                q.push(NULL);
        }

        else
        {
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    node *root = NULL;

    // create tree
    root = build_tree(root);

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    // level order traversal to show tree;
    level_order_traversal(root);

    return 0;
}