/*
 * The following program illustrates the usage of array as a data structure
 * to implement stack.
 * The program will allocate a max size for array ie 100 in this case.
 * Time complexity : 
 *    Insertion : O(1) Always
 *    Deletion : O(N) worst case
 *    Peek : O(1) Always
 *
 * Space Complexity : UNKNOWN 
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int *data_arr; /* Pointer to array with dynamically allocated memory */
    int size; /* Total size of the stack */
    int top; /* Specifies the current index of the top element in the stack */
}stack_t;

/* APIs to perform stack functions */

/* 1. To insert elements into a stack */
int push_stack(stack_t *stck_p, int elem) {
    
    /* Pointer Validation */
    if (!stck_p) {
        printf("Insertion of %d into stack failed as the pointer to stack structure is NULL \n", elem);
        return -1;
    }
    /* Is there space left on stack to accomodate new element ? */
    if (stck_p->top == (stck_p->size - 1)){
        printf("Insertion of %d into stack failed as the stack is FULL !! \n", elem);
        return -2;        
    }
    /* Everything is fine now, insert into stack by incrementing the top variable */
    stck_p->data_arr[++(stck_p->top)] = elem;
    return 0;
}

/* 2. To delete element from stack */
int pop_stack(stack_t *stck_p, int *ret_code) {
    
    int elem = 0;
    
    /* Pointer Validation */
    if (!stck_p || !ret_code) {
        printf("Cannot delete element as pointer to stack structure or ret_code is NULL\n");
        *ret_code = -1;
    } else if (stck_p->top == -1){
        /* Is the stack already empty ? */
        printf("Deletion from stack failed as the stack is empty !!\n");
        *ret_code = -2;
    } else {
        /* Everything is fine now, insert into stack by incrementing the top variable */
        if (stck_p->data_arr) {
            elem = stck_p->data_arr[stck_p->top];
            (stck_p->top)--;    
            *ret_code = 0;
        } else {
            printf("Cannot delete element as pointer to stack is NULL\n");
            *ret_code = -3;            
        }
    }
    return elem;
}

int peek(stack_t *stck_p, int *ret_code) {
    
    if (!stck_p) {
        printf("Cannot check the top element as pointer to stack structure or ret_code is NULL\n");
        *ret_code = -1;
    } else if (stck_p->top == -1){
        printf("The stack is empty !\n");
        *ret_code = -2;
    } else {
        if (stck_p->data_arr) {
            return stck_p->data_arr[stck_p->top];
        } else {
            printf("The pointer to stack is NULL !\n");
            *ret_code = -3;            
        }
    }
    return 0;
}

int main(void) {
    stack_t *stck_p = NULL;
    int ret_code = 0; /* For checking return err codes*/
    int elem = 0; /* For element retrieval */
    
    /* Initialize stack with size of 100 */
    stck_p = (stack_t *)malloc(sizeof(stack_t));
    if (!stck_p) {
        printf("Memory allocation failed for stack structure \n");
        exit(1);
    }

    stck_p->data_arr = (int *)malloc(sizeof(int) * 100);
    if (!stck_p->data_arr) {
        printf("Memory allocation failed for stack data array \n");
        exit(2);
    }
    stck_p->size = 100;
    stck_p->top = -1;
    
    /* Basic test case */
    if ((ret_code = push_stack(stck_p, 2000)) != 0) {
        printf("Element %d addition failed to stack with errcode: %d\n", 2000, ret_code);
        exit(3);
    }
    if ((ret_code = push_stack(stck_p, 3000)) != 0) {
        printf("Element %d addition failed to stack with errcode: %d\n", 3000, ret_code);
        exit(3);
    }
    if ((ret_code = push_stack(stck_p, 4000)) != 0) {
        printf("Element %d addition failed to stack with errcode: %d\n", 4000, ret_code);
        exit(3);
    }
    if ((ret_code = push_stack(stck_p, 5000)) != 0) {
        printf("Element %d addition failed to stack with errcode: %d\n", 5000, ret_code);
        exit(3);
    }
    if ((ret_code = push_stack(stck_p, 6000)) != 0) {
        printf("Element %d addition failed to stack with errcode: %d\n", 6000, ret_code);
        exit(3);
    }
    
    /* TODO: add max elements and then test */
    
    elem = pop_stack(stck_p, &ret_code);
    if (!ret_code) {
        printf("Successfully popped : %d\n", elem);
    }
    elem = pop_stack(stck_p, &ret_code);
    if (!ret_code) {
        printf("Successfully popped : %d\n", elem);
    }
    
    /* Free the memory allocated */
    free(stck_p->data_arr);
    free(stck_p);
    
    return 0;
}

