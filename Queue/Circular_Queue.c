#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
 int circular_queue[5], front, rear, i, element, maxsize = 6, choice;
 char ch;

 do
 {
  printf("Functions of Circular Queue\n");
  printf("press: 1 for Enqueue\n");
  printf("       2 for Dequeue\n");
  printf("       3 for display\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);

  switch(choice)
  {
   case 1:
   if((front == rear + 1) || (front == 0 && rear == maxsize - 1))
   {
    printf("Queue is full\n");
   }
   else
   {
    if(front == -1)
    {
     front = 0;
    }
    rear = (rear + 1) % maxsize;
    printf("Enter the element to enqueue: ");
    scanf(" %d", &element);
    circular_queue[rear] = element;
    printf("Inserted element = %d\n", element);
   }
   break;

   case 2:
   if(front == -1)
   {
    printf("Queue is empty\n");
   }
   else
   {
    element = circular_queue[front];
    if(front == rear)
    {
     front = -1;
     rear = -1;
    }
    else
    {
     front = (front + 1) % maxsize;
    }
    printf("Deleated element = %d\n", element);
   }
   break;

   case 3:
   printf("Element of the queue are: ");
   for(i=0; i<maxsize; i++)
   {
    printf("%d\n", circular_queue[i]);
   }
   break;

   default:
   printf("Wrong input\n");
   break;
  }

  printf("Do you want to do another function? (y/n): ");
  scanf(" %c", &ch);

 } while (ch=='y'||ch=='Y');
 
}