#include<stdio.h>
#include<stdlib.h>

struct tree{
    int value,balance;
    struct tree *left,*right;
    int height;
};
int max(int a, int b);
int max(int a, int b)
{
    return (a > b)? a : b;
}
struct tree *newNode(int value)
{
    struct tree *newnode = (struct tree*)malloc(sizeof(struct tree));
    newnode->value = value;
    newnode->left   = NULL;
    newnode->right  = NULL;
    newnode->height = 1; 
    return(newnode);
}
int height(struct tree *root)
{
    if (root == NULL)
        return 0;
    return root->height;
}
int getBalance(struct tree *root)
{
    if (root == NULL)
        return 0;
    return height(root->left) - height(root->right);
}
struct tree *rightRotate(struct tree *y)
{
    struct tree *x = y->left;
    struct tree *T2 = x->right;
 
    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    return x;
}
struct tree *leftRotate(struct tree *x)
{
    struct tree *y = x->right;
    struct tree *T2 = y->left;
 
    y->left = x;
    x->right = T2;
 
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
 
    return y;
}
struct tree *insert(struct tree *root,int value){
  
    if (root == NULL){
        return(newNode(value));
    }
    if (value < root->value){
        root->left  = insert(root->left,value);
    }
    else if (value > root->value){
        root->right = insert(root->right,value);
    }

    root->height = 1 + max(height(root->left),height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && value < root->left->value)
        return rightRotate(root);
 
    
    if (balance < -1 && value > root->right->value)
        return leftRotate(root);
 
    
    if (balance > 1 && value > root->left->value)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && value < root->right->value)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
                           
}
void print(struct tree *root){
    if (root == NULL)
        return;
    
    print(root->left);
    printf("%d\n",root->value);
    print(root->right);
}
void balanceCounter(struct tree *root){
    if (root == NULL)
        return;
    
    balanceCounter(root->left);
    root->balance = getBalance(root);
    balanceCounter(root->right);
}
void printLevel(struct tree *root,int level,int rootID,char way){
    
    if(root==NULL){
        return ;
    }
    
    if(level==1){
        printf("%d (%d %c) (%d B) ",root->value,rootID,way,root->balance);
    }
    
    else if(level>1){
        printLevel(root->left,level-1,root->value,'L');
        printLevel(root->right,level-1,root->value,'R');
    }
     
}

int main(){

    struct tree *root=NULL;
    int value,levelCount,i;

    scanf("%d",&value);
    while(value!=-1){
        root=insert(root,value);
        scanf("%d",&value);
    }
    print(root);
    printf("\n");
    balanceCounter(root);
    printf("%d (%d B)\n",root->value,root->balance);
    
    levelCount=height(root);
    for(i=2;i<=levelCount;i++){
        
        printLevel(root,i,root->value,' '); 
        printf("\n");
    }

    return 0;
}




