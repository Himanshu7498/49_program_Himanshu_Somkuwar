#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    int isEndOfWord;
};

struct TrieNode* createNode() {
    struct TrieNode* node = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    node->isEndOfWord = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;
    return node;
}

void insert(struct TrieNode* root, const char* key) {
    struct TrieNode* p = root;
    for (int i = 0; i < strlen(key); i++) {
        int index = key[i] - 'a';
        if (p->children[index] == NULL)
            p->children[index] = createNode();
        p = p->children[index];
    }
    p->isEndOfWord = 1;
}

int search(struct TrieNode* root, const char* key) {
    struct TrieNode* p = root;
    for (int i = 0; i < strlen(key); i++) {
        int index = key[i] - 'a';
        if (p->children[index] == NULL)
            return 0;
        p = p->children[index];
    }
    return p->isEndOfWord;
}

int main() {
    struct TrieNode* root = createNode();
    int n;
    char word[50], key[50];

    printf("Enter number of words to insert: ");
    scanf("%d", &n);

    printf("Enter %d words:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%s", word);
        insert(root, word);
    }

    printf("Enter word to search: ");
    scanf("%s", key);

    if (search(root, key))
        printf("Word '%s' found in Trie\n", key);
    else
        printf("Word '%s' not found in Trie\n", key);

    return 0;
}
