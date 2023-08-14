#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<malloc.h>
#include<process.h>

void insert_b();
void insert_e();
void insert_btw();
void delete_b();
void delete_e();
void delete_btw();
void display();

int A, B, C, D, element;

struct Node
{
    int info;
    struct Node *next;
};
typedef struct Node NodeType;
NodeType *first = NULL, *last = NULL;

int main()
{
    int choice;

    printf("Enter the Operation you want to compute");
    printf("1 for insert at begining");
    printf("2 for insert at end");
    printf("3 for insert in between");
    printf("4 for delete at begining");
    printf("5 for delete at end");
    printf("6 for delete at a specific position");
    printf("7 to display");
    scanf(" %d", &choice);

    switch(choice)
    {
        case 1:
            insert_b();
            break;

        case 2:
            insert_e();
            break;

        case 3:
            insert_btw();
            break;

        case 4:
            delete_b();
            break;

        case 5:
            delete_e();
            break;

        case 6:
            delete_btw();
            break;
        
        case 7:
            display();
            break;
        
        default:
            printf("Wrong input");
            break;
    }
}

void insert_b()
{
    NodeType *Newnode;
    Newnode = (NodeType*)malloc(sizeof(NodeType));
    printf("Enter the element to be inserted: ");
    scanf("%d", &element);
    Newnode.info = element;
    if(first==NULL)
    {
        Newnode->next = NULL;
        first = last = Newnode;
    }
    Newnode->next=first;
    first=Newnode;
}

void insert_e()
{
    NodeType *Newnode;
    Newnode = (NodeType*)malloc(sizeof(NodeType));
    printf("Enter the element to be inserted: ");
    scanf("%d", &element);
    Newnode.info=element;
    if(last==NULL)
    {
        Newnode->next = NULL;
        first = last = Newnode;
    }
    Newnode->next=NULL;
    last->next=Newnode;
    last=Newnode;

}

void insert_btw(){
    NodeType *Newnode;
    NodeType *temp;
    int i, pos;
    Newnode = (NodeType*)malloc(sizeof(NodeType));
    printf("Enter the element to be inserted: ");
    scanf("%d", &element);
    printf("Enter the position where you want to insert the newnode: ");
    scanf("%d", &pos);
    temp = first;
    if(first == NULL){
        printf("Void insertion");
    }
    else{
        for(i=0; i<pos-1; i++){
            temp = temp->next;
        }
        Newnode->next = temp->next;
        temp->next = Newnode;
    }
}

void delete_b(){
    NodeType *temp;
    if(first == NULL){
        printf("Void deletion");
    }
    else if(first == last){
        printf("Deleted ietem as: ", first.info);
        first = last = NULL;
    }
    else{
        temp = first;
        printf("Deleted item as : ", first.info);
        first = first->next;
        free(temp);
    }
}

void delete_e(){
    NodeType *temp;
    if(first == NULL){
        printf("Void deletion");
    }
    else if(first == last){
        printf("Deleted ietem as: ", first.info);
        first = last = NULL;
    }
    else{
        temp = first;
        while(temp->next != last){
            temp = temp->next;
        }
        temp->next = NULL;
        last = temp;
    }
}

void delete_btw(){
    NodeType *temp, *loc; 
    int i, pos;
    if(first == NULL){
        printf("Void deletion");
    }
    else if(first == last){
        printf("Deleted ietem as: ", first.info);
        first = last = NULL;
    }
    else{
        printf("Enter the position where you want to delete the node: ");
        scanf("%d", &pos);
        temp = first;
        for(i=0; i<pos-1; i++){
            temp = temp->next;
        }
        printf("deleted item as: ", temp->next.info);
        loc = temp->next;
        temp->next = loc->next;
    }
}

void display()
{
    NodeType *temp;
    temp = first;
    if(first==NULL){
        printf("Empty linked list");
    }
    else{
        while(temp!=NULL){
            printf("%d\t", temp.info);
            temp = temp->next;
        }
    }
}
