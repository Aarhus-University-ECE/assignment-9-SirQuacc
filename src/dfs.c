/*
 * Search an expression using DFS.
 */

#include <stdio.h>		/* scanf, printf */
#include <stdlib.h>		/* abort */
#include <stdbool.h>		/* bool, true, false */
#include <assert.h>    /* assert(); */
#include "dfs.h"


void DFT (node * root)
{
  printf("The given tree:\n");
  print_tree(root, 0); //Print the given tree first

  stack* mainStack = malloc(sizeof(stack)); //Allocate a stack node
  initStack(mainStack); //Initialize the stack
  mainStack = push(mainStack, root); //Push the root on to the stack first
  stack* popped; //Pointer to the saved node after popping

  printf("Order of visiting tree: ");
  while(!isEmpty(mainStack)){ //!isEmpty(mainStack)
    popped = pop(&mainStack); //Pop the top node, popped variable saves pointer to the popped node
    print_node(popped->node); //Print the visited (popped) node's value.
    if(popped->node->rchild != NULL) mainStack = push(mainStack, popped->node->rchild); //If there is a right child, add this to the stack
    if(popped->node->lchild != NULL) mainStack = push(mainStack, popped->node->lchild); //If there is a left child, add this to the stack
    free(popped); // Free stack-node, clean-up.
  }
  printf("\n");
}

node *make_node (int num, node * left, node * right)
{
  node* new = malloc(sizeof(node)); //Allocate new node in heap
  new->num = num; //add num data
  new->visited = false; //Haven't visisted it by default
  new->lchild = left; //add children
  new->rchild = right;
	return new; //return pointer to new node
}

void free_node (node * p) //free a given node, and its children
{
  if(p->rchild != NULL){
    free_node(p->rchild);
  }
  if(p->lchild != NULL){
    free_node(p->lchild);
  }
  free(p);
}

void print_node (node * p)
{
  if (p == NULL)
    printf ("NULL\n");
  else
    printf ("-> %d ", p->num);
}


void print_tree (node * p, int depth)
{
  for (int i = 0; i < depth; i = i + 1)
    printf (" ");
  printf ("| ");

  if (p == NULL)
    printf ("NULL\n");
  else
    printf ("[%d]\n", p->num);


  if (p->lchild)
    {
      print_tree (p->lchild, depth + 1);
    }

  if (p->rchild)
    print_tree (p->rchild, depth + 1);
}

void initStack (stack* topp){ //Initialize a stack with a root node, that points to nothing
  topp->next = NULL;
  topp->node = NULL;
}

stack *push (stack * topp, node * node)
{
  stack* add = malloc(sizeof(stack)); //Create new "stack" node to add to the list
  add->node = node; //add the tree node to "add" as the top in the stack
  add->next = topp; //add previous topp node below "add"
	return add;
}

bool isEmpty (stack * topp)
{
  return (topp->next == NULL && topp->node == NULL); //If stack points to the initialized node, it's empty
}

node *top (stack * topp)
{
	return NULL;
}

// Utility function to pop topp  
// element from the stack 

stack *pop (stack ** topp) //Using double pointer allows editing the what the input points toward.
{
  assert(!isEmpty(*topp)); //Can't pop from an empty stack
  stack* save = *topp; //Save a copy of the top stack node
  *topp = (*topp)->next; //New top node is the next one
	return save; //Return the popped node
}

void print_stack (stack * topp)
{
  struct stack *temp = topp;

  while (temp != NULL)
    {

      print_node (temp->node);
      printf ("\n");

      temp = temp->next;
    }

  printf ("====\n");

  return;
}
