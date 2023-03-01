
// Muhammed Cafer Taşdelen 
// CENG 205 DATA STRUCTURES ASSIGNMENT 3
//References
//https://youtu.be/C1iEv-nDm1w

#include <stdio.h>
#include <stdlib.h>

struct treeNode
{
	int data;
	struct treeNode* leftptr;
	struct treeNode* rightptr;
};

void reverseLevelOrder(struct treeNode* root);
struct treeNode* newNode(int data);

void reverseLevelOrder(struct treeNode* root)
{

	
	

	struct treeNode* queue[101]; // queue creation
	int front = 0, rear = 0;

	queue[rear++] = root;//queue the root of the tree as the first element

	
	while (front < rear) {
		
		struct treeNode* curr = queue[front]; // curr is temporary element
		front++;
		if (curr->rightptr != NULL) // checks right child
		{
			queue[rear] = curr->rightptr;
			rear++;
		}
		
		if (curr->leftptr != NULL) //check left child
		{
			queue[rear] = curr->leftptr;
			rear++;
		}

	}
	//print queue
	int i = rear - 1;
	while (i>=0)
	{
		printf("%d ", queue[i]->data);
		i--;
	}
	
	

	


}

struct treeNode* newNode(int data)
{
	struct treeNode* treeNode = (struct treeNode*)malloc(sizeof(struct
		treeNode));
	treeNode->data = data;
	treeNode->leftptr = NULL;
	treeNode->rightptr = NULL;
	return(treeNode);
}
int main()
{
	struct treeNode* root = newNode(9);
	root->leftptr = newNode(12);
	root->rightptr = newNode(21);
	root->leftptr->leftptr = newNode(15);
	root->leftptr->rightptr = newNode(8);
	root->rightptr->leftptr = newNode(7);
	root->rightptr->rightptr = newNode(11);
	printf("Level Order traversal of binary tree is \n");
	reverseLevelOrder(root);
	return 0;
}