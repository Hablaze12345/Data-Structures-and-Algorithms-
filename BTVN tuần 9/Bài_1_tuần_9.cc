#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Cấu trúc Node cho danh sách liên kết đơn để lưu thông tin file
typedef struct FileNode {
    char address[200];      // Địa chỉ file
    char name[100];         // Tên file
    time_t modifiedTime;    // Thời gian chỉnh sửa cuối cùng
    int size;               // Kích thước file (đơn vị: MB)
    struct FileNode* link;  // Con trỏ tới Node tiếp theo
} FileNode;

// Hàm sao chép chuỗi thủ công
void copyString(char* dest, const char* src, int maxLen) {
    int i;
    for (i = 0; i < maxLen - 1 && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0'; // Kết thúc chuỗi
}

// Hàm khởi tạo một Node mới
FileNode* createNode(const char* address, const char* name, time_t modifiedTime, int size) {
    FileNode* newNode = (FileNode*)malloc(sizeof(FileNode));
    if (newNode == NULL) {
        printf("Không thể cấp phát bộ nhớ cho Node mới.\n");
        exit(1);
    }

    // Sao chép thủ công các chuỗi vào các trường address và name
    copyString(newNode->address, address, 200);
    copyString(newNode->name, name, 100);
    newNode->modifiedTime = modifiedTime;
    newNode->size = size;
    newNode->link = NULL;
    return newNode;
}
// Hàm chèn một Node mới vào danh sách theo thứ tự thời gian
void insertFile(FileNode** head, FileNode* newNode) {
    if (*head == NULL || (*head)->modifiedTime >= newNode->modifiedTime) {
        newNode->link = *head;
        *head = newNode;
    } else {
        FileNode* current = *head;
        while (current->link != NULL && current->link->modifiedTime < newNode->modifiedTime) {
            current = current->link;
        }
        newNode->link = current->link;
        current->link = newNode;
    }
}

// Hàm thêm file vào danh sách với thông tin địa chỉ, tên, thời gian, và kích thước
void addFile(FileNode** head, const char* address, const char* name, time_t modifiedTime, int size) {
    FileNode* newNode = createNode(address, name, modifiedTime, size);
    insertFile(head, newNode);
}
// Hàm tính tổng kích thước của tất cả các file trong danh sách
int calculateTotalSize(FileNode* head) {
    int totalSize = 0;
    FileNode* current = head;
    while (current != NULL) {
        totalSize += current->size;
        current = current->link;
    }
    return totalSize;
}
// Hàm tính tổng kích thước của tất cả các file trong danh sách
int calculateTotalSize(FileNode* head) {
    int totalSize = 0;
    FileNode* current = head;
    while (current != NULL) {
        totalSize += current->size;
        current = current->link;
    }
    return totalSize;
}

// Hàm lọc các file để sao lưu vào USB có dung lượng 32GB
void filterFilesForUSB(FileNode** head, int maxSize) {
    int totalSize = calculateTotalSize(*head);
    while (totalSize > maxSize) {
        // Tìm file có kích thước nhỏ nhất
        FileNode* current = *head;
        FileNode* prev = NULL;
        FileNode* smallestNode = *head;
        FileNode* smallestPrev = NULL;

        while (current != NULL) {
            if (current->size < smallestNode->size) {
                smallestPrev = prev;
                smallestNode = current;
            }
            prev = current;
            current = current->link;
        }

        // Loại bỏ node có kích thước nhỏ nhất khỏi danh sách
        if (smallestPrev == NULL) {
            *head = smallestNode->link;
        } else {
            smallestPrev->link = smallestNode->link;
        }

        // Giải phóng bộ nhớ của node bị loại
        totalSize -= smallestNode->size;
        free(smallestNode);
    }
}
// Hàm hiển thị danh sách các file trong danh sách
void displayFiles(FileNode* head) {
    FileNode* current = head;
    printf("Danh sách file:\n");
    while (current != NULL) {
        printf("Địa chỉ: %s\n", current->address);
        printf("Tên: %s\n", current->name);
        printf("Kích thước: %d MB\n", current->size);
        printf("Thời gian chỉnh sửa: %s", ctime(&current->modifiedTime));
        printf("\n");
        current = current->link;
    }
}
int main() {
    FileNode* fileList = NULL;


    addFile(&fileList, "D:/Document/file1.txt", "file1.txt", time(NULL), 1000);
    addFile(&fileList, "D:/Document/file2.txt", "file2.txt", time(NULL), 2000);
    addFile(&fileList, "D:/Document/file3.txt", "file3.txt", time(NULL), 500);
    addFile(&fileList, "D:/Document/file4.txt", "file4.txt", time(NULL), 700);
    addFile(&fileList, "D:/Document/file5.txt", "file5.txt", time(NULL), 1200);

    // Hiển thị danh sách các file trước khi lọc
    printf("Trước khi lọc:\n");
    displayFiles(fileList);

    // Thực hiện lọc các file để sao lưu vào USB 32GB
    filterFilesForUSB(&fileList, 32768);

    // Hiển thị danh sách các file sau khi lọc
    printf("Sau khi lọc (phù hợp với USB 32GB):\n");
    displayFiles(fileList);

    return 0;
}