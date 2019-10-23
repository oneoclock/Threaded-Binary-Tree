#include <iostream.h>
#include <process.h> //cstdlib
//using namespace std;

class node
{
public:
	node *left, *right;
	int lbit, rbit;
	int data;
};

class tbt
{
public:
	node *root;
	node *dummy;
	tbt()
		{
				root=NULL;
				dummy=NULL;
		}
	void create(int);
	void insert(node *, node*);
	void inorder();
	void preorder();
	void postorder();
	void display();
	void control();
};

void tbt :: create(int num)
{
	node *temp;
	node *trav;
	temp= new node;
	temp->data=num;
	temp->lbit=0;
	temp->rbit=0;
	if (root==NULL)
	{
		dummy=new node;
		dummy->data=9999;
		dummy->lbit=1;
		dummy->rbit=1;
		dummy->left=temp;
		dummy->right=dummy;
		temp->left=dummy;
		temp->right=dummy;
		root=temp;
	}
	else
	{
		trav=root;
		insert(trav, temp);
	}
}

void tbt :: insert(node *trav, node *temp)
{
	if(temp->data<trav->data)
	{
		if(trav->lbit==0)
		{
			temp->left=trav->left;
			temp->right=trav;
			trav->left=temp;
			trav->lbit=1;
		}
		else
		{
			insert(trav->left,temp);
		}
	}
	if(temp->data>trav->data)
	{
		if(trav->rbit==0)
		{
			temp->right=trav->right;
			temp->left=trav;
			trav->right=temp;
			trav->rbit=1;
		}
		else
			insert(trav->right,temp);
	}
}

void tbt :: preorder()
{
	node *trav=root;
	cout<<endl;
	if(trav==NULL)
		cout<<"TBT is empty.";
	else
	{
		while(trav!=dummy)
		{
			cout<<"\n"<<trav->data<<" ";
			if(trav->lbit==1)
			{
				trav=trav->left;
			}
			else
			{
				while(trav->rbit==0 && trav->right!=dummy)
				{
					trav=trav->right;
				}
				trav=trav->right;
			}
		}
	}
}

void tbt :: inorder()
{
	node *trav=root;
	cout<<endl;
	if (trav==NULL)
	{
		cout<<"TBT is empty!";
	}
	else
	{
		while(trav!=dummy)
		{
			while (trav->lbit==1)
			{
				trav=trav->left;
			}
			cout<<"\n"<<trav->data<<endl;
			while(trav!=dummy)
			{
				if(trav->rbit==1)
				{
					trav=trav->right;
					while(trav->lbit==1)
					{
						trav=trav->left;
					}
					cout<<trav->data<<endl;
				}
				else
				{
					while(trav->rbit==0)
					{
						trav=trav->right;
						if(trav==dummy)
						break;
						cout<<trav->data<<endl;

					}
				}
			}
		}
	}
}

void tbt :: postorder()
{
	node *trav=root;
	int i=0, a[20], n;
	if(trav==NULL)
	cout<<"TBT is Empty";
	else
	{
		while(trav!=dummy)
		{
			a[i]=trav->data;
			i++;
			if(trav->rbit==1)
			{
				trav=trav->right;
			}
			else
			{
				while(trav->lbit==0 && trav->left!=dummy)
				{
					trav=trav->left;
				}
				trav=trav->left;
			}
		}
	}
	n=i;
	n--;
	for(i=n;i>=0;i--)
	cout<<"\n"<<a[i];
}

void tbt :: display()
{
	int ch;
	cout<<"What order: \n";
	cout<<"1. Inorder\n2. Preorder\n3. Postorder\n";
	cin>>ch;
	switch (ch)
	{
		case 1: inorder();
		break;
		case 2: preorder();
		break;
		case 3: postorder();
		break;
	}
}

void tbt :: control()
{
	int numb, n, x, ch;
	x=0;
	while(1)
		{
		cout<<"\nThreaded Binary Search Tree";
		cout<<"\n1. Insert nodes\n2. Display\n3. Exit";
		cout<<"\nEnter choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Enter the no. of nodes: ";
				cin>>n;
				while(x<n)
				{
					cout<<"Enter no. to be entered into threaded binary tree: ";
					cin>>numb;
					create(numb);
					x++;
				}
				break;
			case 2: display();
				break;
			case 3: exit(0);
			break;
			default: cout<<"Invalid choice.";
			break;
		}
	}
}

int main()
{tbt branch; branch.control(); return 0;}