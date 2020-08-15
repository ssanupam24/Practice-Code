#include <iostream>
#include <stdlib.h>

using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* newNode(int data)
{
    struct node* newNode1 = new node;
    newNode1->data = data;
    newNode1->left = NULL;
    newNode1->right = NULL; 
    return(newNode1);
}

bool isBalanced(struct node* root, int* height){
    int lh = 0; 
    int rh =0;
    int l = 0;
    int r = 0;
    if(root == NULL){
        *height = 0;
        return 1;
    }
    l = isBalanced(root->left,&lh);
    r = isBalanced(root->right, &rh);
    *height = (lh > rh? lh: rh) + 1;
    if(abs(lh-rh) >= 2)
        return 0;
    else
        return (l && r);

}
 
int main()
{
  int height = 0;
    
  /* Constructed binary tree is
             1
           /   \
         2      3
       /  \    /
     4     5  6
    /
   7
  */   
  struct node *root = newNode(1); 
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6);
  root->left->left->left = newNode(7);
  root->left->left->left->left = newNode(12);
 
  if(isBalanced(root, &height))
    cout<<"Tree is balanced"<<endl;
  else
    cout<<"Tree is not balanced"<<endl;   

  return 0;
}
