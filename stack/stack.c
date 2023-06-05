#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
    int stack[6], top = -1, choice, i, j, elm;
    char ch;
    
    do{
        printf("Functions of Stack\n");
        printf("press: 1 for push\n");
        printf("       2 for pop\n");
        printf("       3 for display\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            if (top == 6)
            {
                printf("Stack Overflow\n");
            }
            else
            {
                printf("If you want to add all 6 element press '1' else press any button: ");
                scanf("%d", &j);

                if(j==1)
                {
                    if (top == -1)
                    {
                        printf("Stack Underflow, proceed to write 6 elements in the stack: \n");
                        for(i=0;i<6;i++)
                        {
                            scanf("%d", &stack[i]);
                            top++;
                        }
                    }
                }
                else
                {
                    scanf("%d", &elm);
                    top++;
                    stack[top] = elm;
                }
            }
            break;

            case 2:
            if (top == -1)
            {
                printf("Stack Underflow\n");
            }
            else
            {
                printf("pop element: %d\n", stack[top]);
                top--;
            }
            break;

            case 3:
            printf("The elements of the Stack are: ");
            for (i = 0; i <= top; i++)
            {
                printf("%d\n", stack[top-i]);
            }
            break;

            default:
            printf("Wrong input\n");
            break;
        }

        printf("Do you want to add another Function?(y/n): ");
        fflush(stdin);
        scanf(" %c", &ch);

    }while(ch=='y'||ch=='Y');

    
}