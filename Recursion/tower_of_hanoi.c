#include<stdio.h>
#include<conio.h>
void TOH(int, char, char, char);

int main()
{
 int num;
 printf("Enter the number of disk: ");
 scanf("%d", &num);
 TOH(num, 'S', 'D', 'I');
}

void TOH(int n, char rodA, char rodB, char rodC){
 if (n==1){
  printf("move disk 1 from rod %c to rod %c\n",rodA, rodB);
  return;
 }
 else{
  TOH(n-1, rodA, rodC, rodB);
  printf("move disk %d from rod %c to rod %c\n",n, rodA, rodB);
  TOH(n-1, rodC, rodB, rodA);
 }
}