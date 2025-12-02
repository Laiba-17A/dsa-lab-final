#include<iostream>
using namespace std;

class node {
public:
    int val;
    node *left;
    node *right;

    node(int v) : val(v) {
        left = nullptr;
        right = nullptr;
    }
};

class bst {
public:
    node *root;

    bst() {
        root = nullptr;
    }

    void insert(int v) {
        node *newn = new node(v);
        if (root == nullptr) {
            root = newn;
            return;
        }

        node *temp = root;
        while (temp != nullptr) {

            if (newn->val == temp->val) {
                delete newn;
                return;
            }

            else if (newn->val < temp->val && temp->left == nullptr) {
                temp->left = newn;
                break;
            }
            else if (newn->val < temp->val) {
                temp = temp->left;
            }

            else if (newn->val > temp->val && temp->right == nullptr) {
                temp->right = newn;
                break;
            }
            else {
                temp = temp->right;
            }
        }
    }

    node* minval(node *r) {
        node* temp = r;
        while (temp->left != nullptr)
            temp = temp->left;
        return temp;
    }

    node* remove(node *r, int v) {

        if (r == nullptr)
            return nullptr;

        if (v < r->val) {
            r->left = remove(r->left, v);
        }
        else if (v > r->val) {
            r->right = remove(r->right, v);   // ? FIXED
        }
        else {
            // CASE 1: Only right child or no child
            if (r->left == nullptr) {
                node *temp = r->right;
                delete r;
                return temp;
            }
            // CASE 2: Only left child
            else if (r->right == nullptr) {
                node *temp = r->left;
                delete r;
                return temp;
            }
            // CASE 3: Two children
            else {
                node *temp = minval(r->right);
                r->val = temp->val;
                r->right = remove(r->right, temp->val);
            }
        }

        return r;   // ? REQUIRED
    }

    node* search(int v) {
        node* temp = root;
        while (temp != nullptr) {
            if (v == temp->val) {
                cout << "value found" << endl;
                return temp;
            }
            else if (v > temp->val)
                temp = temp->right;
            else
                temp = temp->left;
        }
        cout << "value not found" << endl;
        return nullptr;
    }

    void inorder(node *r) {
        if (r == nullptr) return;
        inorder(r->left);
        cout << r->val << " ";
        inorder(r->right);
    }
};

int main() {
    bst b;
    b.insert(20);
    b.insert(10);
    b.insert(30);
    b.insert(40);

    b.inorder(b.root);

    b.root = b.remove(b.root, 20);   // ? FIXED CALL

    cout << endl;
    b.inorder(b.root);
    cout << endl;

    b.search(40);
    b.search(50);

    return 0;
}
