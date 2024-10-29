#include <stdio.h>
#include <stdlib.h>

// Cấu trúc cho một phần tử của đa thức (node)
typedef struct nodeDT {
    int he_so;            // Hệ số
    int so_mu;            // Số mũ
    struct nodeDT* next;  // Con trỏ tới phần tử tiếp theo
} nodeDT;

// Cấu trúc danh sách liên kết (List)
typedef struct {
    nodeDT* firstNode;    // Con trỏ đến phần tử đầu tiên
} List;

// Khởi tạo danh sách liên kết rỗng
void List_Init(List* list) {
    list->firstNode = NULL;
}

// Tạo một node mới với hệ số và số mũ đã cho
nodeDT* createNode(int he_so, int so_mu) {
    nodeDT* newnode = (nodeDT*)malloc(sizeof(nodeDT));
    if (newnode == NULL) {
        printf("Loi cap phat bo nho!\n");
        exit(1);
    }
    newnode->he_so = he_so;
    newnode->so_mu = so_mu;
    newnode->next = NULL;
    return newnode;
}

// Thêm một node vào cuối danh sách liên kết
void addNode(List* list, int he_so, int so_mu) {
    nodeDT* newnode = createNode(he_so, so_mu);
    if (list->firstNode == NULL) {
        list->firstNode = newnode;
    } else {
        nodeDT* temp = list->firstNode;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

// Giải phóng toàn bộ danh sách để tránh rò rỉ bộ nhớ
void freeList(List* list) {
    nodeDT* current = list->firstNode;
    while (current != NULL) {
        nodeDT* nextNode = current->next;
        free(current);
        current = nextNode;
    }
    list->firstNode = NULL;
}

// Hàm nhập đa thức
void taoDT(List* list) {
    int he_so, so_mu;
    int i = 0;
    printf("Bat dau nhap da thuc :\n");
    while (1) {
        i++;
        printf("Nhap so phan tu thu %d:\n", i);
        printf("Nhap he so = ");
        scanf("%d", &he_so);
        if (he_so == 0) {
            printf("Bo qua phan tu co he so = 0.\n");
            continue;  // Bỏ qua phần tử nếu hệ số bằng 0
        }
        printf("Nhap so mu = ");
        scanf("%d", &so_mu);
        addNode(list, he_so, so_mu);
        printf("Nhap 0 de ket thuc, nhap bat ky de tiep tuc: ");
        int choice;
        scanf("%d", &choice);
        if (choice == 0) break;
    }
    printf("Ket thuc nhap da thuc.\n");
}

// Hàm in đa thức
void inDT(List* list) {
    nodeDT* current = list->firstNode;
    if (current == NULL) {
        printf("f(x) = 0\n");  // Nếu danh sách rỗng, in f(x) = 0
        return;
    }
    printf("f(x) = ");
    while (current != NULL) {
        printf("%d*x^%d", current->he_so, current->so_mu);
        if (current->next != NULL) {
            printf(" + ");
        }
        current = current->next;
    }
    printf("\n");
}

// Hàm main để kiểm thử chương trình
int main() {
    List DT1;
    List_Init(&DT1);
    taoDT(&DT1);
    inDT(&DT1);
    freeList(&DT1);  // Giải phóng bộ nhớ sau khi sử dụng
    return 0;
}