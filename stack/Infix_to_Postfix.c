#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<math.h>
#include<ctype.h>
int main()
{
 int i, j, pTop=-1, oTop=-1, len, length, precedency(char ch);
 char infix[100], opstack[100], poststack[100];

 printf("Enter the infix expression: ");
 gets(infix);

 len = strlen(infix);
 length = len;

 for(i=0; i<length; i++)
 {
  if(infix[i]=='(')
  {
   opstack[++oTop] = infix[i];
   len++;
  }
  else if(isalpha(infix[i]))
  {
   poststack[++pTop] = infix[i];
  }
  else if(infix[i]==')')
  {
   len++;
   while(opstack[oTop]!='(')
   {
    poststack[++pTop] = opstack[oTop];
    oTop--;
   }
   oTop--;
  }
  else
  {
   if(precedency(opstack[oTop])>=precedency(infix[i]))
   {
    poststack[++pTop] = opstack[oTop--];
    opstack[++oTop] = infix[i];
   }
   opstack[++oTop] = infix[i];
  }
 }

 while(oTop!=-1)
 {
  poststack[++pTop] = opstack[oTop];
  oTop--;
 }

 for(i=0; i<len; i++)
 {
  printf("%c", poststack[i]);
 }
 getch();
}

int precedency(char ch)
{
 switch(ch)
 {
  case '$':
  return(4);

  case '*':
  case '/':
  return(3);

  case '+':
  case '-':
  return(2);

  default:
  return(1);
 }
}