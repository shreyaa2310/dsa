#include<iostream>
using namespace std;

//The structure will have data, pointer to structure (a left one and a right one)
struct Node{
    int data;
    Node* left; 
    Node* right;

    Node(int d){
        data=d;
        left=right=nullptr;
    }
};

// Function to insert a node into the BST
Node* insert(Node *root,int val){
    if(root==nullptr){
        return new Node(val); 
        //new keyword returns a pointer to the variable which was created on the heap
        // int* ptr = new int(5); // Allocates space for int, stores 5, and returns address
    }

    Node* temp=root;
    while(true){
        if(val>temp->data){
            if(temp->right !=nullptr)
                temp=temp->right;
            else{   
                temp->right=new Node(val);
                break;
            }
        }
        else{
            if(temp->left !=nullptr)
                temp=temp->left;
            else{
                temp->left=new Node(val);
                break;
            }
        }
    }
    return root;
}

void printBST(Node *root){  //via inorder
    if (root==nullptr)
        return;
    
        printBST(root->left); 
        cout<<root->data<<" ";
        printBST(root->right);

        //calls function for its left child
        //if the called element has a left child, then it will be called
        //if not then it will access the data of that element and print it
        //after that it will check the right part of that element.
}

void searchBST(Node *root, int look){
    // if(root->data==look){
    //     cout<<"Element present in BST"<<endl;
    //     return;
    // }
    Node *temp=root;
    while(temp!=nullptr){
        if(look>temp->data)
            temp=temp->right;
        else if(look<temp->data)
            temp=temp->left;
        else{
            cout<<"Element found"<<endl;
            return;
        }
    }
    cout<<"Element not found"<<endl;
}

int main(){

    int n;
    int a;
    Node* root=nullptr;

    cout<<"Enter the number of nodes in your tree"<<endl;
    cin>>n;
    cout<<"Enter those elements"<<endl;
    for(int i=1;i<=n;i++){
        cin>>a;
        root=insert(root,a);
    }
    cout<<"Emter the element to be searched"<<endl;
    cin>>a;
    searchBST(root,a);
    printBST(root);
    return 0;
}
