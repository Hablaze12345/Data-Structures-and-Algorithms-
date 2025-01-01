#include <iostream>
#include <string>
using namespace std;

// Dn Node
struct Node {
    string name; // Ten dinh
    Node* next;  // Con tro toi dinh tiep theo

	//Cau truc tung node tiep theo
    Node(string name) {
        this->name = name;
        this->next = nullptr; // Khoi tao con tro ban dau la nullptr
    }
};

struct Edge {
    Node* node;    // Moi canh la 1 node
    Edge* next;     // Con tro toi canh ke voi no

    // Dinh nghia canh voi node da cho
    Edge(Node* node) {
        this->node = node;
        this->next = nullptr;
    }
};

// Luu tru danh sach cac canh cua cac dinh
Edge* head[10000] = {nullptr};

// Thêm c?nh
void addEdge(int u, string name) {
    Node* newNode = new Node(name) ;//Tao node moi
    Edge* newEdge = new Edge(newNode);  // Tao canh moi tu node

    // Them vao danh sach ke cua dinh
    newEdge->next = head[u];
    head[u] = newEdge;
}

// Hien thi danh sach ke cua do thi
void displayAdjacencyList(int n) {
    for (int i = 1; i <= n; i++) {
        cout << "V[" << i << "]: ";
        Edge* temp = head[i];
        if (temp == nullptr) {
            cout << "Khong co dinh ke" << endl;
        } else {
            while (temp != nullptr) {
                cout << temp->node->name;
                if (temp->next != nullptr) {
                    cout << ", ";
                }
                temp = temp->next;
            }
            cout << endl;
        }
    }
}

int main () {
    // Ma tran luu tru
    int n = 11, m = 13;
    int a[n][m];
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        a[x][y] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;

}

//Danh sach ke

    // Khoi tao do thi
    addEdge(1, "ST");
    addEdge(1, "TN");
    addEdge(1, "BN");
    addEdge(1, "HD");
    addEdge(1, "PL");
    addEdge(1, "HB");
    addEdge(2, "HN");
    addEdge(3, "HN");
    addEdge(4, "HN");
    addEdge(4, "BG");
    addEdge(4, "UB");
    addEdge(5, "BN");
    addEdge(5, "UB");
    addEdge(6, "BN");
    addEdge(6, "BG");addEdge(6, "HP");
    addEdge(7, "UB");
    addEdge(7, "HD");
    addEdge(8, "HN");
    addEdge(8, "HP");  addEdge(8, "HY");
    addEdge(9, "HD");  addEdge(9, "PL");
    addEdge(10, "HN");  addEdge(10, "HY");
    addEdge(11, "HN");

    // Hien thi danh sach lien ket cua do thi
    displayAdjacencyList(n);

    return 0;

}
