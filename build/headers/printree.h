// Program to print binary tree in 2D
#define COUNT 10

// A binary tree node

// Function to print binary tree in 2D
// It does reverse inorder traversal
void print2DUtil(AST *root, int space){
    // Base case
    if (root == NULL)
        return;
  
    // Increase distance between levels
    space += COUNT;
  
    // Process right child first
    if(root->right != NULL){
        print2DUtil(root->right, space);
    } else printf("NULL\n");
  
    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->nodetype);
  
    // Process left child
    if(root->left != NULL){
        print2DUtil(root->left, space);
    } else printf("NULL\n");
    
}
  
// Wrapper over print2DUtil()
void print2D(AST *root){
   print2DUtil(root, 0);
    printf("END\n");
}
  
