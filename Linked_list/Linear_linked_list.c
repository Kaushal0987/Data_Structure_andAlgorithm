#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<malloc.h>
#include<process.h>

int elm;
void insert_begi();
void insert_end();
void insert_betw();
void delete_begi();
void delete_end();
void delete_betw();
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
  printf("3: Insert node at between\n");
  printf("4: Delete node at begining\n");
  printf("5: Delete node at end\n");
  printf("6: Delete node at between\n");
  printf("7: Display the nodes\n");
  printf("8: exit\n");
  printf("Select an option of Linear Linked list operation: ");
  scanf("%d", &choice);

  switch(choice){

   case 1:
   insert_begi();
   break;

   case 2:
   insert_end();
   break;

   case 3:
   insert_betw();
   break;

   case 4:
   delete_begi();
   break;

   case 5:
   delete_end();
   break;

   case 6:
   delete_betw();
   break;

   case 7:
   display();
   break;

   case 8:
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
  Newnode->next = NULL;
  first = last = Newnode;
 }
 else{
  Newnode->next = first;
  first = Newnode;
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
  Newnode->next = NULL;
  first = last = Newnode;
 }
 else{
  Newnode->next = NULL;
  last->next = Newnode;
  last = Newnode;
 }
}

void insert_betw(){
 int pos, i;
 NodeType *Newnode, *temp;
 Newnode = (NodeType*)malloc(sizeof(NodeType));

 printf("Enter the element to insert: ");
 scanf("%d", &elm);
 Newnode->info = elm;

 printf("Enter the postion of the new node: ");
 scanf("%d", &pos);

 if(first==NULL){
  printf("void insertion");
  Newnode->next = NULL;
  first = last = Newnode;
 }
 else{
  temp=first;
  for(i=1; i<pos-1; i++){
   temp = temp->next;
  }
  Newnode->next = temp->next;
  temp->next = Newnode;
 }
 free(temp);
}

void delete_begi(){
 NodeType *temp;

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
  temp->next = NULL;
  last = temp;
 }
 free(temp);
}

void delete_betw(){
 NodeType *temp, *loc;
 int pos, i;

 if(first==NULL){
  printf("void deletion");
 }
 else if(first==last){
  printf("deleted item as: %d",first->info);
  first=last=NULL;
 }
 else{
  printf("Enter the postion of the new node: ");
  scanf("%d", &pos);

  temp = first;
  for(i=0; i<pos-1; i++){
   temp = temp->next;
  }
  loc = temp->next;
  printf("Deleated item as: %d",loc->next->info);
  temp->next = loc->next;
  free(temp);
 }
}

void display(){
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