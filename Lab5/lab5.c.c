#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct customer
{
	int customerID,arrtime,oprtime,leavetime,empID,check,waittime,lvcheck;
        struct customer *next;
	struct employee *emp;
	struct customer *prev;
};
struct employee
{
	int empID,worktime,donecheck;
	struct employee *next;
};
void create_que(struct customer **head,struct customer **endcus,int customerID,int arrtime,int oprtime);
void create_st(struct employee **head,int empID);
void print(struct employee *head_emp,struct customer *head_cus);
void bank(struct customer **head_cus,struct employee **head_emp,struct customer *endcus);
void push(int *list,struct employee ***heademp,struct customer ***headcus);

int main () 
{
	struct customer *head_cus=NULL;
	struct customer *endcus=NULL;
	struct employee *head_emp=NULL;
	int customerID,arrtime,oprtime,i;

	scanf("%d",&customerID);
	while(customerID!=-1)
	{
		scanf("%d",&arrtime);
		scanf("%d",&oprtime);		
		create_que(&head_cus,&endcus,customerID,arrtime,oprtime);
		scanf("%d",&customerID);
	}

	for(i=1;i<7;i++)
	{
		create_st(&head_emp,i);
	}	
	
	bank(&head_cus,&head_emp,endcus);
	print(head_emp,head_cus);


	return 0;
}

void create_que(struct customer **head,struct customer **endcus,int customerID,int arrtime,int oprtime)
{
	struct customer *ptr,*newnode;
	
	newnode=(struct customer*)malloc(sizeof(struct customer));
	newnode->customerID=customerID;
	newnode->arrtime=arrtime;
	newnode->oprtime=oprtime;
	newnode->check=0;
	newnode->leavetime=arrtime+oprtime;
	newnode->waittime=0;
	newnode->emp=NULL;
	*endcus=newnode;
	
	if(*head==NULL)
	{
		*head=newnode;
		newnode->next=NULL;
		newnode->prev=NULL;
	}
	else
	{
		ptr=*head;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=newnode;
		newnode->prev=ptr;
		newnode->next=NULL;
	}
}

void create_st(struct employee **head,int empID)
{
	struct employee *ptr,*newnode;
	
	newnode=(struct employee*)malloc(sizeof(struct employee));
	newnode->donecheck=1;
	
	if(*head==NULL)
	{
		newnode->empID=1;
		*head=newnode;
		newnode->next=NULL;
	}
	else
	{
		newnode->empID=empID;
		newnode->next=*head;
		*head=newnode;
	}
}

void print(struct employee *head_emp,struct customer *head_cus)
{
	struct employee *ptremp;
	struct customer *ptrcus;
	int i;
	ptremp=head_emp;
	ptrcus=head_cus;
	
	while(ptrcus!=NULL)
	{
		printf("%d %d %d %d %d\n",ptrcus->customerID,ptrcus->empID,ptrcus->arrtime,ptrcus->leavetime,ptrcus->waittime);
		ptrcus=ptrcus->next;
	}
	
	printf("\n");
	for(i=6;i>0;i--)
	{
		ptremp=head_emp;
		while(ptremp!=NULL)
		{
			if(i==ptremp->empID)
			{
				printf("%d %d\n",ptremp->empID,ptremp->worktime);				
				break;
			}
			ptremp=ptremp->next;
		}
	}
}

void bank(struct customer **head_cus,struct employee **head_emp,struct customer *endcus)
{
	struct employee *ptremp;
	struct customer *ptrcus;		
	int done=0,time=1,checkall=0,lvcheck=0;
	ptremp=*head_emp;
	ptrcus=*head_cus;
	int i,list[6];

	for(i=0;i<6;i++)
	{
		list[i]='-';
	}
	while(!done)
	{
		ptrcus=*head_cus;
		i=0;
		while(ptrcus!=NULL)
		{
			if(ptrcus->leavetime==time)
			{
				list[i++]=ptrcus->emp->empID;				
			}
			ptrcus=ptrcus->next;	
		}
		push(&list[0],&head_emp,&head_cus);
		ptrcus=*head_cus;		
		while(ptrcus!=NULL)
		{
			if(ptrcus->arrtime==time && *head_emp!=NULL && ptrcus->check==0)
			{
				ptrcus->emp=*head_emp;
				*head_emp=(*head_emp)->next;
				ptrcus->empID=ptrcus->emp->empID;
				ptrcus->check=1;
				ptrcus->emp->worktime+=ptrcus->oprtime;
				ptrcus->emp->donecheck=0;
			}
			if(*head_emp==NULL && ptrcus->arrtime==time && ptrcus->check==0)
			{
				ptrcus->waittime+=1;
				ptrcus->arrtime+=1;
				ptrcus->leavetime+=1;

			}
			ptrcus=ptrcus->next;
		}
		ptrcus=*head_cus;
		checkall=1;
		while(ptrcus!=NULL)
		{
				
			if(ptrcus->lvcheck==0)
			{				
				checkall=0;
				break;
			}
			ptrcus=ptrcus->next;			
		}
		ptrcus=*head_cus;				
		time+=1;
		if(checkall)
		{
			done=1;
		}
	}
}

void push(int *list,struct employee ***heademp,struct customer ***headcus)
{

	struct employee *minvalue;
	struct customer *ptr;
	int min,i=0,check=1,index,y=0;

	ptr=**headcus;
	if(list[0]!='-')
	{
		while(1)
		{
			ptr=**headcus;
			min=list[0];
			index=0;
			check=1;
			for(i=1;i<6;i++)
			{
				if(list[i]<min)
				{
					min=list[i];
					index=i;
				}
			}
			for(i=0;i<6;i++)
			{
				if(list[i]!='-')
				{
					check=0;
					break;
				}										
			}
			if(check)
			{
				break;
			}
			while(ptr!=NULL)
			{
				if(ptr->emp !=NULL)
				{	
					if(ptr->emp->empID == min && ptr->lvcheck==0)
					{
						ptr->lvcheck=1;
						ptr->emp->donecheck=1;
						ptr->emp->next=**heademp;
						**heademp=ptr->emp;
						list[index]='-';
					}
				}	
				ptr=ptr->next;
			}
		}	
	}
}
			
		
