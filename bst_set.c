/* This program has the following objectives
 * Create a binary search tree by adding elements to it
 * Traversal to print the elements
 * 
 *   Time Complexity  :
 *   Space Complexity :
 *
 *
 *   Manish Kumar, 24-August-2019
 */


#include<stdio.h>
#include<stdlib.h>
#include<time.h>

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
err_code add_elem(tree_t **bst_p, int elem);
int traverse_bst(tree_t *bst_p, int type_trvsl);

/* Add element in a BST */
err_code add_elem(tree_t **bst_p, int elem) {
    err_code ret = FAIL;

	if (!(*bst_p)) {
	    *bst_p = (tree_t *)malloc(sizeof(tree_t));
	    if (!(*bst_p)) {
	        printf("Memory allocation failed while adding %d\n", elem);
	        return ret;
	    }
	    (*bst_p)->data = elem;
	    (*bst_p)->left = NULL;
	    (*bst_p)->right = NULL;
	    printf("The element %d is added succesfully.\n", (*bst_p)->data);
	    ret = SUCCESS;
	} else {
	    if ((*bst_p)->data <= elem) {
	        ret = add_elem(&((*bst_p)->right), elem);
	    } else {
	        ret = add_elem(&((*bst_p)->left), elem);
	    }
	}
	return ret;
}

void inorder_traversal(tree_t *bst_p) {
    if (bst_p == NULL) {
        return;
    }
    inorder_traversal(bst_p->left);
    printf("%d -> ", bst_p->data);
    inorder_traversal(bst_p->right);
}

void free_memory(tree_t *bst_p) {
	static int count = 0;
    if (bst_p == NULL) {
        return;
    }
    free_memory(bst_p->left);
    free_memory(bst_p->right);
    count++;
    printf("Freeing %d , total: %d\n", bst_p->data, count);
    free(bst_p);
}

int main(int argc, char *argv[]) {
    tree_t *bst_p = NULL;
    int index = 0, count = 0;
    int elem = 0;
    err_code ret = SUCCESS;

    if (argc != 2) {
        printf("Usage: ./a.out <num of elements> %d\n", argc);
        exit(1);
    }
    count = atoi(argv[1]);
    
    srand(time(0));
    printf("Generating %d elements and storing it in BST\n", count);

    /* Generate elements in the range of 20000 */
    for (int index=0; index < count; index++) {
        elem = rand() % 20000;
        printf("Element %d add status : %d\n", elem, add_elem(&bst_p, elem));
    }

/* For Debugging purpose*/
#if 0    
	/* Add few elements */
	elem = 300;
	printf("Element %d add status : %d\n", elem, add_elem(&bst_p, elem));

	elem = 200;
	printf("Element %d add status : %d\n", elem, add_elem(&bst_p, elem));

	elem = 400;
	printf("Element %d add status : %d\n", elem, add_elem(&bst_p, elem));

	elem = 150;
	printf("Element %d add status : %d\n", elem, add_elem(&bst_p, elem));
#endif


    printf("Display elements now in BST \n\n\n");
    inorder_traversal(bst_p);
    printf("\n");
	
    /* Free the memory */
    free_memory(bst_p);
    /* Clearing out dangling pointer */
    bst_p = NULL;
}
