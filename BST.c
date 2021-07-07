#include<stdio.h>
#include<stdlib.h>


struct Node
{
	struct Node *lchild;	
	int info;
	struct Node *rchild;
};

void insert();
void preorder(struct Node *);
void inorder(struct Node *);
void postorder(struct Node *);
void search();
void smallest();
void largest();
void delete1();
void case_A(struct Node *, struct Node *);
void case_B(struct Node *, struct Node *);
void case_C(struct Node *, struct Node *);

struct Node *root=NULL;

main()
{
	int choice;
	while(1)
	{
		printf("\n1.Insert\n2.Preorder\n3.Inoder\n4.Postorder\n5.Smallest Node\n6.Largest Node\n7.Delete\n8.Search an elemnt\n9.EXIT\n");
		printf("\nEnter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:insert();
					break;
			case 2:if(root == NULL)
					{
						printf("\nTree is empty\n");
					}
					else
					{
						preorder(root);
						break;
					}	
			case 3:if(root == NULL)
					{
						printf("\nTree is empty\n");
					}
					else
					{
						inorder(root);
						break;
					}
			case 4:if(root == NULL)
					{
						printf("\nTree is empty\n");
					}
					else
					{
						postorder(root);
						break;
					}
			case 5:smallest();
					break;
			case 6:largest();
					break;
			case 7:delete1();		
					break;
			case 8:search();
					break;
			case 9:exit(0);
			default:printf("\nWrong Choice\n");
		}
	}
}
void insert()
{
	struct Node *temp,*ptr,*par;
	int item;
	temp=(struct Node *)malloc(sizeof(struct Node));
	if(temp==NULL)
	{
		printf("\n Memory is not allocated\n");
	}
	else
	{
		printf("Enter value to insert");
		scanf("%d",&item);
		temp->info=item;
		temp->lchild=NULL;
		temp->rchild=NULL;
		if(root==NULL)
		{
			root=temp;
		}
		else
		{
			ptr=root;
			while(ptr!=NULL)
			{
				par=ptr;
				if(item < ptr->info)
				{
					ptr=ptr->lchild;
				}
				else if(item > ptr->info)
				{
					ptr=ptr->rchild;
				}
				else
				{
					printf("\nDuplicate element is not allowed\n");
					break;
				}
			}
			if(ptr == NULL)
			{
				if(item < par->info)
				{
					par->lchild = temp;
				}
				else
				{
					par->rchild = temp;
				}
			}
		}
	}
}
void delete1()
{
	struct Node *ptr,*par;
	int item;
	if(root == NULL)
	{
		printf("\nTree is empty\n");
	}
	else
	{
		ptr=root;
		par=NULL;
		printf("\nEnter value to delete\n");
		scanf("%d",&item);//A
		while(ptr != NULL)
		{
			if(ptr->info == item)
			{
				break;
			}
			par=ptr;
			if(item < ptr->info)
			{
				ptr=ptr->lchild;
			}
			else
			{
				ptr=ptr->rchild;
			}
		}
		if(ptr == NULL)
		{
			printf("\n Node not found\n");
		}
		else
		{
			printf("\n Deleted node=%d\n",ptr->info);
			if((ptr->lchild != NULL) && (ptr->rchild != NULL))
			{
				case_C(par,ptr); //Node having both children
			}
			else if((ptr->lchild == NULL) && (ptr->rchild == NULL))
			{
				case_A(par,ptr); //Node having zero child
			}
			else
			{
				case_B(par,ptr); //Node having one child
			}
		}
	} 
}
void case_A(struct Node *par,struct Node *ptr)
{
	printf("\nDeleted value is %d\n",ptr->info);
	if(par == NULL)
	{
		root = NULL;
		free(ptr);
	}
	else
	{
		if(ptr->info < par->info)
		{
			par->lchild = NULL;
		}
		else
		{
			par->rchild = NULL;
		}
		free(ptr);
	}
	
}
void case_B(struct Node *par,struct Node *ptr)
{
	struct Node *child;
	if(ptr->lchild != NULL)
	{
		child = ptr->lchild;
	}
	else
	{
		child = ptr->rchild;
	}
	printf("\nDeleted value is %d\n",ptr->info);
	if(par == NULL)
	{
		root = child;
		free(ptr);
	}
	else
	{
		if(ptr == par->lchild)
		{
			par->lchild = child;
		}
		else
		{
			par->rchild = child;
		}
		free(ptr);
	}
}
void case_C(struct Node *par,struct Node *ptr)
{
	stuct Node *pptr,*ppar;
	pptr = ptr->rchild;
	ppar = ptr;
	while(pptr->lchild != NULL)
	{
		ppar = pptr;
		pptr = pptr->lchild;
	}
	ptr->info = pptr->info;
	if(pptr->rchild != NULL)
	{
		case_B(ppar,pptr);
	}
	else
	{
		case_A(ppar,ppt);
	}
}

void preorder(struct Node *temp)    //NLR
{
	if(temp!=NULL)
	{
		printf("%d ",temp->info);//N
		preorder(temp->lchild);//L
		preorder(temp->rchild);//R
	}
}

void postorder(struct Node *temp)    //LRN
{
	if(temp!=NULL)
	{
		postorder(temp->lchild);//L
		postorder(temp->rchild);//R
		printf("%d ",temp->info);//N
	}
}

void inorder(struct Node *temp)    //LNR
{
	if(temp!=NULL)
	{
		inorder(temp->lchild);//L
		printf("%d ",temp->info);//N
		inorder(temp->rchild);//R
	}
}
void smallest()
{
	struct Node *temp;
	if(root == NULL)	
	{
		printf("\nTree is empty\n");
	}
	else
	{
		temp = root;
		while(temp->lchild != NULL)
		{
			temp = temp->lchild;
		}
		printf("\nSmallest element of the tree is %d\n",temp->info);
	}
}
void largest()
{
	struct Node *temp;
	if(root == NULL)	
	{
		printf("\nTree is empty\n");
	}
	else
	{
		temp = root;
		while(temp->rchild != NULL)
		{
			temp = temp->rchild;
		}
		printf("\nLargest element of the tree is %d\n",temp->info);
	}
}

void search()
{
	int item;
	struct Node *temp;
	if(root == NULL)
	{
		printf("\nTree is empty\n");
	}
	else
	{
		printf("\nEnter the value to search");
		scanf("%d",&item);
		temp = root;
		while(temp!=NULL)
		{
			if(temp->info == item)
			{
				printf("\nSearched item is present\n");
				break;
			}
			else if(item < temp->info)
			{
				temp = temp->lchild;
			}
			else
			{
				temp = temp->rchild;
			}
		}
		if(temp == NULL)
		{
			printf("\nSearched item is not present\n");
		}
	}
}

