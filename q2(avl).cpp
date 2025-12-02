#include <iostream>
using namespace std;

class Node {
public:
    int price;
    Node* left;
    Node* right;
    int height;
    
    Node(int p) {
        price = p;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

// Count total nodes in a tree
int countNodes(Node* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// In-order traversal to fill array
void inorder(Node* root, int arr[], int& index) {
    if (root == NULL) return;
    
    inorder(root->left, arr, index);
    arr[index++] = root->price;
    inorder(root->right, arr, index);
}

// Count pairs in left subtree that sum to root's price
int countPairs(Node* root) {
    if (root == NULL || root->left == NULL) return 0;
    
    int target = root->price;
    
    // Count nodes in left subtree
    int size = countNodes(root->left);
    
    // Create array to store left subtree values
    int* arr = new int[size];
    int index = 0;
    
    // Fill array with left subtree values (sorted)
    inorder(root->left, arr, index);
    
    // Two-pointer technique
    int left = 0;
    int right = size - 1;
    int count = 0;
    
    while (left < right) {
        int sum = arr[left] + arr[right];
        
        if (sum == target) {
            count++;
            left++;
            right--;
        }
        else if (sum < target) {
            left++;
        }
        else {
            right--;
        }
    }
    
    delete[] arr;  // Free memory
    return count;
}

int main() {
    // Build example tree from paper
    //       6
    //      / \
    //     5   8
    //    / \   \
    //   2  4    9
    
    Node* root = new Node(6);
    root->left = new Node(5);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->right = new Node(9);
    
    int result = countPairs(root);
    cout << result << endl;
    
    return 0;
}