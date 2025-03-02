#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

void inorderTraversal(Node* root){
    if (root) {
        inorderTraversal(root->left);
        cout<< root->val<< " ";
        inorderTraversal(root->right);
    }
}

void preorderTraversal(Node* root){
    if (root){
        cout<< root->val<< " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(Node* root){
    if (root){
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout<< root->val<< " ";
    }
}

Node* buildTree(vector<int> &arr, int idx=0){
    if (idx >= arr.size()) return NULL;

    Node* node = new Node(arr[idx]);
    node->left = buildTree(arr, 2*idx + 1);
    node->right = buildTree(arr, 2*idx + 2);

    return node;
}

int main(){
    int n; cin>> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    
    Node* root = buildTree(arr);
    
    cout<< "In-order traversal: ";
    inorderTraversal(root);
    cout<< '\n';

    cout<< "Pre-order traversal: ";
    preorderTraversal(root);
    cout<< '\n';

    cout << "Post-order traversal: ";
    postorderTraversal(root);
    cout<< '\n';

    return 0;
}

/*          (1)
           /   \
         (2)   (3)
         / \   / \
        4   5 6   7

7
1 2 3 4 5 6 7
*/