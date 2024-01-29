/*A) Write a program to create a binary search tree and perform the folloewing operations:
a)Insert a node in tree
b)Search a node in tree
c)Traversal of Tree (Inorder, Preorder, Postorder)
d) Delete a node in tree.
e) Calculate height of the tree.
f) Calculate total number of nodes, number of internal node and number of leaf node.*/
#include <stdio.h>
#include <conio.h>
#include <malloc.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
}*tree;

int count=0;
struct node *insertElement(struct node *, int);
void preorderTraversal(struct node *);
void inorderTraversal(struct node *);
void postorderTraversal(struct node *);
struct node *findSmallestElement(struct node * );
struct node *findLargestElement(struct node *);
struct node *deleteElement(struct node *, int);
struct node *searchElement(struct node *, int);
struct node* kthSmallest(struct node* , int);
int totalNodes(struct node *);
int totalExternalNodes(struct node *);
int totalInternalNodes(struct node *);
int Height(struct node *);
struct node *deleteTree(struct node *);

int main()
{
	int option, val;
	struct node *ptr;
	tree=NULL;
	do
	{
		printf("\n ******MAIN MENU******* \n");
		printf("\n 1. Insert Element");
		printf("\n 2. Preorder Traversal");
		printf("\n 3. Inorder Traversal");
		printf("\n 4. Postorder Traversal");
		printf("\n 5. Find the smallest element");
		printf("\n 6. Find the largest element");
		printf("\n 7. Delete an element");
		printf("\n 8. Count the total number of nodes");
		printf("\n 9. Count the total number of external nodes");
		printf("\n 10. Count the total number of internal nodes");
		printf("\n 11. Determine the height of the tree");
		printf("\n 12. Find kth smallest element");
		printf("\n 13. Delete the tree");
		printf("\n 14. Search an element");
		printf("\n 15. Exit");
		printf("\n\n Enter your option : ");
		scanf("%d", &option);
		switch(option)
		{
		case 1:
			printf("\n Enter the value of the new node : ");
			scanf("%d", &val);
			tree = insertElement(tree, val);
			break;
		case 2:
			printf("\n The elements of the tree are : \n");
			preorderTraversal(tree);
			break;
		case 3:
			printf("\n The elements of the tree are : \n");
			inorderTraversal(tree);
			break;
		case 4:
			printf("\n The elements of the tree are : \n");
			postorderTraversal(tree);
			break;
		case 5:
			ptr = findSmallestElement(tree);
			printf("\n Smallest element is :%d",ptr->data);
			break;
		case 6:
			ptr = findLargestElement(tree);
			printf("\n Largest element is : %d",ptr->data);
			break;
		case 7:
			printf("\n Enter the element to be deleted : ");
			scanf("%d", &val);
			tree = deleteElement(tree, val);
			break;
		case 8:
			printf("\n Total no. of nodes = %d", totalNodes(tree));
			break;
		case 9:
			printf("\n Total no. of external nodes = %d", totalExternalNodes(tree));
			break;
		case 10:
			printf("\n Total no. of internal nodes = %d", totalInternalNodes(tree));
			break;
		case 11:
			printf("\n The height of the tree = %d",Height(tree));
			break;
		case 12:
			printf("\n Enter the kth smallest value to found : ");
			scanf("%d", &val);
			count=0;
			ptr = kthSmallest(tree, val);
			if(ptr!=NULL)
				printf("\nK-th smallest ement is %d",ptr->data);
			else
				printf("\nElement not Found");  
			break;
		case 13:
			tree = deleteTree(tree);
			break;
		case 14:
			printf("\n Enter the element to be searched : ");
			scanf("%d", &val);
			ptr = searchElement(tree, val);
			if(ptr!=NULL)
				printf("\nElement Found");
			else
				printf("\nElement not Found");  
			break;
		}
	}while(option!=15);
	getch();
	return 0;
}

struct node *insertElement(struct node *tree, int val)
{
	struct node *ptr, *nodeptr, *parentptr;
	ptr = (struct node*)malloc(sizeof(struct node));
	ptr->data = val;
	ptr->left = NULL;
	ptr->right = NULL;
	if(tree==NULL)
	{
		tree=ptr;
		tree->left=NULL;
		tree->right=NULL;
	}
	else
	{
	if(val < tree->data)
		tree->left = insertElement(tree->left, val);
	else
		tree->right=insertElement(tree->right, val);
	}
	return tree;
}//function

void preorderTraversal(struct node *tree)
{
	if(tree != NULL)
	{
		printf("%d\t", tree->data);
		preorderTraversal(tree->left);
		preorderTraversal(tree->right);
	} 
}

void inorderTraversal(struct node *tree)
{
	if(tree != NULL)
	{
		inorderTraversal(tree->left);
		printf("%d\t", tree->data);
		inorderTraversal(tree->right);
	} 
}

void postorderTraversal(struct node *tree)
{
	if(tree != NULL)
	{ 
		postorderTraversal(tree->left);
		postorderTraversal(tree->right);
		printf("%d\t", tree->data);
	}
}

struct node *findSmallestElement(struct node *tree)
{
	if( (tree == NULL) || (tree->left == NULL))
		return tree;
	else
		return findSmallestElement(tree ->left);
}

struct node *findLargestElement(struct node *tree)
{
	if( (tree == NULL) || (tree->right == NULL))
		return tree;
	else
		return findLargestElement(tree->right);
}

struct node *deleteElement(struct node *tree, int val)
{
	struct node  *temp;
	if(tree==NULL)
		printf("\nNo Element found");
	// Recursive calls for ancestors of node to be deleted
	else if(val < tree->data)	
		tree->left=deleteElement(tree->left,val);
	else if(val > tree->data)
		tree->right=deleteElement(tree->right,val);
	else
	{
		//node found 
		if(tree->left!=NULL && tree->right!=NULL)	 
		{//node with two child
			temp=findLargestElement(tree->left);
			tree->data=temp->data;
			tree->left=deleteElement(tree->left,tree->data);
		} 
		else 
		{
			temp=tree;
			//node with no child
			if(tree->left==NULL && tree->right==NULL)
				tree=NULL;
			//node with one child
			else if(tree->left==NULL)
				tree=tree->right;
			else 
				tree=tree->left; 
			free(temp);	
		}
	}
	return(tree);	   
}

struct node* kthSmallest(struct node* tree, int k)
{
  	struct node *left;  
   	if (tree == NULL)
        return NULL;
 
    // search in left subtree
    left = kthSmallest(tree->left, k);
 
    // if k'th smallest is found in left subtree, return it
    if (left != NULL)
        return left;
 
    // if current element is k'th smallest, return it
    count++;
    if (count == k)
        return tree;
 
    // else search in right subtree
    return kthSmallest(tree->right, k);
}

struct node *searchElement(struct node *tree, int val)
{
	struct node *ptr=tree;
	if(ptr->data==val || ptr == NULL)
	{
	return(ptr);
	}
	if(val < ptr->data)
	{
		if(ptr->left!=NULL) 
			return(searchElement(ptr->left, val));
	}
	else
	{
		if(ptr->right!=NULL)
			return(searchElement(ptr->right, val));
	}
}

int Height(struct node *tree)
{
	int leftheight, rightheight;
	if(tree==NULL)
		return 0;
	else
	{ 
		leftheight = Height(tree->left);
		rightheight = Height(tree->right);
		if(leftheight > rightheight)
			return (leftheight + 1);
		else
			return (rightheight + 1);
	} 
}

int totalNodes(struct node *tree)
{
	if(tree==NULL)
		return 0;
	else
		return(totalNodes(tree->left) + totalNodes(tree->right) + 1);
}

int totalExternalNodes(struct node *tree)
{
	if(tree==NULL)
		return 0;
	else if((tree->left==NULL) && (tree->right==NULL))
		return 1;
	else
		return (totalExternalNodes(tree->left) + totalExternalNodes(tree->right));
}

int totalInternalNodes(struct node *tree)
{
	if( (tree==NULL) || ((tree->left==NULL) && (tree->right==NULL)))
		return 0;
	else
		return (totalInternalNodes(tree->left) + totalInternalNodes(tree->right) + 1);
}

struct node *deleteTree(struct node *tree)
{
	if(tree!=NULL)
	{
		deleteTree(tree->left);
		deleteTree(tree->right);
		free(tree);
	}
	return(NULL);
}