Q1. Write a C program to search an element using binary search technique. [10]
-------------------------------------------------------------------------------------
#include <stdio.h>
int binarySearch(int arr[], int left, int right, int key) 
{
while (left <= right) 
{
int mid = left + (right - left) / 2;
if (arr[mid] == key)
return mid;
if (arr[mid] < key)
left = mid + 1;
else
right = mid - 1;
}
return -1;
}
int main() 
{
int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
int n = sizeof(arr) / sizeof(arr[0]);
int key = 23;
int result = binarySearch(arr, 0, n - 1, key);
if (result == -1)
printf("Element not found\n");
else
printf("Element found at index %d\n", result);
return 0;
}

---------------------------------------------------------------
Q2. Write a program that implement dynamic stack. [20]
---------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* newNode(int data) 
{
struct Node* node = (struct Node*)malloc(sizeof(struct Node));
if (node == NULL) 
{
printf("Memory allocation failed.\n");
exit(1);
}
node->data = data;
node->next = NULL;
return node;
}
int isEmpty(struct Node* root) 
{
return (root == NULL);
}
void push(struct Node** root, int data) 
{
struct Node* node = newNode(data);
node->next = *root;
*root = node;
printf("%d pushed to stack.\n", data);
}
int pop(struct Node** root) 
{
if (isEmpty(*root)) 
{
printf("Stack underflow.\n");
exit(1);
}
struct Node* temp = *root;
*root = (*root)->next;
int popped = temp->data;
free(temp);
return popped;
}
int peek(struct Node* root) 
{
if (isEmpty(root)) 
{
printf("Stack is empty.\n");
exit(1);
}
return root->data;
}
int main() 
{
struct Node* root = NULL;
push(&root, 10);
push(&root, 20);
push(&root, 30);
printf("%d popped from stack.\n", pop(&root));
printf("Top element of stack: %d\n", peek(root));
return 0;
}
