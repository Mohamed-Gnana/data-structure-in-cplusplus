#include <stdio.h>
#include <stdlib.h>


typedef struct {int *base; int *top; int size;} stack_t;
typedef struct st_t{int item; struct st_t *next} stack_h;
stack_h *create_stack(int size)
{
    stack_h *st;
    st = get_node();
    st->next = NULL;
    return(st);
}
stack_t *create(int size)
{
    stack_t *sk;
    sk = (stack_t *) malloc(sizeof(stack_t));
    sk->base = (int *) malloc(size *sizeof(int));
    sk->size = size;
    sk->top = sk->base;
    return(sk);
}
int stack_isempty(stack_t *sk)
{
    return(sk->base == sk->top);
}
int push(int x, stack_t *sk)
{
    if (sk->top < sk->base + sk->size)
    {
        *(sk->top) = x;
        sk->top += 1;
        return(0);
    }
    return(-1);
}
int pop(stack_t *sk)
{
    sk->top -=1;
    return(*(sk->top));
}
void remove_stack(stack_t *sk)
{
    free(sk->base);
    free(sk);
}
int main()
{
    stack_t *sk = create(5);
    stack_h *st = create_stack(5);
    int worked = 100;
    worked = push(5, sk);
    printf("%d",worked);
    printf("%d",pop(sk));
    return 0;
}
