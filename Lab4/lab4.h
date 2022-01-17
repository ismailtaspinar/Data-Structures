struct nodeClass
{
	int classID;
	double classMidtermAverage;
	struct nodeClass *next;
	struct nodeStudent *studentPtr;
};

struct nodeStudent
{
	int studentID;
	int midterm;                    
	struct nodeStudent *next;
};


// You must write all the function definitions to be used in this lab into this file.
// You may also write other functions that may be called from our functions.
// Do not make any changes to the main.c file.
// Upload function.h file to the system as StudentNumber.h.


void insert(struct nodeClass** head,int id,int midterm)
{
  int clID=id/10000;
  int i,go=0;
  struct nodeClass *newclass,*preclass,*ptrclass;
  struct nodeStudent *newstudent,*prest,*ptrst,*nxt;
  int check=0;
  
  newstudent=(struct nodeStudent*)malloc(sizeof(struct nodeStudent));
 

  if(*head==NULL)
  {
     newclass=(struct nodeClass*)malloc(sizeof(struct nodeClass));
     *head=newclass;
     newclass->classID=6;
     newclass->studentPtr=NULL;
     ptrclass=*head;                         //create nodeclasses and link them for the first input.
     
     for(i=7;i<10;i++)
     {
        newclass=(struct nodeClass*)malloc(sizeof(struct nodeClass));
        newclass->classID=i;
        newclass->studentPtr=NULL;
        ptrclass->next=newclass;
        ptrclass=ptrclass->next;
     }
     ptrclass->next=NULL;
     
  }
 
  ptrclass=*head;
  while(ptrclass != NULL)
  {  
     ptrst=ptrclass->studentPtr;    //iterating classes.
     if(ptrclass->classID==clID)  
     {
       
       if(ptrclass->studentPtr==NULL)
       {
         newstudent->studentID=id;
         newstudent->midterm=midterm;           
         ptrclass->studentPtr=newstudent;
         newstudent->next=NULL;
         break;
       }
       
     else
       {
          while(ptrst!=NULL)  //iterating students in associated class.
          {
              if(midterm > ptrst->midterm || ((midterm == ptrst->midterm) && (id < ptrst->studentID)))
              {
                   if(ptrst==ptrclass->studentPtr)
                   {
                      newstudent->studentID=id;
                      newstudent->midterm=midterm;
                      newstudent->next=ptrst;  
                      ptrclass->studentPtr=newstudent;  //placing start or middle before the ptrst node.
                      check=1;
                      break;
                   }
                
                   else
                   {
                      newstudent->studentID=id;
                      newstudent->midterm=midterm;
                      prest->next=newstudent;
                      newstudent->next=ptrst;
                      check=1;
                      break;
                   }
              }
              else if((midterm == ptrst->midterm) && (id > ptrst->studentID))  //placing middle or end.
              {
                   if(ptrst->next == NULL)
                   {
                      newstudent->studentID=id;
                      newstudent->midterm=midterm;
                      ptrst->next=newstudent;
                      newstudent->next=NULL;
                      check=1;
                      break;
                   }
                   else
                   {
                      newstudent->studentID=id;
                      newstudent->midterm=midterm;
                      nxt=ptrst->next;
                      ptrst->next=newstudent;
                      newstudent->next=nxt;
                      check=1;
                      break;
                   }
                      
              }     
              if(ptrst->next==NULL) //placing end.
              {
                   newstudent->studentID=id;
                   newstudent->midterm=midterm;
                   ptrst->next=newstudent;
                   newstudent->next=NULL;
                   check=1;
                   break;
              }

              prest=ptrst;
              ptrst=ptrst->next;
        
          }
        }
     }
     if(check)
     {
        break;
     }
     ptrclass=ptrclass->next;
  }
}

void computeClassAverage(struct nodeClass* head)
{
   struct nodeClass *ptrclass;
   struct nodeStudent *ptrst;
   ptrclass=head;
   double sum=0.0,count=0.0;

   ptrst=ptrclass->studentPtr;
   while(ptrclass!=NULL)
   {  
      ptrst=ptrclass->studentPtr;
      while(ptrst!=NULL)
      {
          sum+=ptrst->midterm;
          count++;
          ptrst=ptrst->next;
      }
      ptrclass->classMidtermAverage=sum/count;
      sum=0;
      count=0;
      ptrclass=ptrclass->next;
   }

}

void printAll(struct nodeClass* head)
{
   struct nodeClass *ptrclass;
   struct nodeStudent *ptrst;
   ptrclass=head;
   
   int y=0;
   ptrst=ptrclass->studentPtr;
   while(ptrclass!=NULL)
   {  
      printf("%d %.2f\n",(ptrclass->classID)-5,ptrclass->classMidtermAverage);
      ptrst=ptrclass->studentPtr;
      while(ptrst!=NULL)
      {
          printf("%d %d\n",ptrst->studentID,ptrst->midterm);
          ptrst=ptrst->next;
      }
      ptrclass=ptrclass->next;
   }
}
