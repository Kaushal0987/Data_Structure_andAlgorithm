#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
 int queue[6], front = -1, rear = -1, maxsize = 6, i, choice, element;
 char ch;

 do
 {

  printf("Functions of Queue\n");
  printf("press: 1 for Enqueue\n");
  printf("       2 for Dequeue\n");
  printf("       3 for display\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);

  switch(choice)
  {
   case 1:
   if(rear>=maxsize-1)
   {
    printf("Queue Overflow\n");
   }
   else
   {
    rear = rear + 1;
    printf("Enter the element to enqueue: ");
    scanf(" %d", &element);
    queue[rear] = element;
   }
   break;

   case 2:
   if(rear<=front)
   {
    printf("Queue is empty\n");
   }
   else
   {
    front = front + 1;
    element = queue[front];
    printf("Element deleted = %d", element);
   }
   break;

   case 3:
   printf("The element of the queue are: ");
   for(i=0; i<=maxsize; i++)
   {
    printf("%d \n",queue[i]);
   }
   break;

   default:
   printf("Wrong input\n");
   break;
  }

  printf("Do you want to compute another function? (y/n): ");
  scanf(" %c", &ch);

 }while(ch=='y'||ch=='Y');

}