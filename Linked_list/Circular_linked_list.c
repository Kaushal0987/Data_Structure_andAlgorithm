#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<malloc.h>
#include<process.h>

int elm;
void insert_begi();
void insert_end();
void delete_begi();
void delete_end();
void display();

struct Node
{
 int info;
 struct Node *next;
};
typedef struct Node NodeType;
NodeType *first=NULL, *last=NULL;

int main(){

 int choice;
 char ch;

 do
 {
  printf("1: Insert node at begining\n");
  printf("2: Insert node at end\n");
  printf("3: Delete node at begining\n");
  printf("4: Delete node at end\n");
  printf("5: Display the nodes\n");
  printf("6: exit\n");
  printf("Select an option of Circular Linked list operation: ");
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

void insert_begi(){
 NodeType *Newnode;
 Newnode = (NodeType*)malloc(sizeof(NodeType));

 printf("Enter the element to insert: ");
 scanf("%d", &elm);

 Newnode->info = elm;
 if(first==NULL){
  Newnode->next = Newnode;
  first = last = Newnode;
 }
 else{
  Newnode->next = first;
  first = Newnode;
  last->next = first;
 }
}

void insert_end(){
 NodeType *Newnode;
 Newnode = (NodeType*)malloc(sizeof(NodeType));

 printf("Enter the element to insert: ");
 scanf("%d", &elm);

 Newnode->info = elm;

 if(last==NULL){
  printf("Void Insertion");
  Newnode->next = Newnode;
  first = last = Newnode;
 }
 else{
  Newnode->next = first;
  last->next = Newnode;
  last = Newnode;
 }
}

void delete_begi(){

 if(first==NULL){
  printf("void deletion");
 }
 else if(first==last){
  printf("deleted item as: %d",first->info);
  first=last=NULL;
 }
 else{
  printf("deleted item as: %d",first->info);
  first = first->next;
 }
}

void delete_end(){
 NodeType *temp;

 if(first==NULL){
  printf("void deletion");
 }
 else if(first==last){
  printf("deleted item as: %d",first->info);
  first=last=NULL;
 }
 else{
  printf("deleted item as: %d",last->info);
  temp = first;
  while(temp->next!=last){
   temp = temp->next;
  }
  temp->next = first;
  last = temp;
 }
 free(temp);
}

void display(){
 NodeType *temp;
 temp = first;
 if(first==NULL){
  printf("Empty Linked List");
 }
 else{
  while(temp!=first){
   printf("%d\t", temp->info);
   temp = temp->next;
  }
 }
 free(temp);
}