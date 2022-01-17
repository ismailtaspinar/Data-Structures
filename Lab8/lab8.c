#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct tree{
    int value,color;
    struct tree *parent,*left,*right;
};

struct tree *root=NULL;

struct tree *insert(struct tree *head,struct tree *node){
    if (head == NULL)
        return node;
 
    
    if (node->value < head->value)
    {
        head->left = insert(head->left, node);
        head->left->parent = head;
    }
    else if (node->value > head->value)
    {
        head->right = insert(head->right, node);
        head->right->parent = head;
    }
 
   
    return head;
}
void rightrotate(struct tree* temp)
{
    struct tree* left = temp->left;
    temp->left = left->right;
    if (temp->left)
        temp->left->parent = temp;
    left->parent = temp->parent;
    if (!temp->parent)
        root = left;
    else if (temp == temp->parent->left)
        temp->parent->left = left;
    else
        temp->parent->right = left;
    left->right = temp;
    temp->parent = left;
}
 

void leftrotate(struct tree* temp)
{
    struct tree* right = temp->right;
    temp->right = right->left;
    if (temp->right)
        temp->right->parent = temp;
    right->parent = temp->parent;
    if (!temp->parent)
        root = right;
    else if (temp == temp->parent->left)
        temp->parent->left = right;
    else
        temp->parent->right = right;
    right->left = temp;
    temp->parent = right;
}
void fix(struct tree* head, struct tree* ptr)
{
    struct tree* parent_ptr = NULL;
    struct tree* grand_parent_ptr = NULL;
 
    while ((ptr != head) && (ptr->color != 0) && (ptr->parent->color == 1))
    {
        parent_ptr = ptr->parent;
        grand_parent_ptr = ptr->parent->parent;
 
        if (parent_ptr == grand_parent_ptr->left)
        {
            struct tree* uncle_ptr = grand_parent_ptr->right;
 
            if (uncle_ptr != NULL && uncle_ptr->color == 1)
            {
                grand_parent_ptr->color = 1;
                parent_ptr->color = 0;
                uncle_ptr->color = 0;
                ptr = grand_parent_ptr;
            } 
            else {

                if (ptr == parent_ptr->right) {
                    leftrotate(parent_ptr);
                    ptr = parent_ptr;
                    parent_ptr = ptr->parent;
                }
                rightrotate(grand_parent_ptr);
                int t = parent_ptr->color;
                parent_ptr->color = grand_parent_ptr->color;
                grand_parent_ptr->color = t;
                ptr = parent_ptr;
            }
        }
 
        else {
            struct tree* uncle_ptr = grand_parent_ptr->left;

            if ((uncle_ptr != NULL) && (uncle_ptr->color == 1))
            {
                grand_parent_ptr->color = 1;
                parent_ptr->color = 0;
                uncle_ptr->color = 0;
                ptr = grand_parent_ptr;
            }
            else {
                if (ptr == parent_ptr->left) {
                    rightrotate(parent_ptr);
                    ptr = parent_ptr;
                    parent_ptr = ptr->parent;
                }
                
                leftrotate(grand_parent_ptr);
                int t = parent_ptr->color;
                parent_ptr->color = grand_parent_ptr->color;
                grand_parent_ptr->color = t;
                ptr = parent_ptr;
            }
        }
    }
 
    root->color = 0;
}
void print(struct tree *root){
    if (root == NULL)
        return;
    
    print(root->left);
    printf("%d\n",root->value);
    print(root->right);
}
int levelCounter(struct tree *root){
    if (root == NULL)
        return -1;
    else
    {
        int leftCount = levelCounter(root->left);
        int rightCount = levelCounter(root->right);

        if (leftCount >= rightCount)
            return(leftCount + 1);
        else return(rightCount + 1);
    }
    
}
void printLevel(struct tree *root,int level,int rootID,char way){
    
    if(root==NULL){
        return ;
    }
    
    if(level==1){
        printf("%d %c (%d %c) ",root->value,(root->color == 1 ? 'R' : 'B'),rootID,way);
    }
    
    else if(level>1){
        printLevel(root->left,level-1,root->value,'L');
        printLevel(root->right,level-1,root->value,'R');
    }
     
}

int main(){

    struct tree *newnode=NULL;
    int value,levelCount,i;
    scanf("%d",&value);
    while(value!=-1){
        newnode=(struct tree*)malloc(sizeof(struct tree));
        newnode->value=value;
        newnode->color=1;
        newnode->left=NULL;
        newnode->right=NULL;
        newnode->parent=NULL;
        root=insert(root,newnode);
        fix(root,newnode);
        scanf("%d",&value);
    }
    
    print(root);
    levelCount=levelCounter(root)+1;
    printf("\n%d %c\n",root->value,(root->color == 1 ? 'R' : 'B'));

    for(i=2;i<=levelCount;i++){
        
        printLevel(root,i,root->value,' '); 
        printf("\n");
    }


    return 0;
}