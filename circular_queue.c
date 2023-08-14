#include<stdio.h>
void main()
{
    int cicular_queue[5], front = -1, rear = -1, maxsize=5, choice, elm, i;
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
            if (front==rear+1||(front==0&&rear==maxsize-1))
            {
                printf("Queue is full");
            }
            else
            {
                if(front==-1)
                {
                    front++;
                }
                rear = (rear+1)%maxsize;
                printf("Enter the element: ");
                scanf("%d", &elm);
                cicular_queue[rear]=elm;
                printf("Inserted = %d", elm);
            }
            break;

            case 2:
            if(front==-1)
            {
                printf("Queue is empty");
            }
            else
            {
                if (front == rear) //reset queue if there is only one element in the queue
                {
                front = -1;
                rear = -1;
                } 
                front = (front+1)%maxsize; //deleting the element
                elm = cicular_queue[front];
                printf("Deleated item = %d", elm);
            }
            break;

            case 3:
            printf("Element of the circular queue are = ");
            for(i=0; i<maxsize; i++)
            {
                printf("%d", &cicular_queue[i]);
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