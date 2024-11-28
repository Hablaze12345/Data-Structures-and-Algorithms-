#include <stdio.h>
#include <string.h>

#define MAX_QUEUE 100 // Kich thuoc toi da cua hang doi

// Cau truc luu tru thong tin khach hang
typedef struct {
    char name[50];
    float amount; // So tien
    int productA; //So sp A
} Customer;

// Cau truc hang doi
typedef struct {
    Customer queue[MAX_QUEUE];
    int front; // Chi so dau hang doi
    int rear;    // Chi so cuoi hang doi
} Queue;

// Ham khoi tao hang doi
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = 0;
}

// Ham kiem tra hang doi cos rong k
int isEmpty(Queue *q) {
    return q->front == q->rear;
}

// Ham kiem tra hang doi co full k
int isFull(Queue *q) {
    return q->rear >= MAX_QUEUE;
}

// Ham them customer vao hang doi
void enqueue(Queue *q) {
    if (isFull(q)) {
        printf("Hang doi da day,khong the them khach hang\n");
        return;
    }
    Customer *c =&q->queue[q->rear] ;
    printf("Nhap ten khach hang :") ;
    scanf(" %[^\n]", c->name) ;
    printf("Nhap so tien thanh toan : ") ;
    scanf("%f",&c->amount) ;
    printf("Nhap so luong sp A :") ;
    scanf("%d", &c->productA) ;
    q->rear++ ;
}

// Ham lay khach hang ra khoi hang doi
Customer dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Hang doi rong, khong co khach hang nao de xu ly .\n");
        Customer emptyCustomer = {"", 0.0, 0};
        return emptyCustomer;
    }
    return q->queue[q->front++];
}

// Ham xu ly hang doi va tinh toan
void processQueue(Queue *q) {
    float totalAmount = 0.0; // Tong so tien thu duocj
    int totalProductA = 0;// Tong so sp A da ban

    printf("\nBat dau xu ly hang doi:\n");
    while (!isEmpty(q)) {
        Customer c = dequeue(q);
        printf("Khach hang %s da thanh toan %.2f va mua %d sp A.\n",
               c.name, c.amount, c.productA);
        totalAmount += c.amount;
        totalProductA += c.productA;
    }

    printf("\nTong so tien thu duoc: %.2f\n", totalAmount);
    printf("Tong so sp A da ban: %d\n", totalProductA);
}

// Ham main
int main() {
    Queue q;
    initQueue(&q);

    int choice ;
    do {
    	printf("1. Them khach hang vao hang doi\n") ;
    	printf("2. Xu ly hang doi\n") ;
    	printf("3. Thoat\n") ;
    	printf("Lua chon cua ban :") ;
    	scanf("%d", &choice) ;
    	switch (choice) {
    		case 1 :
    			enqueue(&q) ;
    			break ;
    		case 2 :
    			processQueue(&q) ;
    			break ;
    		case 3 :
    			printf("Ket thuc chuong trinh\n") ;
    			break ;
    		default :
    			printf("Lua chon khong hop le.Vui long thu lai\n") ;
		}
	} while (choice !=3) ;

    return 0; // y 2,3,4 duoc xu ly trong ham processQueue
}