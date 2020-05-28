#include<stdio.h>
#include<stdlib.h>
#define limit 10
int i=0;
struct node
{
int uniqno;
int data;
struct node *link;
};
struct node *start=NULL;
void display()
{
if(start==NULL)
{
printf("ALL SEATS EMPTY");
}
else
{
    struct node*q=start;
    printf("unique user id\t aadhar number\n");
  while(q!=NULL)
   {
    printf("%d\t",q->uniqno);
	printf("\t%d\n",q->data);
	printf("\n");
    q=q->link;
  }
}
}
int length()
{
 int count=0;
 struct node *p;
 p=start;
 while(p!=NULL)
  {
   count++;
   p=p->link;
  }
return count;
}
void cancel()
{
struct node *root=start;
struct node *p;
int uniqid;
int len = length();
printf("enter the uniqid to cancel\n");
scanf("%d",&uniqid);
if(uniqid>i)
{
printf("enter valid id");
}
else
{
while(root->uniqno!=uniqid)
{
p=root;
root=root->link;
}
p->link=root->link;
free(root);
printf("ticket cancelled successfully");
}
}

struct node *read()
{
struct node *temp,*root=start,*details;
int data;
temp=(struct node*)malloc(sizeof(struct node));
printf("Enter your aadhar number(without spacing)\n");
scanf("\n%d",data);
printf("\nyour booking is accepted");
printf("\nyour unique user id is %d\n",++i);
printf("\nremember your uuid for further use\n\nHAVE A SAFE JOURNEY\n\n");
temp->uniqno=i;
temp->data=data;
temp->link=NULL;
details=temp;
return details;
}
void book()
{
struct node *p, *q;
p=read();
 if(start==NULL)
  {
   start=p;
  }
 else
  {
   q=start;
    while(q->link!=NULL)
     {
      q=q->link;
     }
   q->link=p;
  }
}

void main()
{
int i,ch;
do
{
printf("\n\n\tRAILWAY RESERVATION\n\n");
printf("\n1.Display\n\n 2.Book a ticket\n\n 3.Cancel a ticket\n\n 4.exit\n\n");
printf("Kindly Enter your choice\t\t");
scanf("%d",&ch);
switch(ch)
{

case 1:display();
       break;
case 2:
if (length()< limit)
        {
	int i=0;
        book(++i);	
        }
        else if(length()>=limit)
        {
            printf("\nTRAIN FULL\n");
        }
       break;
case 3:cancel();
       break;
case 4:exit(0);
       break;
default: printf("invalid entry\n");
         break;
}
}while(ch!=4);
}

