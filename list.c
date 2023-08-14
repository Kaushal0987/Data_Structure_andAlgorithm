#include<stdio.h>
#include<conio.h>
#include<process.h>

void Create();
void Insert();
void Update();
void Merge();
void Delete();
void Display();

int a[100], n;
int main()
{
	int ch;
	while(1){
	printf("Menu\n");
	printf("1.Create\n");
	printf("2.Insert\n");
	printf("3.Update\n");
	printf("4.Merge\n");
	printf("5.Delete\n");
	printf("6.Display\n");
	printf("Enter Your Choice: ");
	scanf("%d", &ch);
	switch(ch)
	{
		
		case 1:
			Create();
			break;
		case 2:
			Insert();
			break;            
		case 3:
			Update();
			break;
		case 4:
			Merge();
			break;
		case 5:
			Delete();
			break;
		case 6:
			Display();
			break;
		case 7:
			exit(1);
			break;
		default :
			printf("Wrong Choice!! Try Again");
	}
}
}

void Create()
{
	int i;
	printf("Enter the size of array: ");
	scanf("%d", &n);
	printf("Enter the elements of an array: \n");
	for(i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
	}
}

void Insert()
{
	int i, pos, el;
	printf("Enter the position to insert element: ");
	scanf("%d", &pos);
	printf("Enter the element: ");
	scanf("%d", &el);
	for(i=n-1;i>=pos;i--) 
	{
		a[i+1] = a[i];
	}
	a[pos] = el;
	n=n+1;
	
}

void Update()
{
	int pos, el;
	printf("Enter the position you want to update: ");
	scanf("%d", &pos);
	printf("\nEnter the element to update: ");
	scanf("%d", &el);
	a[pos] = el;
}

void Merge()
{
	int i, j=n, m, b[100];
	printf("Enter the size of second list: ");
	scanf("%d", &m);
	printf("Enter the elements of list: \n");
	for(i=0;i<m;i++)
	{
		scanf("%d", &b[i]);
	}
	printf("The list after merging: \n");
	for(i=0;i<m;i++)
	{
		a[j] = b[i];
		j++;
		n=n+1;
	}
}

void Delete()
{
	int i, pos;
	printf("Enter the position of element to be deleted: ");
	scanf("%d", &pos);
	for(i=pos;i<n;i++)
	{
		a[i] = a[i+1];
	}
	n = n-1;
}

void Display()
{
	int i;
	printf("The elements of array: \n");
	for(i=0;i<n;i++)
	{
		printf("%d\t", a[i]);
	}
}
