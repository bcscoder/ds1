Q1) Implement a list library (singlylist.h) for a singly linked list of integers with the create, display 
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

--------------------------------------------------------------------------------
Q2. Write a program that sorts the elements using merge sort technique.
-----------------------------------------------------------------------------------------
#include <stdio.h>
void merge(int arr[], int left, int mid, int right) 
{
 int n1 = mid - left + 1;
 int n2 = right - mid;
 int leftArr[n1], rightArr[n2];
 for (int i = 0; i < n1; i++)
 leftArr[i] = arr[left + i];
 for (int j = 0; j < n2; j++)
 rightArr[j] = arr[mid + 1 + j];
 int i = 0, j = 0, k = left;
 while (i < n1 && j < n2) 
{
 if (leftArr[i] <= rightArr[j]) 
{
 arr[k] = leftArr[i];
 i++;
 } 
else 
{
 arr[k] = rightArr[j];
 j++;
 }
 k++;
 }
 while (i < n1) 
{
 arr[k] = leftArr[i];
 i++;
 k++;
 }
 while (j < n2) 
{
 arr[k] = rightArr[j];
 j++;
 k++;
 }
}
void mergeSort(int arr[], int left, int right) 
{
 if (left < right)
{
 int mid = left + (right - left) / 2;
 mergeSort(arr, left, mid);
 mergeSort(arr, mid + 1, right);
 merge(arr, left, mid, right);
 }
}
void printArray(int arr[], int size) 
{
 for (int i = 0; i < size; i++)
 printf("%d ", arr[i]);
 printf("\n");
}
int main() 
{
 int arr[] = {12, 11, 13, 5, 6, 7};
 int size = sizeof(arr) / sizeof(arr[0]);
 printf("Given array: ");
 printArray(arr, size);
 mergeSort(arr, 0, size - 1);
 printf("Sorted array: ");
 printArray(arr, size);
 return 0;
}