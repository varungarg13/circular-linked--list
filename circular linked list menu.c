#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int info;
	struct node *next;
}node;
node * getnode(int);
node * AddBefore(node *,int,int);
node * AddAfter(node *,int,int);
node * AddFirst(node *,int);
node * AddLast(node *,int);
node * DelNode(node *,int);
void Traverse(node *);
int count(node *);
node *freeall(node *);
int main()
{
	node *start=NULL;
	int item,num,ch,C=0;
	do{
		system("cls");
		printf("\n1. AddBefore\n2. AddAfter\n3. AddFirst\n4. AddLast\n5. DelNode\n6. Traverse\n7. Count\n8.Exit \nEnter your choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1:
			 	   printf("\nEnter the number you want to add and number to addBefore :");
				   scanf("%d%d",&item,&num);
				   start=AddBefore(start,item,num);
				   break;
			case 2:
					printf("\nEnter the number you want to add and number to addAfter :");
				   scanf("%d%d",&item,&num);
				   start=AddAfter(start,item,num);
				   break;
		    case 3:
					printf("\nEnter the number you want to addFirst :");
				   scanf("%d",&item);
				   start=AddFirst(start,item);
				   break;
			case 4:
					printf("\nEnter the number you want to addLast :");
				   scanf("%d",&item);
				   start=AddLast(start,item);
				   break;
			case 5:
					printf("\nEnter the number you want to Delete :");
				   scanf("%d",&item);
				   start=DelNode(start,item);
				   break;
			case 6:
				   Traverse(start);
				   break;
			case 7:
				   C=count(start);
				   printf("\nThe count is =%d",C);
				   break;
			case 8:
					freeall(start);
					break;
			default:
			printf("\nEnter a valid input!");
		}
		getch();
	}while(ch!=8);
	return 0;	
}
node * getnode(int item){
	node *t=(node *)malloc(sizeof(node));
	t->info=item;
	return t;	
}
node * AddBefore(node *start,int item,int num)
{
 node *newnode,*ptr,*preptr;
 ptr=start->next;
 preptr=start;
 if(start==NULL)
 {
 	printf("\nThere is %d list\n",num);
 }
 newnode=getnode(item);
 	do{
 		if(ptr->info==num)
 		{
			 break;
			 }	
		preptr=ptr;
		ptr=ptr->next;
		
	 }while(ptr!=start->next);
		
		if(ptr->info!=num)
		{
			printf("!!!");
			return start;
		}
		
		newnode->next=ptr;
		preptr->next=newnode;
		
 return start;
}
node * AddAfter(node *start,int item,int num)
{
 node *newnode,*ptr;
 newnode=getnode(item);
 if(start==NULL)
 {
 	printf("\nThere is no list!",num);
 }
 ptr=start->next;
 
 do
 {
 	if(ptr->info==num){
 	break;
  }
  ptr=ptr->next;
}while(ptr!=start->next);
if(ptr->info!=num)
{
	printf("\nThe %d was not not found in the list! ",num);
}
	newnode->next=ptr->next;
  	ptr->next=newnode;
  	if(ptr==start)
  	{
  		start=newnode;
	  }
 return start;
}

node * AddFirst(node *start,int item)
{
	node *ptr,*newnode;
	newnode=getnode(item);
	if(start==NULL)
	{
		newnode->next=newnode;
		start=newnode;
	}
	else{
		
	ptr=start->next;
	newnode->next=ptr;
	start->next=newnode;
	}
	return start;
	
}
node * AddLast(node *start,int item)
{
	node *ptr,*newnode;
	newnode=getnode(item);
	ptr=start->next;
	//newnode->next=NULL;
	if(start==NULL)
	{
		newnode->next=newnode;
		start=newnode;
	}
	else{
		newnode->next=start->next;
		start->next=newnode;
		start=newnode;
	}
	return start;	
}
node * DelNode(node *start,int item){
	node *preptr,*ptr;
	preptr=start;
	ptr=start->next;
	do
	{
		preptr=ptr;
		ptr=ptr->next;
	}while(ptr!=start->next && ptr->info!=item);
	if(ptr==start->next)
	{
		printf("%d not found in list",item);
		return start;
	}
	if(ptr==start)
	{
		start=start->next;
	}
	else{
		preptr->next=ptr->next;
	}
	return start;
}
void Traverse(node *start)
{
	node *ptr;
	ptr=start->next;
	printf("\nThe list is: ");
	do
	{
		printf("%d\t",ptr->info);
		ptr=ptr->next;
	}while(ptr!=start->next);
	printf("\n");	
}
int count(node *start)
{
	int count=0;
	node *ptr;
	ptr=start;
	while(ptr!=NULL)
	{
		ptr=ptr->next;
		count++;
	}
	return count;
}
node *freeall(node *start)
{
	node *ptr;
	ptr =start;
	while(start!=NULL)
	{
		ptr=start;
		start=start->next;
		free(ptr);
	}
	return start;
}


