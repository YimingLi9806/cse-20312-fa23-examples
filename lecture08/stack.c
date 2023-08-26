/* Lecture 08: Stack (Dynamic Array) */

#include "stack.h"

/* Functions */

void	stack_push(Stack *s, int value) {
    array_append(s, value);
}

int	stack_pop(Stack *s) {
    int top = stack_top(s);
    array_remove(s, s->size - 1);
    return top;
}

int	stack_top(Stack *s) {
    return array_at(s, s->size - 1);
}

bool	stack_empty(Stack *s) {
    return s->size == 0;
}
