#include<stdio.h>

static int sum=0, rem;

int reverse(int num)
{
 if(num)
 {
  rem=num%10;
  sum=sum*10+rem;
  reverse(num/10);
 }
 else
 {
   return sum;
 }
}
int main()
{
 int num, revnum;

 printf("Enter the number to reverse: ");
 scanf("%d", &num);

 revnum = reverse(num);
 printf("%d", revnum);
}