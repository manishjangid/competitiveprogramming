/* This program has the following objectives
 * Create a binary search tree by adding elements to it
 * Traversal to print the elements
 * 
 *   Time Complexity  :
 *   Space Complexity :
 *
 *
 *   Manish Kumar, 22-August-2019
 */


#include<stdio.h>
#include<stdlib.h>

typedef enum {
	SUCCESS,
	FAIL,
}err_code;

/* Data structure for a binary search tree */
typedef struct tree {
	int data;
	struct tree *left;
	struct tree *right;
} tree_t;

/* APIs to manage the BST */
err_code add_elem(tree_t *bst_p, int elem);
int traverse_bst(tree_t *bst_p, int type_trvsl);

/* Add element in a BST */
err_code add_elem(tree_t *bst_p, int elem) {
    err_code ret = FAIL;

	if (!bst_p) {
	    bst_p = (tree_t *)malloc(sizeof(tree_t));
	    if (!bst_p) {
	        printf("Memory allocation failed while adding %d\n", elem);
	        return ret;
	    }
	    bst_p->data = elem;
	    bst_p->left = NULL;
	    bst_p->right = NULL;
	    printf("The element %d is added succesfully.\n", elem);
	    ret = SUCCESS;
	} else {
	    if (bst_p->data < elem) {
	        ret = add_elem(bst_p->left, elem);
	    } else {
	        ret = add_elem(bst_p->right, elem);
	    }
	}
	return ret;
}

int main(void) {
	tree_t bst_p;
	int elem = 0;
	err_code ret = SUCCESS;

    bst_p.data = 200;
    bst_p.left = bst_p.right = NULL;

	/* Add few elements */
	elem = 300;
	printf("Element %d add status : %d\n, elem, add_elem(&bst_p, elem));

	elem = 400;
	printf("Element %d add status : %d\n, elem, add_elem(&bst_p, elem));

	elem = 500;
	printf("Element %d add status : %d\n, elem, add_elem(&bst_p, elem));

	elem = 600;
	printf("Element %d add status : %d\n, elem, add_elem(&bst_p, elem));

	/*TODO: Traverse and print it */
}
