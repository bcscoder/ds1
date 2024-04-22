Q1. Sort a random array of n integers (accept the value of n from user) in 
ascending order by using insertion sort algorithm.
----------------------------------------------------------------------\
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void insertionSort(int arr[], int n) 
{
int i, key, j;
for (i = 1; i < n; i++)
{
key = arr[i];
j = i - 1;
while (j >= 0 && arr[j] > key) 
{
arr[j + 1] = arr[j];
j = j - 1;
}
arr[j + 1] = key;
}
}
int main()
{
int n;
printf("Enter the number of elements in the array: ");
scanf("%d", &n);
int *arr = (int *)malloc(n * sizeof(int));
if (arr == NULL)
{
printf("Memory allocation failed.\n");
return 1;
}   
srand(time(NULL));
printf("Random array before sorting:\n");
for (int i = 0; i < n; i++)
{
arr[i] = rand() % 100; 
printf("%d ", arr[i]);
}
printf("\n");
insertionSort(arr, n);
printf("Array after sorting in ascending order:\n");
for (int i = 0; i < n; i++) 
{
printf("%d ", arr[i]);
}
printf("\n");    
free(arr);
return 0;
}

---------------------------------------------------------------
Q2. Write a C program to implement static stack. [20]
------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100 
struct Stack 
{
int items[MAX_SIZE];
int top;
};
void initialize(struct Stack *s) 
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
printf("%d pushed to stack.\n", value);
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
int peek(struct Stack *s) 
{
if (isEmpty(s)) 
{
printf("Stack is empty!\n");
exit(1);
}
return s->items[s->top];
}
int main() 
{
struct Stack stack;
initialize(&stack);
push(&stack, 10);
push(&stack, 20);
push(&stack, 30);
printf("%d popped from stack.\n", pop(&stack));
printf("Top element of stack: %d\n", peek(&stack));
return 0;
}
