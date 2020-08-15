#include <iostream>
#include <math.h>
#include<stdlib.h>

using namespace std;

struct node
{
        int data;
        struct node* left;
        struct node* right;
};

 
struct node* newNode(int data)
{
      struct node* node = (struct node*) malloc(sizeof(struct node));
      node->data = data;
      node->left = NULL;
      node->right = NULL;         
      return(node);
}

void swap(struct node** left, struct node** right){
        struct node* temp = *left;
        *left = *right;
        *right = temp;
        }
struct node* mirror(struct node* root){
            if(root == NULL) return NULL;
             mirror(root->left);
             mirror(root->right);
             swap(&root->left,&root->right);
             return root;
}

void inOrder(struct node* node)
{
      if (node == NULL)
              return;
         
        inOrder(node->left);
          cout<<node->data;
           
            inOrder(node->right);
} 
 
 
/* Driver program to test mirror() */
int main()
{
      struct node *root = newNode(1);
        root->left        = newNode(2);
          root->right       = newNode(3);
            root->left->left  = newNode(4);
              root->left->right = newNode(5);
                 
                /* Print inorder traversal of the input tree */
                cout<<"\n Inorder traversal of the constructed tree is \n";
                  inOrder(root);
                     
                    /* Convert tree to its mirror */
                    mirror(root);
                       
                      /* Print inorder traversal of the mirror tree */
                      cout<<"\n Inorder traversal of the mirror tree is \n"; 
                        inOrder(root);
                        return 0; 
}

