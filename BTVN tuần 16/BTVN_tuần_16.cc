#include<iostream>
#include<algorithm>
using namespace std ;
struct AVLNode {
	int elem ;
	AVLNode* left;
	AVLNode* right ;
	int height ; //chieu cao cua nut
	AVLNode(int e, AVLNode* l,AVLNode* r,int h) {
		elem =e ;
		left=l ;
		right =r ;
		height=h ;
	}
};
//Ham tra ve chieu cao cua nut
int height(AVLNode* t) {
	return t==NULL?-1 : t->height ;
}
void rotatewithLeftChild(AVLNode * & k2){
	AVLNode* k1=k2->left;
	k2->left=k1->right ;
	k1->right=k2 ;
	k2->height=max(height(k2->left), height(k1->right)) +1 ;
	k1->height=max(height(k1->left),k2->height) +1;
	k2=k1 ;
}
void rotatewithRightChild(AVLNode*& k2) {
    AVLNode* k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->right), k2->height) + 1;
    k2 = k1;
}

void doublewithLeftChild(AVLNode * & k3) {
	rotatewithRightChild(k3->left) ;
	rotatewithLeftChild(k3) ;
}
void doublewithRightChild(AVLNode * & k3) {
    rotatewithLeftChild(k3->right);
    rotatewithRightChild(k3);
}
void insert(int x, AVLNode*& t) {
    if (t == nullptr) {
        t = new AVLNode(x,nullptr,nullptr,0);
    } else if (x <= t->elem) {
        insert(x, t->left);
        if (height(t->left) - height(t->right) == 2) {
            if (x <= t->left->elem) {
                rotatewithLeftChild(t);
            } else {
                doublewithLeftChild(t);
            }
        }
    } else if (x > t->elem) {
        insert(x, t->right);
        if (height(t->right) - height(t->left) == 2) {
            if (x > t->right->elem) {
                rotatewithRightChild(t);
            } else {
                doublewithRightChild(t);
            }
        }
    }
    t->height = max(height(t->left), height(t->right)) + 1;
}
//Ham duyet cay theo thu tu inorder
void inorderTraversal(AVLNode* t) {
    if (t != nullptr) {
        inorderTraversal(t->left);
        cout << t->elem << " ";
        inorderTraversal(t->right);
    }
}
//Ham kiem tra can bang cua cay AVL
int getBalance(AVLNode* t) {
    if (t == nullptr) return 0;
    return height(t->left) - height(t->right);
}
//Ham kiem tra toan bo cay co can bang hay k
bool isBalanced(AVLNode* t) {
    if (t == nullptr) return true;
    int balance = getBalance(t);
    if (abs(balance) > 1) return false;
    return isBalanced(t->left) && isBalanced(t->right);
}
void deleteTree(AVLNode*& t) {
    if (t != nullptr) {
        deleteTree(t->left);
        deleteTree(t->right);
        delete t;
        t = nullptr;
    }
}
int main() {
    AVLNode* root = nullptr;
    int arr[] = {17, 23, 201, 98, 67, 83, 13, 23, 10, 191, 84, 58};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        insert(arr[i], root);
    }

    cout << "Cay AVL sau khi chen phan tu: ";
    inorderTraversal(root);
    cout << endl;

    if (isBalanced(root)) {
        cout << "Cay AVL duoc can bang." << endl;
    } else {
        cout << "Cay AVL ko duoc can bang." << endl;
    }

    deleteTree(root);

    return 0;
}

