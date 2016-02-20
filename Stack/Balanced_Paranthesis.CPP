//Compiled in Turbo C++.
//Author:Soumyadeep Jana
//Problem Statement-https://www.hackerrank.com/challenges/balanced-parentheses

#include<iostream.h>
#include<conio.h>
#include<stdio.h>

struct stud
{
    char data;
    stud *next;
};

stud * push(stud *,char);
stud * pop(stud *,char);
//void display(stud *);

void main()
{
    clrscr();
    stud *top = NULL;
    char str[20];
    int i;
    cout<<"Enter the paranthesis series:";
    gets(str);
    for(i=0;str[i]!=NULL;i++)
    {
       if(str[i]=='(' || str[i]=='{' || str[i]=='[')
	  top=push(top,str[i]);
       else
	  top=pop(top,str[i]);

    }
    if(top==NULL)
      cout<<"yes"<<endl;
    else
      cout<<"NO"<<endl;
    getch();
}


stud * push(stud *top,char ch)
{
    stud *node = new stud;
    if(node == NULL)
	cout<<"Memory overflow"<<endl;
    else
    {

	node->data=ch;
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


stud * pop(stud *top,char ch)
{



	//cout<<"Element deleted:"<<top->data<<endl;
	if((int)top->data==40 && (int)ch==41
	|| (int)top->data==123 && (int)ch==125
	||(int)top->data==91 && (int)ch==93)
	{
	  //cout<<top->data;
	  stud *temp = top;
	  top = top->next;
	  delete temp;
	}
       //	cout<<top->data<<endl;


    return top;
}


