#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

int main(){
    int** matrix = (int**)malloc(sizeof(int*) * 100);
    for (int i = 0; i < 10; i++){
        int* row = (int*)malloc(sizeof(int) * 100);
        for (int j = 0; j < 100; j++){
            row[j] = j;
        }
        matrix[i] = row;
    }
    
    // free matrix
    for (int i = 0; i < 10; i++){
        free(matrix[i]);
    }
    free(matrix);

    // Node
    struct Node* some_node_1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node some_node_2;
    some_node_1 -> val = 100;
    some_node_2.val = 100;
    printf("%i\n", some_node_1 -> val);
    printf("%i\n", (*some_node_1).val);
    printf("%i\n", some_node_2.val);

    // Linked List
    struct Node* node_1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node_2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node_3 = (struct Node*)malloc(sizeof(struct Node));

    node_1 -> val = 1;
    node_2 -> val = 2;
    node_3 -> val = 5;
    node_1 -> next = node_2;
    node_2 -> next = node_3;

    struct Node* node_4 = (struct Node*)malloc(sizeof(struct Node));
    node_4 -> val = 3;
    node_1 -> next = node_4;
    node_4 -> next = node_2;

    printf("%i\n", node_1 -> val);
    printf("%i\n", node_2 -> val);
    printf("%i\n", node_3 -> val);
    printf("%i\n", node_4 -> val);
}