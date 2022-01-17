struct nodeFB
{
	int id;
	int age;
	struct nodeFB *next;
};

struct nodeGS
{
	int id;
	struct nodeGS *next;
};

struct newNodeFB
{
	int id;
	int age;
	struct newNodeGS *next;
};

struct newNodeGS
{
	int id;
	struct newNodeFB *next;
};

// You need to write all the function definitions to be used in this lab in this file.
// You can call other functions that you define from the mandatory functions.
// Do not make any changes to the main.c file.
// Upload the file function.h to the system as StudentNumber.h. 

void insertGS(struct nodeGS **startGS,int id){
     struct nodeGS *newnode,*ptr,*preptr;
     newnode=(struct nodeGS*)malloc(sizeof(struct nodeGS));
     ptr=*startGS;
     
     if(*startGS == NULL){
          
          newnode->id=id;
          newnode->next=*startGS;
          *startGS=newnode;
     }

     else{
         while(ptr != NULL){
             if(id > ptr->id){
                if(*startGS==ptr){
                    newnode->id=id;
                    newnode->next=*startGS;
                    *startGS=newnode;
                    break;
                 }
                 else{
                    newnode->id=id;
                    preptr->next=newnode;
                    newnode->next=ptr;
                    break;
                 }
             }
             if(ptr->next==NULL){
                    newnode->id=id;
                    ptr->next=newnode;
                    newnode->next=NULL;
                    break;
             }
             preptr=ptr;
             ptr=ptr->next;
        }
    }
}  

void insertFB(struct nodeFB **startFB,int id,int age){
     struct nodeFB *newnode,*ptr,*preptr;
     newnode=(struct nodeFB*)malloc(sizeof(struct nodeFB));
     ptr=*startFB;
     
     if(*startFB == NULL){
          
          newnode->id=id;
          newnode->age=age;
          newnode->next=*startFB;
          *startFB=newnode;
     }
     else{
          while(ptr != NULL){
             if(id < ptr->id){
                 if(*startFB==ptr){
                    newnode->id=id;
                    newnode->age=age;
                    newnode->next=*startFB;
                    *startFB=newnode;
                    break;
                 }
                 else{
                    newnode->id=id;
                    newnode->age=age;
                    preptr->next=newnode;
                    newnode->next=ptr;
                    break;
                 }
             }
             if(ptr->next==NULL){
                    newnode->id=id;
                    newnode->age=age;
                    ptr->next=newnode;
                    newnode->next=NULL;
                    break;
             }
             preptr=ptr;
             ptr=ptr->next;
       }
     }
}

void printFB(struct nodeFB *startFB){
     struct nodeFB *ptr;
    
     ptr=startFB;

     while(ptr!=NULL){
          printf("%d %d\n",ptr->id,ptr->age);
          ptr=ptr->next;
     }
     printf("\n");
}

void printGS(struct nodeGS *startGS){
     struct nodeGS *ptr;
    
     ptr=startGS;

     while(ptr !=NULL){
          printf("%d\n",ptr->id);
          ptr=ptr->next;
     }
     printf("\n");
}

void createFinalList(struct newNodeFB **startNewFB,struct nodeFB *startFB,struct nodeGS *startGS){

    struct newNodeFB *newnodeFB;
    struct newNodeGS *newnodeGS;
    struct nodeFB *ptrFB;
    struct nodeGS *ptrGS;

    ptrFB=startFB;
    ptrGS=startGS;
    newnodeFB=(struct newNodeFB*)malloc(sizeof(struct newNodeFB));
    
    *startNewFB=newnodeFB;

    while(ptrFB != NULL && ptrGS != NULL){
         
         newnodeGS=(struct newNodeGS*)malloc(sizeof(struct newNodeGS));
         
         newnodeFB->id=ptrFB->id;
         newnodeFB->age=ptrFB->age;
         newnodeFB->next=newnodeGS;
         
         newnodeGS->id=ptrGS->id;
         ptrFB=ptrFB->next;
         newnodeFB=(struct newNodeFB*)malloc(sizeof(struct newNodeFB));
         newnodeGS->next=newnodeFB;
         ptrGS=ptrGS->next;
    }
    newnodeFB=NULL;
}

void printAll(struct newNodeFB *startNewFB){

    struct newNodeFB *ptrFB;
    struct newNodeGS *ptrGS;
    ptrFB=startNewFB;
    ptrGS=ptrFB->next;

    while(ptrGS!=NULL){
        printf("%d %d\n",ptrFB->id,ptrFB->age);
        printf("%d\n",ptrGS->id);
        ptrFB=ptrGS->next;
        ptrGS=ptrFB->next;
    }
} 
