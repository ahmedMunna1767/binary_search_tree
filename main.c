#include<stdio.h>

#include "bst.h"
#include "bst.c"

int main(int argc, char* argv[]) {

    node* root = NULL; 

/*     root = insertVal(root, 5); 
    root = insertVal(root, 4); 
    root = insertVal(root, 6); 
    root = insertVal(root, 3); 
    root = insertVal(root, 7); 
    root = insertVal(root, 2);
    root = insertVal(root, 8);
    root = insertVal(root, 3);
    root = insertVal(root, 13); 
10, 5, 1, 7, 40, 50 */

    root = insertVal(root, 10); 
    root = insertVal(root, 5); 
    root = insertVal(root, 1); 
    root = insertVal(root, 7); 
    root = insertVal(root, 40); 
    root = insertVal(root, 50); 

    printf("In Order: \n"); 
    printTreeInOrder(root); 
    printf("\n"); 
    printf("Pre Order: \n"); 
    printTreePreOrder(root); 
    printf("\n"); 
    printf("Post Order: \n"); 
    printTreePostOrder(root); 
    printf("\n");

    printf("Succesor of 5 is %d\n", getSuccessor(root, 5));
    printf("Succesor of 1 is %d\n", getSuccessor(root, 1));
    printf("Succesor of 50 is %d\n", getSuccessor(root, 50));

    printf("Succesor of 40 is %d\n", getSuccessor(root, 40));
    printf("Succesor of 10 is %d\n", getSuccessor(root, 10));


    printf("total number of Nodes: %d\n", getNodeCount(root)); 
    printf("Is 7 in tree : %d\n", inTree(root, 7)); 
    printf("Is 17 in tree : %d\n", inTree(root, 17)); 
    printf("height of Tree: %d\n", getHeight(root)); 
    printf("Max Element is %d\n", getMax(root)); 
    printf("Min Element is %d\n", getMin(root)); 
    printf("Is BST %d\n", isBST(root)); 


    root = deleteVal(root,5);
    printf("Is BST %d\n", isBST(root));

    root = deleteVal(root,40);
    printf("Is BST %d\n", isBST(root));

    root = deleteVal(root,10);
    printf("Is BST %d\n", isBST(root));

    root = deleteVal(root,5);
    printf("Is BST %d\n", isBST(root));

    root = deleteVal(root,5);
    printf("Is BST %d\n", isBST(root));

    printTreeInOrder(root); 
    printf("\n");  


    printf("\n-- --- ---- ---- ---- --- -- \n");
    printf("            All Ok\n");
    printf("-- --- ---- ---- ---- --- -- \n");
    return 0;

}