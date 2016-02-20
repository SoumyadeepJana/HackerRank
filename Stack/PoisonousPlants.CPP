#include<iostream.h>
#include<conio.h>
#include<stdio.h>


struct plant
{
   int poison;
   plant *next;
};

int traverse(plant *head,int &count)
{
    plant *ptr=head->next;
    plant *prev=head;
    int stat=0,t=0;

    while(ptr!=NULL)
    {
	if(ptr->poison>prev->poison)
	{
	    plant *temp=ptr;
	    prev->next=ptr->next;
	    delete temp;
	    stat++;
	    t++;
	}
	if(t>0)
	  ptr=prev->next;
	else
	{
		prev=ptr;
		ptr=ptr->next;
	}
	t=0;
    }

    if(stat>0)
    {
	   count++;
	   return 1;
    }
    return 0;


}


plant * append(plant *head)
{
   plant *node=new plant;

   if(node==NULL)
       cout<<"Memory error"<<endl;
   else
   {
      cout<<"Enter the poison level:";
      cin>>node->poison;
      node->next=NULL;

      if(head==NULL)
	 head=node;
      else
      {
	 plant *ptr=head;
	 while(ptr->next!=NULL)
	    ptr=ptr->next;
	 ptr->next=node;
      }
   }
   return head;
}


void main()
{
   clrscr();
   plant *head=NULL;
   int n,i,count=0,flag=1;
   cout<<"Enter the no of plants:";
   cin>>n;
   for(i=0;i<n;i++)
   {
      head=append(head);
   }

   while(flag)
   {
      flag=traverse(head,count);
   }
   cout<<"The day after all plants stop dying:"<<count;

   getch();
}
