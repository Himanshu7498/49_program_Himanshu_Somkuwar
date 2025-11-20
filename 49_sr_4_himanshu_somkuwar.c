#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int arr[MAX];
int front1 = -1, rear1 = -1;
int front2 = MAX, rear2 = MAX;

void enqueue1(int x) {
    if (rear1 + 1 == rear2) {
        printf("Queue Overflow\n");
        return;
    }
    if (front1 == -1) front1 = 0;
    arr[++rear1] = x;
}

void enqueue2(int x) {
    if (rear2 - 1 == rear1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front2 == MAX) front2 = MAX - 1;
    arr[--rear2] = x;
}

void dequeue1() {
    if (front1 == -1 || front1 > rear1) {
        printf("Queue1 Underflow\n");
        return;
    }
    printf("Dequeued from Queue1: %d\n", arr[front1++]);
}

void dequeue2() {
    if (front2 == MAX || front2 < rear2) {
        printf("Queue2 Underflow\n");
        return;
    }
    printf("Dequeued from Queue2: %d\n", arr[front2--]);
}

void display1() {
    if (front1 == -1 || front1 > rear1) {
        printf("Queue1 is Empty\n");
        return;
    }
    printf("Queue1: ");
    for (int i = front1; i <= rear1; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void display2() {
    if (front2 == MAX || front2 < rear2) {
        printf("Queue2 is Empty\n");
        return;
    }
    printf("Queue2: ");
    for (int i = front2; i >= rear2; i--)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    enqueue1(10);
    enqueue1(20);
    enqueue1(30);

    enqueue2(100);
    enqueue2(200);
    enqueue2(300);

    display1();
    display2();

    dequeue1();
    dequeue2();

    display1();
    display2();

    return 0;
}

