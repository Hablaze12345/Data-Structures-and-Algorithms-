#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Cấu trúc Node cho danh sách liên kết để lưu từ
typedef struct WordNode {
    char word[100];           // Từ vựng
    int count;                // Số lần xuất hiện
    struct WordNode* link;    // Con trỏ tới Node tiếp theo
} WordNode;

// Hàm sao chép chuỗi thủ công
void copyString(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// Hàm tạo một Node mới
WordNode* createNode(const char* word) {
    WordNode* newNode = (WordNode*)malloc(sizeof(WordNode));
    if (newNode == NULL) {
        printf("Không thể cấp phát bộ nhớ cho Node mới.\n");
        exit(1);
    }
    copyString(newNode->word, word);
    newNode->count = 1;
    newNode->link = NULL;
    return newNode;
}

// Hàm thêm từ vào danh sách (nếu từ đã tồn tại thì tăng số lần xuất hiện)
void addWord(WordNode** head, const char* word) {
    WordNode* current = *head;
    WordNode* prev = NULL;

    // Kiểm tra từ đã tồn tại trong danh sách chưa
    while (current != NULL) {
        if (current->word[0] != '\0' && strcmp(current->word, word) == 0) {
            current->count++;
            return;
        }
        prev = current;
        current = current->link;
    }

    // Nếu từ chưa tồn tại, thêm Node mới vào cuối danh sách
    WordNode* newNode = createNode(word);
    if (prev == NULL) {
        *head = newNode; // Danh sách đang rỗng
    } else {
        prev->link = newNode;
    }
}

// Hàm xác định từ xuất hiện nhiều nhất
WordNode* findMostFrequentWord(WordNode* head) {
    WordNode* mostFrequent = head;
    WordNode* current = head;

    while (current != NULL) {
        if (current->count > mostFrequent->count) {
            mostFrequent = current;
        }
        current = current->link;
    }
    return mostFrequent;
}

// Hàm đếm số từ trong danh sách
int countWords(WordNode* head) {
    int count = 0;
    WordNode* current = head;

    while (current != NULL) {
        count++;
        current = current->link;
    }
    return count;
}

// Hàm hiển thị danh sách từ
void displayWords(WordNode* head) {
    WordNode* current = head;

    printf("Danh sách từ:\n");
    while (current != NULL) {
        printf("%s: %d lần\n", current->word, current->count);
        current = current->link;
    }
}

// Hàm xóa từ láy nếu có (ví dụ: xanh xanh)
void removeDuplicateWords(WordNode** head) {
    WordNode* current = *head;

    while (current != NULL) {
        char* word = current->word;
        int len = 0;

        // Tìm chiều dài của từ
        while (word[len] != '\0') len++;

        // Nếu từ lặp (xanh xanh)
        if (len % 2 == 0) {
            int half = len / 2;
            bool isDuplicate = true;

            for (int i = 0; i < half; i++) {
                if (word[i] != word[half + i]) {
                    isDuplicate = false;
                    break;
                }
            }

            // Xóa từ lặp nếu đúng
            if (isDuplicate) {
                WordNode* toDelete = current;
                current = current->link;
                free(toDelete);
                return;
            }
        }
        current = current->link;
    }
}

// Hàm tách từ thủ công từ một câu
void splitWords(const char* sentence, WordNode** head) {
    char word[100] = {0};
    int index = 0;

    for (int i = 0; sentence[i] != '\0'; i++) {
        if (sentence[i] == ' ' || sentence[i] == '\n' || sentence[i] == '\t') {
            if (index > 0) {
                word[index] = '\0'; // Kết thúc từ
                addWord(head, word); // Thêm từ vào danh sách
                index = 0;           // Reset index
            }
        } else {
            word[index++] = sentence[i];
        }
    }

    // Xử lý từ cuối cùng (nếu có)
    if (index > 0) {
        word[index] = '\0';
        addWord(head, word);
    }
}

// Hàm chính
int main() {
    WordNode* wordList = NULL;

    // Câu đầu vào
    const char sentence[] = "xanh xanh đỏ vàng xanh đỏ vàng xanh xanh";

    // Tách từ từ câu và thêm vào danh sách liên kết
    splitWords(sentence, &wordList);

    // Hiển thị danh sách từ
    printf("Trước khi xử lý:\n");
    displayWords(wordList);

    // Xác định từ xuất hiện nhiều nhất
    WordNode* mostFrequent = findMostFrequentWord(wordList);
    printf("\nTừ xuất hiện nhiều nhất: %s (%d lần)\n", mostFrequent->word, mostFrequent->count);

    // Loại bỏ từ láy nếu có
    removeDuplicateWords(&wordList);

    // Hiển thị danh sách từ sau khi loại bỏ từ láy
    printf("\nSau khi loại bỏ từ láy:\n");
    displayWords(wordList);

    // Đếm tổng số từ
    int totalWords = countWords(wordList);
    printf("\nTổng số từ trong danh sách: %d\n", totalWords);

    return 0;
}