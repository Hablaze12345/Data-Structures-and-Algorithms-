#include <stdio.h>
#include <stdlib.h>


typedef struct nodeDT {
    int he_so;
    int so_mu;
    struct nodeDT* next;
} nodeDT;


typedef struct {
    nodeDT* firstNode;
} List;


void List_Init(List* list) {
    list->firstNode = NULL;
}


void List_Add(List* list, int he_so, int so_mu) {
    nodeDT* newnode = (nodeDT*)malloc(sizeof(nodeDT));
    newnode->he_so = he_so;
    newnode->so_mu = so_mu;
    newnode->next = list->firstNode;
    list->firstNode = newnode;
}


void addNode(List* lDT, nodeDT* newnode) {
    if (lDT->firstNode == NULL) {
        lDT->firstNode = newnode;
    } else {
        nodeDT* temp = lDT->firstNode;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}


nodeDT* callNode(int he_so, int so_mu) {
    nodeDT* pDT = (nodeDT*)malloc(sizeof(nodeDT));
    if (pDT == NULL) return NULL;
    pDT->he_so = he_so;
    pDT->so_mu = so_mu;
    pDT->next = NULL;
    return pDT;
}


void attachNode(List* lDT, int he_so, int so_mu) {
    nodeDT* pDT = callNode(he_so, so_mu);
    if (pDT == NULL) return;
    addNode(lDT, pDT);
}


void taoDT(List* lDT) {
    int he_so, so_mu;
    int i = 0;
    printf("Bat dau nhap da thuc (nhap he so 0 de ket thuc):\n");
    do {
        i++;
        printf("Nhap so phan tu thu %d\n", i);
        printf("Nhap he so = ");
        scanf("%d", &he_so);
        if (he_so == 0) break;
        printf("Nhap so mu = ");
        scanf("%d", &so_mu);
        attachNode(lDT, he_so, so_mu);
    } while (he_so != 0);
    printf("Ket thuc nhap\n");
}


void inDT(List* lDT) {
    nodeDT* current = lDT->firstNode;
    printf("\nf(x) = ");
    while (current != NULL) {
        printf("%d*x^%d", current->he_so, current->so_mu);
        if (current->next != NULL && current->next->he_so != 0) {
            printf(" + ");
        }
        current = current->next;
    }
    printf("\n");
}


int main() {
    List DT1;
    List_Init(&DT1);
    taoDT(&DT1);
    inDT(&DT1);
    return 0;
}