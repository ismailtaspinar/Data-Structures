#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct tree{
    int id,data;
    struct tree *left,*right; 
};
void insert(struct tree **root,int id,int data);
void print(struct tree *root);
int levelCounter(struct tree *root);
void printLevel(struct tree *root,int level,int rootID,char way);

int main(){

    int id,data,levelCount,i;
    struct tree *root=NULL;

    scanf("%d",&id);
    while(id!=-1){
        scanf("%d",&data);
        insert(&root,id,data);
        scanf("%d",&id);
    }
    print(root);
    levelCount=levelCounter(root)+1;
    printf("\n");
    printf("%d %d\n",root->id,root->data);
    
    for(i=2;i<=levelCount;i++){
        
        printLevel(root,i,root->data,' '); 
        printf("\n");
    }
    return 0;
}

void insert(struct tree **root,int id,int data){

    struct tree *ptr,*newnode;
    newnode=(struct tree*)malloc(sizeof(struct tree));
    newnode->id=id;
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;

    if(*root==NULL){
        *root=newnode;
    }
    else{
        ptr=*root;
        while(1){
            
            if(newnode->data > ptr->data && ptr->right==NULL){
                ptr->right=newnode;
                break;
            }
            else if(newnode->data < ptr->data && ptr->left==NULL){
                ptr->left=newnode;
                break;
            }
            else if(newnode->data > ptr->data){
                ptr=ptr->right;
            }
            else if(newnode->data < ptr->data){
                ptr=ptr->left;
            }
            
        }
    }
}

void print(struct tree *root){
    if (root == NULL)
        return;
    
    print(root->left);
    printf("%d %d\n",root->id, root->data);
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
        printf("%d %d (%d %c) ",root->id,root->data,rootID,way);
    }
    
    else if(level>1){
        printLevel(root->left,level-1,root->data,'L');
        printLevel(root->right,level-1,root->data,'R');
    }
     
}