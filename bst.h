#include<stdbool.h>
#include<stdlib.h>

typedef struct bst_node {
    int val; 
    struct bst_node* left; 
    struct bst_node* right; 
} node;


node* insertVal (node* rootNode,  const int val); 

void printTreeInOrder(node* rootNode); 
void printTreePreOrder(node* rootNode);
void printTreePostOrder(node* rootNode);

int getNodeCount(node* rootNode); 

void deleteTree(node* rootNode); 

bool inTree( node* rootNode, const int val); 

int getHeight(node* rootNode);

int getMin(node* rootNode); 

int getMax(node* rootNode); 

bool isBetween(node *rootNode, int min, int max); 

bool isBST(node* rootNode); 

node* deleteVal(node* rootNode, const int val); 

int getSuccessor(node* rootNode, const int val); 

