#include <stdio.h>
#define MAX 5

void push(int stack[], int *top, int value) {
    if (*top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        (*top)++;
        stack[*top] = value;
        printf("%d pushed onto the stack\n", value);
    }
}

void pop(int stack[], int *top) {
    if (*top == -1) {
        printf("Stack underflow: cannot pop from stack\n");
    } else {
        printf("%d popped from stack\n", stack[*top]);
        (*top)--;
    }
}

void display(int stack[], int *top) {
    if (*top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = *top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int stack[MAX];
    int top = -1;
    int choice, value;

    do {
        printf("Enter choice (1 for push, 2 for pop, 3 for display, 4 for exit): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(stack, &top, value);
                break;
            case 2:
                pop(stack, &top);
                break;
            case 3:
                display(stack, &top);
                break;
            case 4:
                printf("Exiting....\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
