#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

bool search(Node* root, int key) {
    if (!root) return false;
    if (root->data == key) return true;
    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

int height(Node* root) {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

void levelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* curr = q.front(); q.pop();
        cout << curr->data << " ";
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}

Node* findMin(Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (!root) return NULL;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

void mirror(Node* root) {
    if (!root) return;
    mirror(root->left);
    mirror(root->right);
    swap(root->left, root->right);
}

int main() {
    Node* root = NULL;
    int choice, val;
    while (true) {
        cout << "\n1.Insert 2.Inorder 3.Search 4.Height 5.LevelOrder 6.Delete 7.Mirror 8.Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                root = insert(root, val);
                break;
            case 2:
                inorder(root); cout << endl;
                break;
            case 3:
                cout << "Enter value to search: ";
                cin >> val;
                cout << (search(root, val) ? "Found" : "Not Found") << endl;
                break;
            case 4:
                cout << "Height: " << height(root) << endl;
                break;
            case 5:
                levelOrder(root); cout << endl;
                break;
            case 6:
                cout << "Enter value to delete: ";
                cin >> val;
                root = deleteNode(root, val);
                break;
            case 7:
                mirror(root);
                cout << "Tree mirrored.\n";
                break;
            case 8:
                return 0;
            default:
                cout << "Invalid option.\n";
        }
    }
}
