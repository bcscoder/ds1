Q1. Write a C program to search an element using binary search technique.[10]
----------------------------------------------------------------------------------
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

------------------------------------------------------------------------------
Q2) Implement a list library (singlylist.h) for a singly linked list of integers with the create, display 
operations. Write a menu driven program to call these operations.program
-------------------------------------------------------------------------
(singlylist.h) file name
#include <stdio.h>
#include <stdlib.h>
typedef struct Node 
{
 int data;
 struct Node* next;
} Node;
Node* createNode(int data) 
{
 Node* newNode = (Node*)malloc(sizeof(Node));
 newNode->data = data;
 newNode->next = NULL;
 return newNode;
}
void displayList(Node* head) 
{
 Node* current = head;
 while (current != NULL) 
 {
 printf("%d -> ", current->data);
 current = current->next;
 }
 printf("NULL\n");
}
------------------------
(singly.c) file name
#include <stdio.h>
#include "singlylist.h"
int main() {
 Node* head = NULL;
 int choice, data;
 do {
 printf("\n--- Menu ---\n");
 printf("1. Create Node\n 2. Display List\n 3. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 printf("Enter data for the new node: ");
 scanf("%d", &data);
 if (head == NULL)
  {
 head = createNode(data);
 }
  else {
 Node* temp = head;
 while (temp->next != NULL) 
 {
 temp = temp->next;
 }
 temp->next = createNode(data);
 }
 break;
 case 2:
 printf("Linked List: ");
 displayList(head);
 break;
 case 3:
 printf("Exiting program\n");
 break;
 }
 } while (choice != 3);
 return 0;
}
