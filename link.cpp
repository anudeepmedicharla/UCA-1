#include <iostream>
#include <stdlib.h>
using namespace std;
struct node
{
	int data;
	struct node *next;
};

struct node *start = NULL;
struct node *n1;

void create()
{
	int a;
	n1= new struct node;
	cout<<"Enter the value you want to insert in node: ";
	cin>>a;
	n1->data=a;
	n1->next=NULL;
}

void insertbeg()
{
	create();
	if(start==NULL)
	{
		start=n1;
	}
	else
	{
		n1->next=start;
		start=n1;
	}
}

void insertend()
{
	create();
	if(start==NULL)
	{
		start=n1;
	}
	else
	{
		struct node *ptr;
		ptr=start;
		while(ptr->next != NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=n1;
	}
}
void insertmid()
{
	create();
	int a;
	if(start==NULL)
	{
		start=n1;
	}
	else
	{
		cout<<"Enter the value after which you want to insert: ";
		cin>>a;
		struct node *ptr;
		ptr=start;
		while(ptr->data != a && ptr->next != NULL)
		{
			ptr=ptr->next;
		}
		n1->next=ptr->next;
		ptr->next=n1;
	}
}
void deletebeg()
{
	if(start==NULL)
	{
		cout<<"List is empty.";
	}
	else
	{
		struct node *ptr;
		ptr=start;
		start=ptr->next;
		delete(ptr);
	}
}
void deleteend()
{
	if(start==NULL)
	{
		cout<<"List is empty.";
	}
	else
	{
		struct node *ptr1, *ptr2;
		ptr1=start;
		ptr2=ptr1->next;
		while(ptr2->next != NULL)
		{
			ptr2=ptr2->next;
			ptr1=ptr1->next;
		}
		ptr1->next = NULL;
		delete(ptr2);
	}
}
void display()
{
	struct node *ptr;
	ptr=start;
	cout<<endl<<"list is:"<<endl;
	while(ptr!=NULL)
	{
		cout<<" "<<ptr->data;
		ptr=ptr->next;
	}
	cout<<endl;
}
void search()
{
	int a, c=1;
	cout<<"enter the value you want to search: ";
	cin>>a;
	struct node *ptr;
	ptr=start;
	while(ptr->next!=NULL && ptr->data!=a)
	{
		ptr=ptr->next;
		c++;
	}
	if(ptr->next==NULL)
	{
		cout<<"Value not found"<<endl;
	}
	if(ptr->data==a)
	{
		cout<<"Value "<<a<<" found at postion "<<c<<endl;
	}

}
void sort()
{
	struct node *ptr1, *ptr2;
	ptr1=start;
	int temp;
	while(ptr1!=NULL)
	{
		ptr2=ptr1->next;

		while(ptr2!=NULL)
		{
			if(ptr1->data>ptr2->data)
			{
				temp=ptr1->data;
				ptr1->data=ptr2->data;
				ptr2->data=temp;
			}
			ptr2=ptr2->next;
		}
		ptr1=ptr1->next;
	}
}
void unique()
{
	struct node *ptr1, *ptr2;
	ptr1=start;
	ptr2=ptr1->next;
	while(ptr1->next!=NULL)
	{
		if(ptr1->data == ptr2->data)
		{
			ptr1->next = ptr2->next;
			delete(ptr2);
			ptr2=ptr2->next;
		}
		else
		{	
			ptr1=ptr1->next;
			ptr2=ptr2->next;
		}
	}

}

int main()
{
	int n;
while(1)
{
	cout<<endl<<"1.Insert at beg"<<endl<<"2.Insert at end"<<endl<<"3.Insert at given value"<<endl<<"4.Deletion of 1st value"<<endl<<"5.Deletion of last value"<<endl<<"6.Display list"<<endl<<"7.Search"<<endl<<"8.Sort"<<endl<<"9.Unique"<<endl<<"10.Exit"<<endl<<"Enter Choice:";
	cin>>n;
	switch(n)
		{
			case 1: insertbeg();
					break;
			case 2: insertend();
					break;
			case 3: insertmid();
					break;
			case 4: deletebeg();
					break;
			case 5: deleteend();
					break;
			case 6: display();
					break;
			case 7: search(); 
					break;
			case 8: sort();
					break;
			case 9: unique();
					break;
			case 10: exit(0);
		}
}
return 0;
}