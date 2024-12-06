#include <iostream>
using namespace std;

struct node{
	string data;
	node *left;
	node *right;
};

bool isEmpty(node* root) {
    return root == NULL;
}
//cap phat node moi
node *createNode(string x){
	node *newNode = new node;
	newNode->data = x;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

//preorder
void preorder(node *root){
	if(root != NULL){
		cout << root->data << ' ';
		preorder(root -> left);
		preorder(root->right);
	}
}

//postorder
void postorder(node *root){
	if(root != NULL){
		postorder(root->left);
		postorder(root->right);
		cout << root->data << ' ';
	}
}

//inorder
void inorder(node *root){
	if(root != NULL){
		inorder(root->left);
		cout << root->data << ' ';
		inorder(root->right);
	}
}

void Traversal(node* root) {
    if (isEmpty(root)) {
        cout << "Cay rong, khong co gi de duyet!" << endl;
        return;
    }

    cout<<"Duyet cay theo thu tu truoc: ";
    preorder(root) ;
    cout<<"\nDuyet cay theo thu tu giua : " ;
    inorder(root) ;
    cout<<"\nDuyet cay theo thu tu sau : " ;
    postorder(root) ;
    cout<<endl ;
}
void insertNode(node* root) {
    string newValue;
    cout << "Nhap gia tri cua phan tu can them: ";
    cin >> newValue;

    node* newNode = createNode(newValue);

    // Duyet cay, tim vi tri trong de chen nut moi
    node* current = root;
    while (true) {
        if (current->left == nullptr) {
            current->left = newNode;
            break;
        } else if (current->right == nullptr) {
            current->right = newNode;
            break;
        } else {
            // tiep tuc duyet sang con ben trai truoc
            if (current->left) {
                current = current->left;
            } else if (current->right) {
                current = current->right;
            }
        }
    }
}
int main() {
	node* root = createNode("+");
	root->left = createNode("-");
	root->right = createNode("*");
	root->left->left = createNode("*");
	root->left->right = createNode("*");
	root->left->left->left = createNode("a");
	root->left->left->right = createNode("5");
	root->left->right->left = createNode("b");
	root->left->right->right = createNode("/");
	root->left->right->right->left = createNode("^");
	root->left->right->right->right = createNode("d");
	root->left->right->right->left->left = createNode("c");
	root->left->right->right->left->right = createNode("6");
	root->right->left = createNode("-");
	root->right->right = createNode("^");
	root->right->left->left = createNode("h");
	root->right->left->right = createNode("f");
	root->right->right->left = createNode("e");
	root->right->right->right = createNode("/");
	root->right->right->right->left = createNode("1");
	root->right->right->right->right = createNode("2");

 	int choice ;
 	do {
 		cout<<"1. Them phan tu vao cay\n" ;
		cout<<"2. Duyet cay\n" ;
		cout<<"3, Thoat\n" ;
		cout<<"Nhap lua chon cua ban :" ;
		cin>>choice ;
		switch (choice) {
			case 1 :
				insertNode(root) ;
				break ;
			case 2 :
				Traversal(root) ;
				break ;
			case 3 :
				cout<<"Thoat chuong trinh.\n" ;
				break ;
			default :
				cout<<"Lua chon khong hop le\n" ;
		}

	 } while(choice !=3) ;
    return 0;
}