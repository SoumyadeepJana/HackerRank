#include<iostream.h>
#include<conio.h>


struct cookie
{
   int sweetness;
   cookie *next;
}*front=NULL,*rear=NULL;


void enqueue()
{
   cookie *node=new cookie;

   if(node==NULL)
      cout<<"Memory error"<<endl;
   else
   {
      cout<<"Enter sweetness level:";
      cin>>node->sweetness;
      node->next=NULL;

      if(front==NULL)
      {
	 front=rear=node;

      }

      else
      {
	 rear->next=node;
	 rear=node;

      }
   }
}




void sort()
{
   cookie *ptr=front;
   cookie *qtr=front;
   int count=0,i,j;

   while(ptr!=NULL)
   {
     count++;
     ptr=ptr->next;
   }
   ptr=front;

   for(i=0;i<count-1;i++)
   {

      for(j=0;j<count-1-i;j++)
      {
	 if(ptr->sweetness>ptr->next->sweetness)
	    {
	       int temp=ptr->sweetness;
	       ptr->sweetness=ptr->next->sweetness;
	       ptr->next->sweetness=temp;
	    }
	    ptr=ptr->next;
      }
      qtr=qtr->next;
      ptr=qtr;
   }
}

int process(int &c)

{  c++;
   int res=front->sweetness+2*front->next->sweetness;
   front=front->next->next;
   return res;
}


void main()
{
   clrscr();
   int n,i,k,res,c=0;
   cout<<"Enter the total no of cookies:";
   cin>>n;
   cout<<"Enter the desired sweetness level:";
   cin>>k;

   for(i=0;i<n;i++)
     enqueue();
   sort();

   cookie *ptr=front;
   while(ptr!=NULL)
   {
     cout<<ptr->sweetness<<endl;
     ptr=ptr->next;
   }
   ptr=front;

   while(ptr->next->next!=NULL)
   {
       res=process(c);
       if(res>=k)
	 break;
       else
	 sort();
   }
   cout<<"no of operations required:"<<c<<endl;
   getch();
}
