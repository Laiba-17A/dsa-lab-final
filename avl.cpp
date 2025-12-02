#include<iostream>
using namespace std;

class node {
public:
    int val;
    node *left;
    node *right;
    int height;

    node(int v) : val(v) {
        left = NULL;
        right = NULL;
        height = 1;
    }
};

class bst {

    node* root;

    int geth(node *r) {
        if (r == NULL) return 0;
        return r->height;
    }

    int getbal(node *n) {
        if (n == NULL) return 0;
        return geth(n->left) - geth(n->right);
    }

    void updateh(node *n) {
        n->height = 1 + max(geth(n->left), geth(n->right));
    }

    // Right rotation
    node* rr(node* y) {
        node* x = y->left;
        node* t2 = x->right;

        x->right = y;
        y->left = t2;

        updateh(y);
        updateh(x);

        return x;
    }

    // Left rotation
    node* rl(node* x) {
        node* y = x->right;
        node* t2 = y->left;

        y->left = x;
        x->right = t2;

        updateh(x);
        updateh(y);

        return y;
    }

    // Balance
    node* balnode(node* n) {
        int b = getbal(n);

        // LL
        if (b > 1 && getbal(n->left) >= 0)
            return rr(n);

        // LR
        if (b > 1 && getbal(n->left) < 0) {
            n->left = rl(n->left);
            return rr(n);
        }

        // RR
        if (b < -1 && getbal(n->right) <= 0)
            return rl(n);

        // RL
        if (b < -1 && getbal(n->right) > 0) {
            n->right = rr(n->right);
            return rl(n);
        }

        return n;
    }

    // Insertion
    node* insert(node* r, int v) {
        if (r == NULL)
            return new node(v);

        if (v < r->val)
            r->left = insert(r->left, v);
        else if (v > r->val)
            r->right = insert(r->right, v);
        else
            return r;

        updateh(r);
        return balnode(r);
    }

    // Find min on right subtree
    node* minval(node* r) {
        node* temp = r;
        while (temp->left != NULL)
            temp = temp->left;
        return temp;
    }

    // Remove
    node* removeNode(node* r, int v) {
        if (r == NULL)
            return NULL;

        if (v < r->val)
            r->left = removeNode(r->left, v);
        else if (v > r->val)
            r->right = removeNode(r->right, v);
        else {

            // CASE 1 + CASE 2: Node with one child or none
            if (r->left == NULL || r->right == NULL) {

                node* temp;

                // REPLACEMENT for ternary operator
                if (r->left != NULL)
                    temp = r->left;
                else
                    temp = r->right;

                // No child
                if (temp == NULL) {
                    temp = r;
                    r = NULL;
                }
                else {
                    // One child → copy child into r
                    r->val = temp->val;
                    r->left = temp->left;
                    r->right = temp->right;
                }

                delete temp;
            }
            else {
                // CASE 3: Two children
                node* temp = minval(r->right);
                r->val = temp->val;
                r->right = removeNode(r->right, temp->val);
            }
        }

        if (r == NULL) return NULL;

        updateh(r);
        return balnode(r);
    }

    void inorder(node *r) {
        if (r == NULL) return;
        inorder(r->left);
        cout << r->val << " ";
        inorder(r->right);
    }

public:

    bst() {
        root = NULL;
    }

    void insert(int v) {
        root = insert(root, v);
    }

    void remove(int v) {
        root = removeNode(root, v);
    }

    void display() {
        inorder(root);
    }
};

int main() {
    bst b;
    b.insert(20);
    b.insert(10);
    b.insert(30);
    b.insert(40);

    b.display();
    cout << endl;

    b.remove(20);

    b.display();
    cout << endl;

    return 0;
}