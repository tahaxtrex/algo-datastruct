#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int v) {
        value = v;
        left = right = nullptr;
    }
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int value) {
        if (node == nullptr)
            return new Node(value);
        if (value < node->value)
            node->left = insert(node->left, value);
        else{
            node->right = insert(node->right, value);
        return node;
        }
    }

    bool search(Node* node, int value) {
        if (node == nullptr) return false;
        if (node->value == value) return true;
        else if (value < node->value)
            return search(node->left, value);
        else
            return search(node->right, value);
    }

    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->value << " ";
        inorder(node->right);
    }

    Node remove(Node* node, int value){
        if (node == nullptr){cout<<"there are no node in this bst"<<endl;}
        else if (value < node->value){remove(node->left, value);}
        else if (value > node->value){remove(node->right, value);}
        else if (value == node->value){
            if(node->left == nullptr && node->right == nullptr){
                Node *temp = node;
                delete node;
                return *temp;
            }
            else if (node ->left == nullptr)
            {
                
            }
            

        }
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    bool search(int value) {
        return search(root, value);
    }

    void inorder() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    BST tree;
    int values[] = {10, 5, 15, 3, 7, 12, 18};
    for (int v : values)
        tree.insert(v);

    cout << "Inorder traversal: ";
    tree.inorder(); // 3 5 7 10 12 15 18

    cout << "Search 7: " << (tree.search(7) ? "Found" : "Not Found") << endl;
    cout << "Search 9: " << (tree.search(9) ? "Found" : "Not Found") << endl;

    return 0;
}
