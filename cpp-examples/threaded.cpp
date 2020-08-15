#include <iostream>

using namespace std;
struct tnode{
    int data;
    tnode* left;
    tnode* right;
};

void morrisTraversal(tnode* root){
    if(root == NULL)
        return;
    tnode* current;
    tnode* pre;
    current = root;
    while(current != NULL){
            if(current->left == NULL){
                cout<<current->data<<endl;
                current = current->right;
            }
            else {
                pre = current->left;
                while(pre->right != NULL && pre->right != current){
                    pre = pre->right;
                }
                if(pre->right == NULL){
                    pre->right = current;
                    current = current->left;
                }
                else {
                    pre->right = NULL;
                    cout<<current->data;
                    cout<<"This is impossible"<<endl;
                    current = current->right;
                }
            }
    }

}

tnode* create(int data){
    tnode* newNode = new tnode;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main(){
    tnode* root = create(1);
    root->left = create(2);
    root->right = create(3);
    root->left->left = create(4);
    root->left->right = create(5);
    morrisTraversal(root);
    return 0;
}
