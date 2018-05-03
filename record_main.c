#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "record.h"
int main()
{
	int x1,xs1,xs2,num,roll,value,k1,m,n,n1,n2;
	Node *ptr,*ans,*ptr1,*ptr2;
	char sc[20];
	ptr=NULL;
	ans=NULL;
	printf("Welcome User!!\n\n");
	printf("This app have two sets of operations: \n");
	l2:
	printf("Press 1.Normal Opreations\n");
	printf("Press 2.List Operations\n\n");
	printf("Press 0.Exit App!\n");
	printf("Enter Your Choice: \n");
	scanf("%d",&x1);
	switch(x1)
	{
		case 1:
			printf("Enter Strength of class1: \n");
			scanf("%d",&num);
			ptr=create(num,ptr);
			printf("Record1 Successfully Created!");
			print(ptr);
			l1:
			printf("\n\n");
			printf("Select Operation: \n");
			printf("Press 1. Insertion\n");
			printf("Press 2. Deletion\n");
			printf("Press 3. Number of active records in list\n");
			printf("Press 4. isEmpty? \n");
			printf("Press 5. isFull?\n");
			printf("Press 6. Maximum marks in a subject\n");
			printf("Press 7. Find Topper\n");
			printf("Press 8. Kth Popular Subject\n");
			printf("Press 9. Find Failures\n");
			printf("Press 0. Exit\n");
			printf("Enter Your Choice: \n");
			scanf("%d",&xs1);
			switch(xs1)
			{
				case 1:
					printf("\nINSERTION!\n");
					printf("Enter Roll Number to insert/update: \n");
					scanf("%d",&roll);
					printf("Enter Subject Code:\n");
					scanf("%s",sc);
					ptr=insert(ptr,roll,sc);
					print(ptr);
					goto l1;
				case 2:
					printf("\nDELETION!\n");
					printf("Enter Roll Number : \n");
					scanf("%d",&roll);
					printf("Enter Subject Code:\n");
					scanf("%s",sc);
					ans=delete_entry(ptr,roll,sc);
					print(ans);
					goto l1;
				case 3:
					printf("\nNUMBER OF ACTIVE RECORDS\n");
					value=getNumRecords(ptr);
					printf("Number of active records are %d\n",value);
					goto l1;
				case 4:
					printf("\nisEMPTY?\n");
					value=isEmpty(ptr);
					if(value==0)
					{
						printf("Records are not Empty!\n");
					}
					else
					{
						printf("Records are Empty!\n");
					}
					goto l1;
				case 5:
					printf("\nisFULL?\n");
					value=isFull(ptr);
					if(value==0)
					{
						printf("Records are not Full!\n");
					}
					else
					{
						printf("Records are Full...There is no space!!\n");
					}
					goto l1;
				case 6:
					printf("\n SUBJECT TOPPER\n");
					printf("Enter Subject Code:\n");
					scanf("%s",sc);
					getMaxMarks(ptr,sc);
					goto l1;
				case 7:
					printf("\nCLASS TOPPER\n");
					Find_topper(ptr);
					goto l1;
				case 8:
					printf("\nKth POPULAR SUBJECT\n");
					printf("Enter a rank of popularity: \n");
					scanf("%d",&k1);
					k_popular_subject(ptr,k1);
					goto l1;
				case 9:
					printf("\nFAILURES!\n");
					printf("Enter Cutoff Marks: \n");
					scanf("%d",&m);
					printf("No of subjects: \n");
					scanf("%d",&n);
					find_failures(ptr,m,n);
					goto l1;
				case 0:
					goto l2;
			}
		case 2:
			l3:
			printf("\n\n");
			printf("Select Operation: \n");
			printf("Press 1. List Unique\n");
			printf("Press 2. List Union\n");
			printf("Press 3. List Intersection\n");
			printf("Press 4. List Difference \n");
			printf("Press 5. List Symmetric Difference\n");
			printf("Press 0. Exit\n");
			printf("Enter Your Choice: \n");
			scanf("%d",&xs2);
			switch(xs2)
			{
				case 1:
					ptr1=NULL;
					ptr2=NULL;
					ans=NULL;
					printf("\nLIST UNIQUE\n");
					printf("Enter Strength of class1: \n");
					scanf("%d",&n1);
					ptr1=create(n1,ptr1);
					printf("Record1 Successfully Created!\n");
					print(ptr1);
					ans=list_unique_x(ptr1);
					print(ans);
					goto l3;
				case 2:
					ptr1=NULL;
					ptr2=NULL;
					ans=NULL;
					printf("\nLIST UNION\n");
					printf("Enter Strength of class1: \n");
					scanf("%d",&n1);
					ptr1=create(n1,ptr1);
					printf("Record1 Successfully Created!\n");
					print(ptr1);
					printf("Enter Strength of class2: \n");
					scanf("%d",&num);
					ptr2=create(num,ptr2);
					printf("Record2 Successfully Created!");
					print(ptr2);
					ans=list_union(ptr1,ptr2);
					print(ans);
					goto l3;
				case 3:
					ptr1=NULL;
					ptr2=NULL;
					ans=NULL;
					printf("\nLIST INTERSECTION\n");
					printf("Enter Strength of class1: \n");
					scanf("%d",&n1);
					ptr1=create(n1,ptr1);
					printf("Record1 Successfully Created!\n");
					print(ptr1);
					printf("Enter Strength of class2: \n");
					scanf("%d",&num);
					ptr2=create(num,ptr2);
					printf("Record2 Successfully Created!");
					print(ptr2);
					ans=list_intersection(ptr1,ptr2);
					print(ans);
					goto l3;
				case 4:
					ptr1=NULL;
					ptr2=NULL;
					ans=NULL;
					printf("\nLIST DIFFERENCE\n");
					printf("Enter Strength of class1: \n");
					scanf("%d",&n1);
					ptr1=create(n1,ptr1);
					printf("Record1 Successfully Created!\n");
					print(ptr1);
					printf("Enter Strength of class2: \n");
					scanf("%d",&num);
					ptr2=create(num,ptr2);
					printf("Record2 Successfully Created!");
					print(ptr2);
					ans=list_difference(ptr1,ptr2);
					print(ans);
					goto l3;
				case 5:
					ptr1=NULL;
					ptr2=NULL;
					ans=NULL;
					printf("\nLIST SYMMETRIC DIFFERENCE\n");
					printf("Enter Strength of class1: \n");
					scanf("%d",&n1);
					ptr1=create(n1,ptr1);
					printf("Record1 Successfully Created!\n");
					print(ptr1);
					printf("Enter Strength of class2: \n");
					scanf("%d",&num);
					ptr2=create(num,ptr2);
					printf("Record2 Successfully Created!");
					print(ptr2);
					ans=list_symmetric_difference(ptr1,ptr2);
					print(ans);
					goto l3;
				case 0:
					goto l2;
			}
			case 0:
				printf("Thanks For using!\n");
				printf("Have a good day!\n");
				break;		
	}
	return(0);
}
