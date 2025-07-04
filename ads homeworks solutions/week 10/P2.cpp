#include <iostream>
using namespace std;

enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    Node *left, *right, *parent;
    Node(int data) : data(data), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTree {
private:
    Node* root;

    void rotateLeft(Node*& x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left != nullptr) y->left->parent = x;
        y->parent = x->parent;
        if (x->parent == nullptr) root = y;
        else if (x == x->parent->left) x->parent->left = y;
        else x->parent->right = y;
        y->left = x;
        x->parent = y;
    }

    void rotateRight(Node*& x) {
        Node* y = x->left;
        x->left = y->right;
        if (y->right != nullptr) y->right->parent = x;
        y->parent = x->parent;
        if (x->parent == nullptr) root = y;
        else if (x == x->parent->right) x->parent->right = y;
        else x->parent->left = y;
        y->right = x;
        x->parent = y;
    }

    void fixInsert(Node*& k) {
        while (k != root && k->parent->color == RED) {
            Node* grandparent = k->parent->parent;
            if (k->parent == grandparent->left) {
                Node* uncle = grandparent->right;
                if (uncle != nullptr && uncle->color == RED) {
                    k->parent->color = BLACK;
                    uncle->color = BLACK;
                    grandparent->color = RED;
                    k = grandparent;
                } else {
                    if (k == k->parent->right) {
                        k = k->parent;
                        rotateLeft(k);
                    }
                    k->parent->color = BLACK;
                    grandparent->color = RED;
                    rotateRight(grandparent);
                }
            } else {
                Node* uncle = grandparent->left;
                if (uncle != nullptr && uncle->color == RED) {
                    k->parent->color = BLACK;
                    uncle->color = BLACK;
                    grandparent->color = RED;
                    k = grandparent;
                } else {
                    if (k == k->parent->left) {
                        k = k->parent;
                        rotateRight(k);
                    }
                    k->parent->color = BLACK;
                    grandparent->color = RED;
                    rotateLeft(grandparent);
                }
            }
        }
        root->color = BLACK;
    }

    Node* minValueNode(Node* node) {
        while (node->left != nullptr) node = node->left;
        return node;
    }

    Node* maxValueNode(Node* node) {
        while (node->right != nullptr) node = node->right;
        return node;
    }

    Node* searchNode(Node* node, int key) {
        if (node == nullptr || node->data == key) return node;
        if (key < node->data) return searchNode(node->left, key);
        else return searchNode(node->right, key);
    }

    void printPreorder(Node* node) {
        if (!node) return;
        cout << node->data << (node->color == RED ? "(R) " : "(B) ");
        printPreorder(node->left);
        printPreorder(node->right);
    }

public:
    RedBlackTree() { root = nullptr; }

    void insertRB(int data) {
        Node* node = new Node(data);
        Node* y = nullptr;
        Node* x = root;

        while (x != nullptr) {
            y = x;
            if (node->data < x->data) x = x->left;
            else x = x->right;
        }

        node->parent = y;
        if (y == nullptr) root = node;
        else if (node->data < y->data) y->left = node;
        else y->right = node;

        node->left = node->right = nullptr;
        node->color = RED;

        fixInsert(node);
    }

    Node* getMinimum() { return minValueNode(root); }
    Node* getMaximum() { return maxValueNode(root); }

    Node* search(int key) { return searchNode(root, key); }

    Node* predecessor(const Node*& x) const {
        if (x->left != nullptr) {
            Node* p = x->left;
            while (p->right) p = p->right;
            return p;
        }
        Node* y = x->parent;
        Node* temp = (Node*)x;
        while (y && temp == y->left) {
            temp = y;
            y = y->parent;
        }
        return y;
    }

    Node* successor(const Node*& x) const {
        if (x->right != nullptr) {
            Node* p = x->right;
            while (p->left) p = p->left;
            return p;
        }
        Node* y = x->parent;
        Node* temp = (Node*)x;
        while (y && temp == y->right) {
            temp = y;
            y = y->parent;
        }
        return y;
    }

    void printTree() {
        printPreorder(root);
        cout << endl;
    }
};

int main() {
    RedBlackTree rbt;
    rbt.insertRB(10);
    rbt.insertRB(20);
    rbt.insertRB(30);
    rbt.insertRB(15);

    cout << "Preorder with colors: ";
    rbt.printTree();

    Node* min = rbt.getMinimum();
    Node* max = rbt.getMaximum();
    if (min) cout << "Minimum: " << min->data << endl;
    if (max) cout << "Maximum: " << max->data << endl;

    Node* found = rbt.search(15);
    if (found) cout << "Found: " << found->data << endl;
    return 0;
}
