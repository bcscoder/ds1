Q1. Read the ‘n’ numbers from user and sort using bubble sort. [10]
--------------------------------------------------------------------------------
#include <stdio.h>
void bubbleSort(int arr[], int n) 
{
int i, j, temp;
for (i = 0; i < n - 1; i++) 
{
for (j = 0; j < n - i - 1; j++) 
{
if (arr[j] > arr[j + 1]) 
{
temp = arr[j];
arr[j] = arr[j + 1];
arr[j + 1] = temp;
}
}
}
}
int main() 
{
int n, i;
printf("Enter the number of elements: ");
scanf("%d", &n);
int arr[n];
printf("Enter %d numbers:\n", n);
for (i = 0; i < n; i++) 
{
scanf("%d", &arr[i]);
}
bubbleSort(arr, n);
printf("Sorted array in ascending order:\n");
for (i = 0; i < n; i++) {
printf("%d ", arr[i]);
}
printf("\n");
return 0;
}

Q2. Write a program to reverse the elements of a stack using stack library.
Implement basic stack operations init, push, pop.
-----------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100 
struct Stack 
{
int items[MAX_SIZE];
int top;
};
void init(struct Stack *s) 
{
s->top = -1;
}
int isEmpty(struct Stack *s) 
{
return s->top == -1;
}
int isFull(struct Stack *s) 
{
return s->top == MAX_SIZE - 1;
}
void push(struct Stack *s, int value) 
{
if (isFull(s)) 
{
printf("Stack Overflow!\n");
return;
}
s->top++;
s->items[s->top] = value;
}
int pop(struct Stack *s) 
{
if (isEmpty(s)) 
{
printf("Stack Underflow!\n");
exit(1);
}
int popped = s->items[s->top];
s->top--;
return popped;
}
void reverseStack(struct Stack *s) 
{
if (isEmpty(s))
return;
int temp = pop(s);
reverseStack(s);
insertAtBottom(s, temp);
}
void insertAtBottom(struct Stack *s, int value) 
{
if (isEmpty(s)) 
{
push(s, value);
return;
}
int temp = pop(s);
insertAtBottom(s, value);
push(s, temp);
}
void display(struct Stack *s) 
{
if (isEmpty(s)) 
{
printf("Stack is empty!\n");
return;
}
printf("Elements of the stack:\n");
for (int i = s->top; i >= 0; i--) 
{
printf("%d\n", s->items[i]);
}
}
int main() 
{
struct Stack stack;
init(&stack);
push(&stack, 10);
push(&stack, 20);
push(&stack, 30);
push(&stack, 40);
push(&stack, 50);
printf("Original stack:\n");
display(&stack);
reverseStack(&stack);
printf("Stack after reversal:\n");
display(&stack);
return 0;
}
