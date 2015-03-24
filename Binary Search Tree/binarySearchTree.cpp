#include <iostream>
#include <climits>
#include <deque>

using namespace std;

struct Tree{
	char data;
	Tree *left;
	Tree *right;
	Tree *parent;	
};


Tree* newTreeNode(int c){
	Tree* newT = new Tree;
	newT->data = c;
	newT->left = NULL;
	newT->right = NULL;
	newT->parent = NULL;

	return newT;
}

/* We examine the root and recursively insert the new node to the left subtree if the new value is less than the root, 
or the right subtree if the new value is greater than or equal to the root.
Ω(logn) operations
*/
struct Tree* insertTreeNode(Tree* root, int data){
	static Tree* par;

	if (root == NULL){
		Tree *retNode = newTreeNode(data);
		retNode->parent=par;
		return retNode;
	}
	else if (data <= root->data){
		par = root;
		root->left = insertTreeNode(root->left, data);
	}
	else if (data > root->data){
		par = root;
		root->right = insertTreeNode(root->right, data);
	}
	return root;
}

/* print tree in order */
/* 1. Traverse the left subtree. 
   2. Visit the root. 
   3. Traverse the right subtree. 
*/
void printTreeInOrder(struct Tree *node){
	if(node == NULL) return;

	printTreeInOrder(node->left);
	cout << node->data << " ";
	printTreeInOrder(node->right);
}

/* print tree in postorder*/
/* 1. Traverse the left subtree. 
   2. Traverse the right subtree. 
   3. Visit the root. 
*/
void printTreePostOrder(struct Tree *node){
	if(node == NULL) return;

	printTreePostOrder(node->left);
	printTreePostOrder(node->right);
	cout << node->data << " ";
}

/* print in preorder */
/* 1. Visit the root. 
   2. Traverse the left subtree. 
   3. Traverse the right subtree. 
*/
void printTreePreOrder(struct Tree *node){
	if(node == NULL) return;

	cout << node->data << " ";
	printTreePreOrder(node->left);
	printTreePreOrder(node->right);
}

/* Tree min value */
Tree* minValue(Tree* root){
	if (root==NULL)
		return NULL;
	while(root->left)
		root = root->left;
	return root;
}

/* Tree max value */
Tree* maxValue(Tree* root){
	if (root==NULL)
		return NULL;
	while(root->right)
		root = root->right;
	return root;
}


/* Search the tree for a given key. This look up in BST is a fast operation because we eliminate half the nodes 
from our search on each iteration by choosing to follow the left subtree or the right subtree. It is an Ω(logn) operation. 
*/
Tree* lookUp(struct Tree *node, char key){
	if(node == NULL) return node;
	if (node->data == key) 
		return node;
	else {
		if (key <= node->data)
			return lookUp(node->left, key);
		else 
			return lookUp(node->right, key);
	}
}

/* 
maxDepth return the number of nodes along the longest path from the root down to the farthest leaf node. 
The maxDepth of the empty tree is 0. 
*/
int maxDepth(struct Tree *node){
	if (node == NULL)
		return 0;
	int leftDepth = maxDepth(node->left);
	int rightDepth = maxDepth(node->right);

	return leftDepth > rightDepth ? 
				leftDepth + 1 : rightDepth + 1;
}

/* 
minDepth return the number of nodes along the shortest path from the root down to the closest leaf node. 
*/
int minDepth(struct Tree *node){
	if (node == NULL)
		return 1; // can be 0 as well...
	int leftDepth = minDepth(node->left);
	int rightDepth = minDepth(node->right);

	return leftDepth < rightDepth ? 
				leftDepth + 1 : rightDepth + 1;
}

/*
Is a tree balanced?
A balanced binary tree is commonly defined as a binary tree in which the height of the two subtrees of every node 
never differ by more than 1.
In this example, we used maxDepth(node)-minDepth(node) <= 1
*/
bool isBalanced(struct Tree *node){
	if(maxDepth(node)-minDepth(node) <= 1) 
	    return true;
	else
	    return false;
}

/*
Size of a binary tree is the total number of nodes in the tree. 
*/
int treeSize(struct Tree *node){
	if (node == NULL)
		return 0;

	return treeSize(node->left) + treeSize(node->right) + 1;
}

/*
Check if the given binary tree is a binary SEARCH tree. If it is then the inorder traversal should output the elements in increasing order. 
We make use of this property of inorder traversal to check whether the given binary tree is a BST or not.
*/
void isBST(struct Tree *node){
	static int minV = INT_MAX;
	if(node == NULL) return;

	isBST(node->left);
	
	if(minV < node->data){
		minV = node->data;
	} else {
	    cout << "Not a BST" << endl;
	  	return;
	}

	isBST(node->right);
	return;
}

string bool2str(bool b){
	return b == 1 ? "yes" : "no";
}

/* Converting a BST into an array. We will use an in-order traversal of a tree to fill in the array.
*/ 
void TreeToArray(struct Tree *node, int a[]){ 
	static int pos = 0; 
  
	if(node == NULL)
		return;
	else { 
	    TreeToArray(node->left,a); 
	    a[pos++] = node->data; 
	    TreeToArray(node->right,a); 
    } 
} 

/*
Helper function for checking whether two trees are equal
*/
bool matchTree(Tree *r1, Tree *r2){
	/* Nothing left in both the big tree and a subtree */
	if(r1 == NULL && r2 == NULL)
	    return true;
	/* One of them is empty, meaning subtree not found */
	if(r1 == NULL || r2 == NULL)
	    return false;
	/* Not matching */
	if(r1->data != r2->data)
	    return false;
	return (matchTree(r1->left, r2->left) && 
			matchTree(r1->right, r2->right));
}


/*
Check if a tree is a subtree of another tree
*/
bool isSubTree(Tree *t1, Tree *t2){
	if(t1 == NULL) // Big tree is empty - meaning a subtree was not found.
	    return false;
	if(t1->data == t2->data) // if nodes equal check whether the left and right subtrees are equal as well
	    if(matchTree(t1, t2)) 
	    	return true;
	
	return (isSubTree(t1->left, t2) || isSubTree(t1->right, t2));
}


/* Mirror a tree. Change a tree so that the roles of the left 
and right hand pointers are swapped at every node */
void mirror(Tree *tr)
{
	if(tr == NULL) return;
	
	Tree *tmp;
	mirror(tr->left);
	mirror(tr->right);

	/* swap pointers */
	tmp = tr->right;
	tr->right = tr->left;
	tr->left = tmp;
}

/* In Order Successor - a node which has the next higher key 
Approach:
1) If right subtree of node is not NULL, then succ lies in right subtree. Do following.
Go to the right subtree and return the node with minimum key value in right subtree.
2) If right sbtree of node is NULL, then succ is one of the ancestors. Do following.
Travel up using the parent pointer until you see a node which is left child of it’s parent. The parent of such a node is the succ.

Good explanation on: http://www.geeksforgeeks.org/inorder-successor-in-binary-search-tree/
*/ 
Tree *succesorInOrder(struct Tree *node){
	if(node->right != NULL) 
		return minValue(node->right);

	Tree *y = node->parent;
	while(y != NULL && node == y->right) {
	    node = y;
	    y = y->parent;
	}
	return y;
}

/* In Order Predecessor - a node which has the next lower key 
Approach:
1) If a node has a left child, then we take subtree's maximum, i.e. right-most child of its left subtree.
2 If a node has no left child, we walk up the tree until we find a left-hand turn. 
In other words, follow the parent pointer until we get the key which is smaller than its own value.
*/
Tree *predecessorInOrder(struct Tree *node){
	if(node->left != NULL) 
		return maxValue(node->left);

	Tree *y = node->parent;
	/* if the node does not have a left child, predecessor is its first left ancestor */
	while(y != NULL && node == y->left) {
	    node = y;
	    y = y->parent;
	}
	return y;
}

Tree *lowestCommonAncestor(Tree *node, Tree *p, Tree *q) 
{
	Tree *left, *right;
	if(node == NULL) 
		return NULL;

	/* If either left or right subtree of a node is either p OR q then that node must be a LCA */
	if(node->left == p || node->left == q || node->right == p || node->right == q) 
		return node;
	
	left = lowestCommonAncestor(node->left, p, q);
	right = lowestCommonAncestor(node->right, p, q);
	/* If both of the above calls return a NON-NULL value, then one key is present in one subtree and other is present in other,
     So this node is the LCA */
	if(left && right) 
	    return node;
	else 
		/* Otherwise check if left subtree or a right subtree is LCA */
	    return (left) ? left : right;	
}

/* Delete the tree */
void clear(struct Tree *node)
{
	if(node != NULL) {
	    clear(node->left);
	    clear(node->right);
	    delete node;
	}
}


/* create a new tree from a sorted array */
Tree *addToBST(char arr[], int start, int end)
{
	if(end < start) return NULL;
	int mid = (start + end)/2;

	Tree *r = new Tree;
	r->data = arr[mid];
	r->left = addToBST(arr, start, mid-1);
	r->right = addToBST(arr, mid+1, end);
	return r;
}

/* Breadth first traversal using queue */
void BreadthFirstTraversal(Tree *root)
{
	if (root == NULL) 
		return;
	deque <Tree *> myQueue;
	myQueue.push_back(root);

	while (!myQueue.empty()) {
	    Tree *p = myQueue.front();
	    cout << p->data << " ";
	    myQueue.pop_front();

	    if (p->left != NULL)
		myQueue.push_back(p->left);
	    if (p->right != NULL)
		myQueue.push_back(p->right);
	}
	cout << endl;
}

/* find n-th max node from a tree. We will use in-order traversal approach */
void NthMax(struct Tree* t, int n_th_max)
{        
	static int num = 0;
	if(t == NULL) 
		return;  

	NthMax(t->right, n_th_max);        
	num++;
	if(num == n_th_max)                
	    cout << n_th_max << "-th maximum value is " << t->data << endl;        
	NthMax(t->left, n_th_max);
}

int main(){

	Tree *root = newTreeNode('F');
	insertTreeNode(root,'B');
	insertTreeNode(root,'A');
	insertTreeNode(root,'D');
	insertTreeNode(root,'C');  
	insertTreeNode(root,'E');
	insertTreeNode(root,'G');
	insertTreeNode(root,'I');
	insertTreeNode(root,'H');

	/* this should print in ascending order */
	cout << "In order print (ascending order, left-root-right): ";
	printTreeInOrder(root);
	cout << endl;

	cout << "Pre-order print (the order in which i added the nodes (?): root-left-right): ";
	printTreePreOrder(root);
	cout << endl;

	cout << "Post-order print (left-right-root): ";
	printTreePostOrder(root);
	cout << endl;

	Tree* test;
	test = maxValue(root);
	cout << "Max Tree node: " << test->data << endl;
	test = minValue(root);
	cout << "Min Tree Value: " << test->data << endl;

	char ch = 'S';
	test = lookUp(root, ch);
	if (test != NULL)
		cout << "Look Up Value: " << test->data << endl;
	else 
		cout << ch << " Not found " << endl;
	ch = 'B';
	test = lookUp(root, ch);
	if (test != NULL)
		cout << "Look Up Value: " << test->data << endl;
	else 
		cout << ch << " Not found " << endl;

	cout << "max depth: " << maxDepth(root) << "\nmin depth: " << minDepth(root) << "\nTree is balanced? " << 
		bool2str(isBalanced(root)) <<  "\nTree size (number of nodes): " << treeSize(root) <<  endl;


	/* convert the tree into an array */
	int bstSize = treeSize(root);
	int *arr = new int[bstSize];
	TreeToArray(root,arr);
	cout << "New array created from a BST: ";
	for (int i = 0; i < bstSize; i++)
	    cout << (char)arr[i] << ' ';
	cout << endl;
	delete [] arr;


	/* subtree */
	Tree *root2 = newTreeNode('D');
	insertTreeNode(root2,'C');  
	insertTreeNode(root2,'E');
	
	Tree *root3 = newTreeNode('B');
	insertTreeNode(root3,'A');  
	insertTreeNode(root3,'D');
	insertTreeNode(root3,'C');  
	insertTreeNode(root3,'E');
	
	Tree *root4 = newTreeNode('B'); 
	insertTreeNode(root4,'D');
	insertTreeNode(root4,'C');  
	insertTreeNode(root4,'E');
	
	cout << "1-2 is a subtree: " << bool2str(isSubTree(root, root2)) << endl;
	cout << "1-3 is a subtree: " << bool2str(isSubTree(root, root3)) << endl;
	cout << "1-4 is a subtree: " << bool2str(isSubTree(root, root4)) << endl;
	cout << "2-3 is a subtree: " << bool2str(isSubTree(root2, root3)) << endl;
	cout << "3-2 is a subtree: " << bool2str(isSubTree(root3, root2)) << endl;

	/* swap left and right */
	mirror(root3);
	cout << "In order print (ascending order, left-root-right): ";
	printTreeInOrder(root3);
	cout << endl;


	ch = 'F';
	Tree* found = lookUp(root,ch);
	if(found) {
	    Tree* succ = succesorInOrder(found);
	    if(succ)
			cout << "In Order Successor (node with the next higher value) of " << ch << " is " << succesorInOrder(found)->data << endl;
	    else 
			cout << "In Order Successor (node with the next higher value) of " << ch << " is None\n";
	}

	ch = 'C';
	found = lookUp(root,ch);
	if(found) {
	    Tree* pred = predecessorInOrder(found);
	    if(pred)
			cout << "In Order Predecessor (node with the next lower value) of " << ch << " is " << predecessorInOrder(found)->data << endl;
	    else 
			cout << "In Order Predecessor (node with the next lower value) of " << ch << " is None\n";
	}


	/* Lowest Common Ancestor */
	char ch1 = 'A';
	char ch2 = 'C';
	Tree* ancestor = lowestCommonAncestor(root, lookUp(root,ch1), lookUp(root,ch2));
	if(ancestor) 
	    cout << "The lowest common ancestor of " << ch1 << " and "
		<< ch2 << " is " << ancestor->data << endl;

	ch1 = 'E';
	ch2 = 'H';
	ancestor = lowestCommonAncestor(root, lookUp(root,ch1), lookUp(root,ch2));
	if(ancestor) 
	    cout << "The lowest common ancestor of " << ch1 << " and "
		<< ch2 << " is " << ancestor->data << endl;

	ch1 = 'D';
	ch2 = 'E';
	ancestor = lowestCommonAncestor(root, lookUp(root,ch1), lookUp(root,ch2));
	if(ancestor) 
	    cout << "The lowest common ancestor of " << ch1 << " and "
		<< ch2 << " is " << ancestor->data << endl;


	/* Traversing level-order. 
	We visit every node on a level before going to a lower level. 
	This is also called Breadth-first traversal.*/
	cout << "Breadth-first traversal:" << endl;
	BreadthFirstTraversal(root);


	/* find n-th maximum node */
	NthMax(root, 5);

	return 0;
}