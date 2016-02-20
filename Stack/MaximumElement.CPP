//Compiled in Turbo C++.
//Author-Soumyadeep Jana
//Problem Statement-https://www.hackerrank.com/challenges/maximum-element

#include<iostream.h>
#include<conio.h>
#include<process.h>

struct stud
{
   int data;
   stud *next;
};

stud * push(stud *top,int n)
{
    stud *node = new stud;
    if(node == NULL)
	cout<<"Memory overflow"<<endl;
    else
    {
	//cout<<"Enter data:";
	node->data=n;
	node->next = NULL;

	if(top == NULL)
	   top = node;
	else
	{
	     node->next = top;
	     top = node;
	}
    }
    return top;
}


stud * pop(stud *top)
{
    if(top == NULL)
       cout<<"Stack empty"<<endl;
    else
    {
	//cout<<"Element deleted:"<<top->data<<endl;
	stud *temp = top;
	top = top->next;
	delete temp;
    }
    return top;

}

void disp_max(stud *top)
{
   stud *ptr=top->next;;
   int max=top->data;

   while(ptr!=NULL)
   {
      if(ptr->data>max)
	 max=ptr->data;
      ptr=ptr->next;
   }

   cout<<max<<endl;
   getch();
}

void main()
{
    clrscr();
    stud *top = NULL;
    int op,times,n;
    cout<<"Enter no of times:";
    cin>>times;
    do
    {

	clrscr();
	cout<<"1.PUSH"<<endl;
	cout<<"2.Delete"<<endl;
	cout<<"3.DISPLAY"<<endl;
	cout<<"Enter your choice:";
	cin>>op;
	times--;

	switch(op)
	{
	     case 1:
		   clrscr();
		   cout<<"Enter the no:";
		   cin>>n;
		   top=push(top,n);
		   break;

	    case 2:
		  clrscr();
		  top=pop(top);
		  break;

	    case 3:
		  clrscr();
		  disp_max(top);
		  break;

	    default:
		   exit(0);
	}
    }while(times!=0);
}


