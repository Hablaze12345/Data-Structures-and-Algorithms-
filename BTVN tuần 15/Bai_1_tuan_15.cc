#include <iostream>
#include <string>
using namespace std;

//Node trong cay nhi phan
struct Node {
    string data;
    Node* left;// Con trai (con ca)
    Node* right; // Con phai (anh em ke)
};

// Ham tao nut moi
Node* createNode(const string& data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Ham chuyen danh sach con thanh cay nhi phan
Node* convertToBinaryTree(Node* dad) {
    if (dad == nullptr || dad->left == nullptr) {
        return dad;
    }

    // Con ca bien thanh con trai
    Node* current = dad->left;
    Node* binaryLeftChild = current;
    dad->left = binaryLeftChild;

    // lien ket ae ke
    Node* previous = binaryLeftChild;
    current = current->right;
    while (current != nullptr) {
        previous->right = current;
        previous = current;
        current = current->right;
    }

    // Duyet de quy cac nut con
    current = binaryLeftChild;
    while (current != nullptr) {
        current->left = convertToBinaryTree(current);
        current = current->right;
    }
    return dad;
}

// duyet cay preorder
void traverseBinaryTree(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    traverseBinaryTree(root->left); // Duyet con trai
    traverseBinaryTree(root->right);// Duyet ae ke
}
// Ham them nut con vao danh sach con cua nut cha
void addChild(Node* dad, const string& childData) {
    if (dad->left == nullptr) {
        dad->left = createNode(childData); // Neu chua co con,them con trai
    } else {
        // Neu da co con trai,tim vi tri thic hop de them anh em ke
        Node* temp = dad->left;
        while (temp->right != nullptr) {
            temp = temp->right;
        }
        temp->right = createNode(childData); // Them vao danh sach ae ke
    }
}

// Ham tim so chuong cua cuon sach
int countChapters(Node* root) {
    if (root == nullptr) return 0;
    int count = 1; // Dem goc
    Node* chapter = root->left;
    while (chapter != nullptr) {
        count++;
        chapter = chapter->right;
    }
    return count;
}


// Ham dem so trang cua mot muc
int countPages(Node* section) {
    if (section == nullptr) return 0;
    int count = 0;
    Node* page = section->left;
    while (page != nullptr) {
        count++;
        page = page->right;
    }
    return count;
}
// Ham tim chuong dai nhat cua cuon sach
Node* findLongestChapter(Node* root) {
    if (root == nullptr || root->left == nullptr) return nullptr;

    Node* longestChapter = root->left;
    int maxPages = countPages(longestChapter);
    Node* chapter = root->left->right;

    while (chapter != nullptr) {
        int pageCount = countPages(chapter);
        if (pageCount > maxPages) {
            maxPages = pageCount;
            longestChapter = chapter;
        }
        chapter = chapter->right;
    }
    return longestChapter;
}

//Ham tim va xoa mot muc khoi sach
Node* deleteItem(Node* root, const string& target) {
    if (root == nullptr) return nullptr;

    if (root->data == target) {
        Node* newRoot = root->left;
        delete root;
        return newRoot;
    }

    Node* parent = root;
    Node* current = root->left;

    // Tim muc can xoa
    while (current != nullptr && current->data != target) {
        parent = current;
        current = current->right;
    }

    if (current != nullptr) {
        parent->right = current->right;
        delete current;
    }

    // Cap nhat lai so trang cho cac muc lien quan
    if (parent->left != nullptr) {
        parent->left = convertToBinaryTree(parent->left);
    }
    return root;
}

int main() {
    // Goc cua cay tong quat (ten sach)
    Node* root = createNode("Sapiens");

    // Them cac chapter vao goc(con ca va cac em)
    root->left = createNode("Chapter 1");
    root->left->right = createNode("Chapter 2");
    root->left->right->right = createNode("Chapter 3");
    root->left->right->right->right=createNode("Chapter 4") ;

    // Them section cho chap1
    Node* chapter1 = root->left;
    chapter1->left = createNode("Section 1.1");
    chapter1->left->right = createNode("Section 1.2");
    chapter1->left->right->right=createNode("Section 1.3") ;
    chapter1->left->right->right->right=createNode("Section1.4");

    // Them so trang cho cac sec
    Node* section1_1 = chapter1->left;
    section1_1->left = createNode("23 pages");
    Node* section1_2= chapter1->left->right ;
    section1_2->left = createNode("28 pages") ;
    Node* section1_3 = chapter1->left->right->right;
    section1_3->left = createNode("33 pages");
    Node* section1_4 = chapter1->left->right->right->right ;
    section1_4->left = createNode("20 pages") ;


    // Them section cho chap2
    Node* chapter2 = chapter1->right;
    chapter2->left = createNode("Section 2.1");
    chapter2->left->right=createNode("Section 2.2");
    chapter2->left->right->right=createNode("Section 2.3");
    chapter2->left->right->right->right=createNode("Section 2.4");

    // Them so trang cho cac sec2.
    Node* section2_1 = chapter2->left;
    section2_1->left = createNode("29 pages");
    Node* section2_2 = chapter2->left->right;
    section2_2->left = createNode("31 pages");
    Node* section2_3 = chapter2->left->right->right;
    section2_3->left = createNode("20 pages");
	Node* section2_4 = chapter2->left->right->right->right;
    section2_4->left = createNode("42 pages");

    // Them section cho chap3
    Node* chapter3 = chapter2->right;
    chapter3->left = createNode("Section 3.1");
    chapter3->left->right = createNode("Section 3.2");
    chapter3->left->right->right=createNode("Section 3.3") ;
    chapter3->left->right->right->right=createNode("Section3.4");
    chapter3->left->right->right->right->right=createNode("Section3.5");

    // Them so trang cho cac sec3.
    Node* section3_1 = chapter3->left;
    section3_1->left = createNode("16 pages");
    Node* section3_2 = chapter3->left->right;
    section3_2->left = createNode("24 pages");
    Node* section3_3 = chapter3->left->right->right;
    section3_3->left = createNode("30 pages");
	Node* section3_4 = chapter3->left->right->right->right;
    section3_4->left = createNode("40 pages");
    Node* section3_5 = chapter3->left->right->right->right->right;
    section3_5->left = createNode("13 pages");

    // Them section cho chap4
    Node* chapter4 = chapter3->right;
    chapter4->left = createNode("Section 4.1");
    chapter4->left->right = createNode("Section 4.2");
    chapter4->left->right->right=createNode("Section 4.3") ;
    chapter4->left->right->right->right=createNode("Section4.4");
    chapter4->left->right->right->right->right=createNode("Section4.5");
    chapter4->left->right->right->right->right->right=createNode("Section4.6");
    chapter4->left->right->right->right->right->right->right=createNode("Section4.7");

    // Them so trang cho cac sec4.
    Node* section4_1 = chapter4->left;
    section4_1->left = createNode("42 pages");
    Node* section4_2 = chapter4->left->right;
    section4_2->left = createNode("46 pages");
    Node* section4_3 = chapter4->left->right->right;
    section4_3->left = createNode("45 pages");
	Node* section4_4 = chapter4->left->right->right->right;
    section4_4->left = createNode("23 pages");
    Node* section4_5 = chapter4->left->right->right->right->right;
    section4_5->left = createNode("37 pages");
    Node* section4_6 = chapter4->left->right->right->right->right->right;
    section4_6->left = createNode("33 pages");
    Node* section4_7 = chapter4->left->right->right->right->right->right->right;
    section4_7->left = createNode("27 pages");


    // Chuyen doi cay tong quat sang cay nhi phan
    root = convertToBinaryTree(root);

    // Duyet cay nhi phan
    cout << "Duyet cay theo thu tu truoc:" << endl;
    traverseBinaryTree(root);

    //So chuong cua cuon sach
    cout<<"\nTotal Chapters : "<<countChapters(root)<<endl ;
    //Chuong dai nhat
    Node* longestChapter= findLongestChapter(root) ;
    cout<< "Longest Chapter : "<<(longestChapter ? longestChapter->data : "None")<<endl ;
    root=deleteItem(root,"Section 1.1") ;

    //Duyet cay sau khi xoa
    cout<<"After deletion: "<<endl;
    traverseBinaryTree(root) ;


    return 0;
}