#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* root = NULL;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* node, int data) {
    if (node == NULL) return createNode(data);
    if (data < node->data) node->left = insert(node->left, data);
    else if (data > node->data) node->right = insert(node->right, data);
    return node;
}

void inorder(struct Node* node) {
    if (node == NULL) return;
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

void preorder(struct Node* node) {
    if (node == NULL) return;
    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
}

void postorder(struct Node* node) {
    if (node == NULL) return;
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->data);
}

struct Queue {
    struct Node* arr[100];
    int front, rear;
};

void initQueue(struct Queue* q) {
    q->front = q->rear = -1;
}

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

void enqueue(struct Queue* q, struct Node* node) {
    if (q->rear == 99) return;
    if (q->front == -1) q->front = 0;
    q->arr[++q->rear] = node;
}

struct Node* dequeue(struct Queue* q) {
    if (isEmpty(q)) return NULL;
    struct Node* node = q->arr[q->front];
    if (q->front == q->rear) q->front = q->rear = -1;
    else q->front++;
    return node;
}

void bfs(struct Node* node) {
    struct Queue q;
    initQueue(&q);
    enqueue(&q, node);
    while (!isEmpty(&q)) {
        struct Node* temp = dequeue(&q);
        printf("%d ", temp->data);
        if (temp->left) enqueue(&q, temp->left);
        if (temp->right) enqueue(&q, temp->right);
    }
}

void dfs(struct Node* node) {
    if (node == NULL) return;
    printf("%d ", node->data);
    dfs(node->left);
    dfs(node->right);
}

struct Node* mirror(struct Node* node) {
    if (node == NULL) return NULL;
    struct Node* temp;
    mirror(node->left);
    mirror(node->right);
    temp = node->left;
    node->left = node->right;
    node->right = temp;
    return node;
}

struct Node* find(struct Node* node, int key) {
    if (node == NULL || node->data == key) return node;
    if (key < node->data) return find(node->left, key);
    else return find(node->right, key);
}

void children(struct Node* node) {
    if (node == NULL) return;
    if (node->left) printf("Left child: %d\n", node->left->data);
    if (node->right) printf("Right child: %d\n", node->right->data);
    if (!node->left && !node->right) printf("No children\n");
}

void sibling(struct Node* root, int key) {
    if (root == NULL) return;
    if (root->left && root->left->data == key && root->right)
        printf("Sibling: %d\n", root->right->data);
    else if (root->right && root->right->data == key && root->left)
        printf("Sibling: %d\n", root->left->data);
    else {
        sibling(root->left, key);
        sibling(root->right, key);
    }
}

void parent(struct Node* root, int key) {
    if (root == NULL) return;
    if ((root->left && root->left->data == key) || (root->right && root->right->data == key))
        printf("Parent: %d\n", root->data);
    else {
        parent(root->left, key);
        parent(root->right, key);
    }
}

void grandparent(struct Node* root, int key) {
    if (root == NULL) return;
    if (root->left) {
        if ((root->left->left && root->left->left->data == key) ||
            (root->left->right && root->left->right->data == key))
            printf("Grandparent: %d\n", root->data);
    }
    if (root->right) {
        if ((root->right->left && root->right->left->data == key) ||
            (root->right->right && root->right->right->data == key))
            printf("Grandparent: %d\n", root->data);
    }
    grandparent(root->left, key);
    grandparent(root->right, key);
}

void uncle(struct Node* root, int key) {
    if (root == NULL) return;
    if (root->left) {
        if ((root->left->left && root->left->left->data == key) ||
            (root->left->right && root->left->right->data == key)) {
            if (root->right) printf("Uncle: %d\n", root->right->data);
        }
    }
    if (root->right) {
        if ((root->right->left && root->right->left->data == key) ||
            (root->right->right && root->right->right->data == key)) {
            if (root->left) printf("Uncle: %d\n", root->left->data);
        }
    }
    uncle(root->left, key);
    uncle(root->right, key);
}

int main() {
    int choice, val, key;
    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Insert\n2. Inorder\n3. Preorder\n4. Postorder\n5. BFS\n6. DFS\n7. Mirror\n");
        printf("8. Children\n9. Sibling\n10. Parent\n11. Grandparent\n12. Uncle\n13. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            case 2:
                inorder(root);
                break;
            case 3:
                preorder(root);
                break;
            case 4:
                postorder(root);
                break;
            case 5:
                bfs(root);
                break;
            case 6:
                dfs(root);
                break;
            case 7:
                root = mirror(root);
                break;
            case 8:
                printf("Enter node value: ");
                scanf("%d", &key);
                children(find(root, key));
                break;
            case 9:
                printf("Enter node value: ");
                scanf("%d", &key);
                sibling(root, key);
                break;
            case 10:
                printf("Enter node value: ");
                scanf("%d", &key);
                parent(root, key);
                break;
            case 11:
                printf("Enter node value: ");
                scanf("%d", &key);
                grandparent(root, key);
                break;
            case 12:
                printf("Enter node value: ");
                scanf("%d", &key);
                uncle(root, key);
                break;
            case 13:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

