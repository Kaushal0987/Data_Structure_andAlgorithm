#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<malloc.h>
#include<process.h>

int elm;
int insert_begi();
int insert_end();
int delete_begi();
int delete_end();
int display();

struct Node
{
 int info;
 struct Node *next, *prev;
};
typedef struct Node NodeType;
NodeType *first=NULL, *last=NULL;

int main(){

 int choice;
 char ch;

 do
  {
   printf("Select an option of Linked list operation\n");
   printf("1: Insert node at begining\n");
   printf("2: Insert node at end\n");
   printf("3: Delete node at begining\n");
   printf("4: Delete node at end\n");
   printf("5: Display the nodes\n");
   printf("6: exit\n");
   scanf("%d", &choice);

   switch(choice){

    case 1:
    insert_begi();
    break;

    case 2:
    insert_end();
    break;

    case 3:
    delete_begi();
    break;

    case 4:
    delete_end();
    break;

    case 5:
    display();
    break;

    case 6:
    exit(1);
    break;

    default:
    printf("Wrong input");
    break;
   }

   printf("\nDo you want to do another function? (y/n): ");
   scanf(" %c", &ch);

  }
  while (ch=='y'||ch=='Y');
}

int insert_begi(){
 NodeType *Newnode;
 Newnode = (NodeType*)malloc(sizeof(NodeType));

 printf("Enter the element to insert: ");
 scanf("%d", &elm);

 Newnode->info = elm;
 if(first==NULL){
  Newnode->next = NULL;
  Newnode->prev = NULL;
  first = last = Newnode;
 }
 else{
  Newnode->next = first;
  Newnode->prev = NULL;
  first = Newnode;
 }
}

int insert_end(){
 NodeType *Newnode;
 Newnode = (NodeType*)malloc(sizeof(NodeType));

 printf("Enter the element to insert: ");
 scanf("%d", &elm);

 Newnode->info = elm;
 if(last==NULL){
  printf("Void Insertion");
  Newnode->next = NULL;
  Newnode->prev = NULL;
  first = last = Newnode;
 }
 else{
  Newnode->next = NULL;
  Newnode->prev = last;
  last->next = Newnode;
  last = Newnode;
 }
}

int delete_begi(){
 NodeType *temp;

 if(first==NULL){
  printf("void deletion");
 }
 else if(first==last){
  printf("deleted item as: ",first->info);
  first=last=NULL;
 }
 else{
  printf("deleted item as: ",first->info);
  first = first->next;
  first->prev = NULL;
 }
}

int delete_end(){
 NodeType *temp;

 if(first==NULL){
  printf("void deletion");
 }
 else if(first==last){
  printf("deleted item as: ",first->info);
  first=last=NULL;
 }
 else{
  printf("deleted item as: ",last->info);
  temp = first;
  while(temp->next!=last){
   temp = temp->next;
  }
  temp->next = NULL;
  last = temp;
 }
 free(temp);
}

int display(){
 NodeType *temp;
 temp = first;
 if(first==NULL){
  printf("Empty Linked List");
 }
 else{
  while(temp!=NULL){
   printf("%d\t", temp->info);
   temp = temp->next;
  }
 }
 free(temp);
}