#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};



struct Node* allocate_node(){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
}



int main(){

    struct Node* node_1 = allocate_node();

    struct Node* node_2a = allocate_node();
    struct Node* node_2b = allocate_node();

    struct Node* node_3a = allocate_node();
    struct Node* node_3b = allocate_node();
    struct Node* node_3c = allocate_node();
    struct Node* node_3d = allocate_node();


    node_1 -> val = 100;
    
    node_2a -> val = 20;
    node_2b -> val = 10;

    node_3a -> val = 11;
    node_3b -> val = 10;
    node_3c -> val = 25;
    node_3d -> val = 20;




    node_1 -> left = node_2a;
    node_1 -> right = node_2b;

    node_2a -> left = node_3a;
    node_2a -> right = node_3b;
    node_2b -> left = node_3c;
    node_2b -> right = node_3d;


}