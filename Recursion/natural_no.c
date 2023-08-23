#include<stdio.h>
int natural(int num)
{
 if(num==1)
 {
  return 1;
 }
 else
 {
  return num+natural(num-1);
 }
}
int main()
{
 int n;

 printf("Enter the no of natural numbers: ");
 scanf("%d", &n);

 printf("%d", natural(n));
}