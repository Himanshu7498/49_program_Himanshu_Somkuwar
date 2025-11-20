#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteNode(int key) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != key) temp = temp->next;
    if (temp == NULL) return;
    if (temp->prev != NULL) temp->prev->next = temp->next;
    else head = temp->next;
    if (temp->next != NULL) temp->next->prev = temp->prev;
    free(temp);
}

void reverseList() {
    struct Node* temp = NULL;
    struct Node* curr = head;
    while (curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    if (temp != NULL) head = temp->prev;
}

struct Node* mergeLists(struct Node* h1, struct Node* h2) {
    if (h1 == NULL) return h2;
    if (h2 == NULL) return h1;
    struct Node* temp = h1;
    while (temp->next != NULL) temp = temp->next;
    temp->next = h2;
    h2->prev = temp;
    return h1;
}

void findMiddle() {
    struct Node* slow = head;
    struct Node* fast = head;
    if (head == NULL) return;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("Middle element: %d\n", slow->data);
}

void sortList() {
    if (head == NULL) return;
    struct Node* i, *j;
    int temp;
    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void detectLoop() {
    struct Node* slow = head;
    struct Node* fast = head;
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            printf("Loop detected\n");
            return;
        }
    }
    printf("No loop detected\n");
}

void sumList() {
    int sum = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        sum += temp->data;
        temp = temp->next;
    }
    printf("Sum of elements: %d\n", sum);
}

void printOddEven() {
    struct Node* temp = head;
    printf("Odd elements: ");
    while (temp != NULL) {
        if (temp->data % 2 != 0) printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\nEven elements: ");
    temp = head;
    while (temp != NULL) {
        if (temp->data % 2 == 0) printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void display() {
    struct Node* temp = head;
    if (head == NULL) {
        printf("List empty\n");
        return;
    }
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, val;
    struct Node* list2 = NULL;
    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Reverse\n5. Merge another list\n");
        printf("6. Find Middle\n7. Sort\n8. Detect Loop\n9. Sum of Data\n10. Print Odd/Even\n11. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insertEnd(val);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                deleteNode(val);
                break;
            case 3:
                display();
                break;
            case 4:
                reverseList();
                break;
            case 5:
                list2 = createNode(100);
                list2->next = createNode(200);
                list2->next->prev = list2;
                head = mergeLists(head, list2);
                break;
            case 6:
                findMiddle();
                break;
            case 7:
                sortList();
                break;
            case 8:
                detectLoop();
                break;
            case 9:
                sumList();
                break;
            case 10:
                printOddEven();
                break;
            case 11:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

