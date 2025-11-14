#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data=data;
        this->left=nullptr;
        this->right=nullptr;
    }
};

class BST{
public:
    Node* root;
    BST(){
        root=nullptr;
    }

    Node* createNode(int data){
        Node* newNode = new Node(data);
        return newNode;
    }

    int minValue(Node* root){
        Node* temp = root;
        int min;
        while(temp!=nullptr){
            min = temp->data;
            temp=temp->left;
        }
        return min;
    }

    Node* insertBST(Node* root, int data){
        if(root==nullptr){
            root = createNode(data);
            return root;
        }
        if(data < root->data){
            root->left = insertBST(root->left, data);
        }
        else{
            root->right = insertBST(root->right, data);
        }
        return root;
    }
    
   

    Node* deleteBST(Node* root, int data){
        if(root==nullptr){
            return root;
        }
        if(root->data < data){
            root->right = deleteBST(root->right, data);
        }
        else if(root->data > data){
            root->left = deleteBST(root->left,data);
        }
        else{
            //Node having 0 or 1 child

            // Case 1: only right child
            if(root->left == nullptr){
               Node* temp = root->right;
               delete root;
               return temp;
            }

            // Case 2: only left child
            else if(root->right==nullptr){
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // Node having both left & right child
            else{
                int minVal = minValue(root->right);
                root->data = minVal;
                root->right = deleteBST(root->right, minVal);
            }
            return root;
        }
    }

    void inOrder(Node* root){
        if(root==nullptr){
            return;
        }
        else
        {
            inOrder(root->left);
            cout<<root->data<<" ";
            inOrder(root->right);
        }
    }
};

int main(){
    BST b1;
    b1.root = b1.insertBST(b1.root, 50);
    b1.root = b1.insertBST(b1.root, 30);
    b1.root = b1.insertBST(b1.root, 100);
    b1.root = b1.insertBST(b1.root, 40);
    b1.inOrder(b1.root);
     cout<<endl;
    b1.root = b1.deleteBST(b1.root,30);
    b1.inOrder(b1.root);
    return 0;
}

