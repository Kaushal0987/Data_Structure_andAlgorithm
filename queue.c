#include<stdio.h>
void main()
{
    int queue[6], front = -1, rear = -1, maxsize=6, choice, elm, i;
    char ch;

    do
    {
        printf("press 1 to enqueue\n");
        printf("press 2 to dequeue\n");
        printf("press 3 to display\n");
        printf("Enter your chioce: ");
        scanf("%d", &choice);

    
        switch(choice)
        {
            case 1:
            if(rear>=maxsize-1)
            {
                printf("Queue Overflow");
            }
            else
            {
                rear = rear+1;
                printf("Enter the element to enqueue: ");
                scanf("%d", &elm);
                queue[rear] = elm;
                break;
            }
            break;

            case 2:
            if(rear<=front)
            {
                printf("Queue is empty");
            }
            else{
                front=front+1;
                elm = queue[front];
                printf("item %d as deleted element",elm);
            }
            break;

            case 3:
            printf("Element of the queue are = ");
            for(i=0; i<maxsize; i++)
            {
                printf("%d", &queue[i]);
            }
            break;

            default:
            printf("wrong input");
            break;  
        }
        printf("\nDo you want compute another function? (y/n)");
        scanf(" %c", &ch);
    }
    while(ch=='y'||ch=='Y');
}
