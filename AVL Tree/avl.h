#ifndef __AVL_H
#define __AVL_H

/*
   File: avl.h
   Interface definition of the AVL tree data structure.
*/

struct AVLTree;
struct AVLTreeIterator;

/* In C, pointer to "function" that takes argument types and returning type  is specified as:
type (*function)(argtypes);
*/


typedef int (*comparator)(void * , void * );
typedef void (*printer)(void *);

/* Initialize binary search tree structure. */
void initAVLTree(struct AVLTree *tree);

/* Alocate and initialize search tree structure. */
struct AVLTree *newAVLTree();

/* Deallocate nodes in BST. */
void clearAVLTree(struct AVLTree *tree);

/* Deallocate nodes in AVL and AVL structure. */
void freeAVLTree(struct AVLTree *tree);

/*-- AVL Bag interface --*/
int  isEmptyAVLTree(struct AVLTree *tree);
int     sizeAVLTree(struct AVLTree *tree);

void     addAVLTree(struct AVLTree *tree, void *val, comparator compare);
int containsAVLTree(struct AVLTree *tree, void *val, comparator compare);
void  removeAVLTree(struct AVLTree *tree, void *val, comparator compare);

/* Utility function to print a tree */
void printTree(struct AVLTree *tree, printer printVal);

/* Iterator Interface */
struct AVLTreeIterator *createAVLTreeItr(struct AVLTree *tree);
void initAVLTreeItr( struct AVLTree *tree, struct AVLTreeIterator *itr);
void *nextAVLTreeItr(struct AVLTreeIterator *itr);
int hasNextAVLTreeItr(struct AVLTreeIterator *itr);
# endif
