#include<iostream.h>
#include<conio.h>
#include<stdio.h>

struct truck
{
   int tank;
   int dist;
   truck *next;
}*front=NULL,*rear=NULL;


void enqueue()
{
   truck *node=new truck;

   if(node==NULL)
      cout<<"Memory error"<<endl;
   else
   {
      cout<<"Enter tank capacity:";
      cin>>node->tank;
      cout<<"Enter next pump distance:";
      cin>>node->dist;
      node->next=NULL;

      if(front==NULL)
      {
	 front=rear=node;
	 rear->next=front;
      }

      else
      {
	 rear->next=node;
	 rear=node;
	 rear->next=front;
      }
   }
}

truck * traverse(truck *ptr)
{
   truck *qtr=ptr;
   int capacity=ptr->tank;;

   do
   {

	if(capacity>=qtr->dist)
	{
	   qtr=qtr->next;
	   capacity-=qtr->dist;
	   capacity+=qtr->tank;

	}
	else
	  return NULL;

   }while(qtr!=ptr);

   return ptr;

}

void main()
{
   clrscr();
   int n,i;
   truck *temp;
   cout<<"Enter the no of pumps:";
   cin>>n;
   for(i=0;i<n;i++)
     enqueue();

   truck *ptr=front;

   do
   {
      temp=traverse(ptr);
      if(!temp)
	ptr=ptr->next;
      else
	break;
   }while(ptr!=front);

   if(temp==NULL)
     cout<<"No such pump present"<<endl;
   else
     cout<<"we can start the journey from:"<<ptr->tank<<endl;

   getch();
}
