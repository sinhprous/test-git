#include <stdio.h>
#include <conio.h>

struct TreeNode{
	int key;
	TreeNode *leftPtr;
	TreeNode *rightPtr;
};

TreeNode* mirror(TreeNode* nodePtr){
	if (nodePtr != NULL){
		TreeNode* temp = NULL;
		temp = nodePtr->leftPtr;
		nodePtr->leftPtr = nodePtr->rightPtr;
		nodePtr->rightPtr = temp;
		mirror(nodePtr->leftPtr);
		mirror(nodePtr->rightPtr); 
	}
}

TreeNode* makeTreeNode(int key){
	TreeNode *newNode = new TreeNode;
	newNode->leftPtr = NULL;
	newNode->rightPtr = NULL;
	newNode->key = key;
	return newNode;
}

main(){
	TreeNode *x = NULL;
	x = makeTreeNode(1);
	x->leftPtr = makeTreeNode(2);
	x->leftPtr->leftPtr = makeTreeNode(3);
	x->leftPtr->rightPtr = makeTreeNode(4);
	x->rightPtr = makeTreeNode(5);
	x->rightPtr->leftPtr = makeTreeNode(7);
	x->rightPtr->rightPtr = makeTreeNode(8);
	x->rightPtr->rightPtr->rightPtr = makeTreeNode(10);
	x->rightPtr->rightPtr->leftPtr = makeTreeNode(9);
	
	mirror(x);
	printf("%d", x->leftPtr->leftPtr->rightPtr->key);
}
