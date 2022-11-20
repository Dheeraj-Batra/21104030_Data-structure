// Name = Dheeraj Batra 
// SID = 21104030
// Branch = EE 

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

// function to store the preorder of BST in vector
void preorder(Node* root,vector<int>&ans) {
        if(root==NULL) return;
        ans.push_back(root->data);
        preorder(root->left,ans);
        preorder(root->right,ans);
    }

// IMPLEMENTATION ===
// The idea is to find the middle element of the array and make it the root of the tree,then perform the same operation on the left subarray for the root’s left child and the same operation on the right subarray for the root’s right child.

// function to convert sorted array into BST
Node* SortedArraytoBST(int *nums,int l,int h){
        if(l>h) return NULL;
        int mid=(l+h)/2;
        Node* root=new Node(nums[mid]);
        root->left=SortedArraytoBST(nums,l,mid-1);
        root->right=SortedArraytoBST(nums,mid+1,h);
        return root;
    }



//function to find minimum value node in the subtree rooted at curr
Node* getMinimumKey(Node* curr){
    while (curr->left != NULL) curr = curr->left;
    return curr;
}
//function to traverse the tree and search for the key
void searchKey(Node* &curr, int key, Node* &parent){
    while (curr != NULL && curr->data != key){
        parent = curr;
        if (key < curr->data) curr = curr->left;
        else curr = curr->right;
    }
}
// Function to delete a node from a BST
void deleteNode(Node*& root, int key){
    Node* parent = NULL;
    Node* curr = root;
    // search key in the BST and set its parent pointer
    searchKey(curr, key, parent);
    // return if the key is not found in the tree
    if (curr == NULL) return;
 
    // Case 1: node to be deleted has no children
    if (curr->left == NULL && curr->right == NULL){
        if (curr != root){
            if (parent->left == curr)  parent->left = NULL;
            else  parent->right = NULL;
        }
        else  root = NULL;
    }
 
    // Case 2: node to be deleted has two children
    else if (curr->left && curr->right){
        Node* successor = getMinimumKey(curr->right);
        int val = successor->data;
        deleteNode(root, successor->data);
        curr->data = val;
    }

    // Case 3: node to be deleted has only one child
    else {
        // choose a child node
        Node* child = (curr->left)? curr->left: curr->right;
        if (curr != root){
            if (curr == parent->left)  parent->left = child;
            else parent->right = child;
        }
        else  root = child;
    }
}


// function to remove an element x from arr[] and returns new size after removal
int deleteElement(int arr[], int n, int x){
int i;
for (i=0; i<n; i++)
    if (arr[i] == x) break;
if (i < n){
    // reduce size of array and move all elements on space ahead
    n = n - 1;
    for (int j=i; j<n; j++) arr[j] = arr[j+1];
}
return n;
}

// space complexity of both structures
// 1) deleting an element fom an array space complexity is O(1)    
// 2) deleting an node from BST The space complexity of a binary search tree is O(n) in both the average and the worst cases.


int main(){
    // pre requisite is that input array should be sorted
    int arr[]={1,2,3,4,5,6,7};
    int n = sizeof(arr) / sizeof(arr[0]);
//   4
// /   \
// 2    6
// / \ / \
// 1 3 5 7

    // function call to convert array to bst and return root of BST
    Node* root=SortedArraytoBST(arr,0,n-1);

    // function to store the preorder of BST in vector named as preorder_vec
    vector<int>preorder_vec;
    preorder(root,preorder_vec);

    // function call to delete 5 from BST
    deleteNode(root,5);


    int x = 5;
    // Delete x from arr[]
    n = deleteElement(arr, n, x);
}
