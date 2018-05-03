#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "record.h"
Node* mergesort_roll_no(Node *lptr)//Sorts roll_no wise!
{
	Node *ptr,*head1=lptr;
	
	if(lptr->next!=NULL)
	{
	
		ptr=divide_roll_no(lptr);
		//printf("Divide ll 1:\n");
		//print(lptr);
		//printf("Divided ll 2: \n");
		//print(ptr);
		lptr=mergesort_roll_no(lptr);
		//printf("done");
		ptr=mergesort_roll_no(ptr);
		//printf("done1\n");
		head1=merge_roll_no(lptr,ptr);
	}

	return(head1);
}
Node* divide_roll_no(Node *lptr)
{
	Node *slow,*fast,*ptr;
	slow=lptr;
	fast=lptr->next->next;
	while(fast!=NULL)
	{
		slow=slow->next;
		fast=fast->next;
		if(fast!=NULL)
		{
			fast=fast->next;
		}
	}
	ptr=slow->next;
	slow->next=NULL;
	//printf("Sucessfull divide!\n");
	return(ptr);
}
Node* merge_roll_no(Node *lptr1, Node *lptr2)
{
	Node *p,*q,*r,*head2;
	p=lptr1;
	q=lptr2;
//	head2=NULL;
	if(p==NULL)
	{
		head2=q;
	}
	else if(q==NULL)
	{
		head2=p;
	}
	else
	{
		if(p->roll_no<q->roll_no)
		{
			head2=p;
			p=p->next;
		}
		else
		{
			head2=q;
			q=q->next;
		}
		
	}
	r=head2;
	while(p!=NULL&&q!=NULL)
	{
	
		
			if(p->roll_no<q->roll_no)
			{
				r->next=p;
				r=r->next;
				p=p->next;
			}
			else
			{
				r->next=q;
				r=r->next;
				q=q->next;
			}
	}
	
	if(p!=NULL)
	{
		r->next=p;
	}
	else if(q!=NULL)
	{
		r->next=q;
	}
	//printf("done2\n");
	//print(head2);
	return(head2);
}
in_Node* mergesort_subject_code(in_Node *lptr)
{
	in_Node *ptr,*head1=lptr;
	
	if(lptr->in_next!=NULL)
	{
	
		ptr=divide_subject_code(lptr);
		//printf("Divide ll 1:\n");
		//print(lptr);
		//printf("Divided ll 2: \n");
		//print(ptr);
		lptr=mergesort_subject_code(lptr);
		//printf("done");
		ptr=mergesort_subject_code(ptr);
		//printf("done1\n");
		head1=merge_subject_code(lptr,ptr);
	}

	return(head1);
}
in_Node* divide_subject_code(in_Node *lptr)
{
	in_Node *slow,*fast,*ptr;
	slow=lptr;
	fast=lptr->in_next->in_next;
	while(fast!=NULL)
	{
		slow=slow->in_next;
		fast=fast->in_next;
		if(fast!=NULL)
		{
			fast=fast->in_next;
		}
	}
	ptr=slow->in_next;
	slow->in_next=NULL;
	//printf("Sucessfull divide!\n");
	return(ptr);
}
in_Node* merge_subject_code(in_Node *lptr1, in_Node *lptr2)
{
	in_Node *p,*q,*r,*head2;
	p=lptr1;
	q=lptr2;
//	head2=NULL;
	if(p==NULL)
	{
		head2=q;
	}
	else if(q==NULL)
	{
		head2=p;
	}
	else
	{
		if(strcmp(p->subject_code,q->subject_code)==-1)
		{
			head2=p;
			p=p->in_next;
		}
		else
		{
			head2=q;
			q=q->in_next;
		}
		
	}
	r=head2;
	while(p!=NULL&&q!=NULL)
	{
	
		
			if(strcmp(p->subject_code,q->subject_code)==-1)
			{
				r->in_next=p;
				r=r->in_next;
				p=p->in_next;
			}
			else
			{
				r->in_next=q;
				r=r->in_next;
				q=q->in_next;
			}
	}
	
	if(p!=NULL)
	{
		r->in_next=p;
	}
	else if(q!=NULL)
	{
		r->in_next=q;
	}
	//printf("done2\n");
	//print(head2);
	return(head2);
}
Node* create(int n, Node *lptr)//creates record by taking inputs
{
	int num,i;
	i=1;
	Node *nptr,*ret;
	in_Node *in_lptr;
	;//useful while creating inner linked list!
	if(n==0)
	{
		ret=NULL;
	}
	else
	{
	
		while(n!=0)
		{
			in_lptr=NULL;
			nptr=(Node*)malloc(sizeof(Node));
			printf("Enter data of student %d: \n",i);
			printf("	Enter Name: \n	");
			scanf("%s",nptr->name);
			printf("	Enter Roll Number: \n	");
			scanf("%d",&nptr->roll_no);
			printf("	Enter number of enrolled courses: \n	");
			scanf("%d",&num);
			in_lptr=in_create(num,in_lptr);
			nptr->inside=in_lptr;
			nptr->next=lptr;
			lptr=nptr;
			n--;
			i++;
		}
		ret=mergesort_roll_no(lptr);
	}
	
	return(ret);
}
in_Node* in_create(int n, in_Node *lptr)//To create inner linked list
{
	in_Node *nptr,*ret;
	int i=1;
	while(n!=0)
	{
		nptr=(in_Node*)malloc(sizeof(in_Node));
		printf("	Enter Subject Code for subject%d: \n	",i);
		scanf("%s",nptr->subject_code);
		printf("	Enter marks obtained in subject%d: \n	",i);
		scanf("%d",&nptr->marks);
		nptr->in_next=lptr;
		lptr=nptr;
		n--;
		i++;
	}
	ret=mergesort_subject_code(lptr);
	return(ret);
}
Node* insert(Node *lptr, int Roll_no, char Subject_code[])//inserts new record element or updates the existing one
{
	int Marks,flag=0;
	int flag1=0;
	Node *xptr,*temp;
	in_Node *yptr,*xptri;
	xptr=lptr;	
	while(xptr!=NULL)
	{
		if(xptr->roll_no==Roll_no)
		{
				flag1=1;
				break;
		}
		else
		{
			xptr=xptr->next;
		}
	
	}
	if(flag1==1)
	{
		xptri=xptr->inside;
	}
	else
	{
		printf("No such roll no exist in current record!\n");
		printf("For insertion please re-enter complete information of student:\n");
		temp=create(1,lptr);
		printf("Successfully Inserted!");
		return(temp);
	}
	
	if(xptr!=NULL)
	{
		while(xptri!=NULL)
		{
			if(strcmp(xptri->subject_code,Subject_code)==0)
			{
				printf(" Roll number %d with Subject Code %s  already exist in record: \n",Roll_no,Subject_code);
				printf("Update marks of roll number %d!\n",Roll_no);
				printf("Enter corrected marks: \n");
				scanf("%d",&Marks);
				xptri->marks=Marks;
				printf("Successfully Updated!\n");
				flag=1;
				break;
			}
			else
			{
				xptri=xptri->in_next;
			}
		}
		if(flag==0)//this means that we should insert element in inner linked list....and its not the case of updation!
		{
			printf("Roll no %d is present in record, hence re-enter new subject code and respective marks obtained\n",Roll_no);
			yptr=in_create(1,xptr->inside);
			xptr->inside=yptr;
			printf("Successfully Updated!\n");
			
		}
		return(lptr);
	}

}
void print(Node *lptr)//to display a single record or all data in the record
{
	int x,r,flag=0;
	Node *temp,*ptr;
	in_Node *tempi,*ptri;
	temp=lptr;
	ptr=lptr;
	printf("Press\n1.To print record of a particular Roll Number \n2.To print complete file of records\n");
	scanf("%d",&x);
	switch(x)
	{
		case 1:
			printf("Enter Roll Number: \n");
			scanf("%d",&r);
			if(temp!=NULL)
			{
				while(temp!=NULL)
				{
					if(temp->roll_no==r)
					{
						flag=1;
						printf("	Name:%s\n",temp->name);
						printf("	Roll Number:%d\n",temp->roll_no);
						tempi=temp->inside;
						while(tempi!=NULL)
						{
							printf("	Subject Code:%s\n",tempi->subject_code);
							printf("		Marks:%d\n",tempi->marks);
							tempi=tempi->in_next;
						}
						break;
						
					}
					else
					{
						temp=temp->next;
					}
				}
				if(flag==0)
				{
					printf("No such entry exist in record!\n");
				}	
				break;
			}
			else
			{
				printf("Record is Empty!\n");
				break;
			}
			
		case 2:
			if(ptr!=NULL)
			{
				while(ptr!=NULL)
				{
					printf("	Name:%s\n",ptr->name);
					printf("	Roll Number:%d\n",ptr->roll_no);
					ptri=ptr->inside;
					while(ptri!=NULL)
					{
						printf("	Subject Code:%s\n",ptri->subject_code);
						printf("		Marks:%d\n",ptri->marks);
						ptri=ptri->in_next;
					}
					printf("\n\n");
					ptr=ptr->next;
				}
				break;
			}
			else
			{
				printf("Record is Empty!\n");
				break;
			}
	}
}
Node* delete_entry(Node *lptr, int Roll_no, char Subject_code[20])//deletes an entry only if its in present in record
{
	int flag1,flag,flag4;
	flag1=0;
	flag=0;
	Node *xptr,*temp,*prevo;
	in_Node *xptri,*prev;
	xptr=temp=lptr;
	while(xptr!=NULL)
	{
		if(xptr->roll_no==Roll_no)
		{
			flag1=1;
			break;
		}
		else
		{
			xptr=xptr->next;
		}
	}
	if(flag1==1)
	{
		xptri=xptr->inside;
		prev=xptri;
	}
	else
	{
		printf("No such Entry exist!\n");
	}
	if(xptr!=NULL)//we have a matching roll no
	{
		while(xptri!=NULL)
		{
			if(strcmp(xptri->subject_code,Subject_code)==0)
			{
				if(prev==xptri)
				{
					xptr->inside=xptri->in_next;
					
				}
				else
				{
					prev->in_next=xptri->in_next;
				}
				if(xptr->inside==NULL)
				{
					prevo=temp;
					if(temp==xptr)
					{
						prevo=prevo->next;
						temp=temp->next;
						free(xptr);
						lptr=temp;
						flag4=1;
					}
					if(flag4!=1)
					{
							while(temp!=xptr)
						{
							prevo=temp;
							temp=temp->next;
							//flag4=1;
						}
		
						if(prevo->next!=NULL)
						{
							prevo->next=xptr->next;
							free(xptr);
						}
						else //if there exist only one node in record and now it needs to be deleted!
						{
							lptr=NULL;
						}
					}
				}
				flag=1;
				free(xptri);
				printf("Successfully Deleted!\n");
				break;
			}
		
				
			else
			{
				prev=xptri;
				xptri=xptri->in_next;
			}
		}
		if(flag==0)
		{
			printf("No such Entry Exist!\n");
		}
	}
	else
	{
		printf("No such Entry exist!\n");
	}
	return(lptr);
}
int getNumRecords(Node *lptr)//returns no of active records!
{
	int count=0;
	while(lptr!=NULL)
	{
		count++;
		lptr=lptr->next;
	}
	return(count);
}
int isEmpty(Node *lptr)//is record empty??	
{
	int ret_val,n;
	n=getNumRecords(lptr);
	if(lptr==NULL)
	{
		ret_val=1;
	}
	else if(n==1)
	{
		if(lptr->inside==NULL)
		{
			ret_val=1;
		}
	}
	else
	{
		ret_val=0;
	}
	return(ret_val);
}
int isFull(Node *lptr)//it is considered that record is never full and we can always add data in it!
{
	return(0);//Not full!
}
void getMaxMarks(Node *lptr, char Subject_code[])//to print roll no(s) of student who had scored highest marks in given subject code!
{
	int flag=0;
	int flag2=0;
	Node *ptr;
	in_Node *ptri;
	sub_list *nptr,*xptr,*prev;
	ptr=lptr;
	nptr=NULL;
	while(ptr!=NULL)
	{
		ptri=ptr->inside;
		while(ptri!=NULL)
		{
			if(strcmp(ptri->subject_code,Subject_code)==0)
			{
				flag=1;
				nptr=create_sub_list(ptr,ptri->marks,nptr);
				break;
			}
			else
			{
				ptri=ptri->in_next;
			}
		}
		ptr=ptr->next;
	}
	if(nptr!=NULL)
	{
		xptr=rev_mergesort_marks(nptr);
		prev=xptr;
		while(xptr!=NULL)
		{
			if(prev->m==xptr->m)
			{
				printf("Roll number %d has scored maximum marks %f in subject code %s\n",xptr->roll,xptr->m,Subject_code);
				flag2=1;//no use!
			}
			prev=xptr;
			xptr=xptr->nxt;
		}	

	}
	else
	{
		printf("No student is enrolled in the subject named %s\n",Subject_code);
	}
}
sub_list* create_sub_list(Node *xptr, float M, sub_list *lptr)//to create sublist.....is used in getMaxmarks function
{
	sub_list *nptr;
	nptr=(sub_list*)malloc(sizeof(sub_list));
	nptr->roll=xptr->roll_no;
	nptr->m=M;
	nptr->nxt=lptr;
	lptr=nptr;
	return(lptr);
}
sub_list* rev_mergesort_marks(sub_list *lptr)//Sorts marks wise!
{
	sub_list *ptr,*head1=lptr;
	
	if(lptr->nxt!=NULL)
	{
	
		ptr=rev_divide_marks(lptr);
		//printf("Divide ll 1:\n");
		//print(lptr);
		//printf("Divided ll 2: \n");
		//print(ptr);
		lptr=rev_mergesort_marks(lptr);
		//printf("done");
		ptr=rev_mergesort_marks(ptr);
		//printf("done1\n");
		head1=rev_merge_marks(lptr,ptr);
	}

	return(head1);
}
sub_list* rev_divide_marks(sub_list *lptr)
{
	sub_list *slow,*fast,*ptr;
	slow=lptr;
	fast=lptr->nxt->nxt;
	while(fast!=NULL)
	{
		slow=slow->nxt;
		fast=fast->nxt;
		if(fast!=NULL)
		{
			fast=fast->nxt;
		}
	}
	ptr=slow->nxt;
	slow->nxt=NULL;
	//printf("Sucessfull divide!\n");
	return(ptr);
}
sub_list* rev_merge_marks(sub_list *lptr1, sub_list *lptr2)
{
	sub_list *p,*q,*r,*head2;
	p=lptr1;
	q=lptr2;
//	head2=NULL;
	if(p==NULL)
	{
		head2=q;
	}
	else if(q==NULL)
	{
		head2=p;
	}
	else
	{
		if(p->m>q->m)
		{
			head2=p;
			p=p->nxt;
		}
		else
		{
			head2=q;
			q=q->nxt;
		}
		
	}
	r=head2;
	while(p!=NULL&&q!=NULL)
	{
	
		
			if(p->m>q->m)
			{
				r->nxt=p;
				r=r->nxt;
				p=p->nxt;
			}
			else
			{
				r->nxt=q;
				r=r->nxt;
				q=q->nxt;
			}
	}
	
	if(p!=NULL)
	{
		r->nxt=p;
	}
	else if(q!=NULL)
	{
		r->nxt=q;
	}
	//printf("done2\n");
	//print(head2);
	return(head2);
}
void Find_topper(Node *lptr)//to print roll no(s) of student scoring highest total marks!
{
	int flag=0;
	int sum,count;
	float avg;
	Node *ptr;
	in_Node *ptri;
	sub_list *nptr,*xptr,*prev;
	ptr=lptr;
	nptr=NULL;
	while(ptr!=NULL)
	{
		sum=0;
		count=0;
		ptri=ptr->inside;
		while(ptri!=NULL)
		{
				sum=sum+ptri->marks;
				count++;
				
				ptri=ptri->in_next;
			
		}
		avg=(float)(sum/count);
		nptr=create_sub_list(ptr,avg,nptr);
		ptr=ptr->next;
	}
	xptr=rev_mergesort_marks(nptr);
	prev=xptr;
	while(xptr!=NULL)
	{
		if(prev->m==xptr->m)
		{
				printf("Roll number %d is topper with total average marks %f\n",xptr->roll,xptr->m);
		}
			prev=xptr;
			xptr=xptr->nxt;
	}	
}
void k_popular_subject(Node *lptr, int k)//to find out kth popular subject according to average marks scored by every studentnin that subject
{
	int sum,count,rank,flag,n;
	float avg;
	Node *temp,*ptr;
	in_Node *tempi,*ptri;
	sub_list2 *xptr,*nptr,*prev;
	nptr=NULL;
	ptr=lptr;
	while(ptr!=NULL)
	{
		ptri=ptr->inside;
		
		while(ptri!=NULL)
		{
			temp=lptr;
			sum=0;
			count=0;
			while(temp!=NULL)
			{
				tempi=temp->inside;
				while(tempi!=NULL)
				{
					if(strcmp(ptri->subject_code,tempi->subject_code)==0)
					{
						sum=sum+tempi->marks;
						count++;
						//printf("Sum and count calculated!\n");
					}
					tempi=tempi->in_next;
				}
				temp=temp->next;
			}
			avg=(float)(sum/count);
			printf("Average Calculated!\n");
			nptr=create_sub_list2(ptri,avg,nptr);
			ptri=ptri->in_next;
		}
		ptr=ptr->next;
	}
	xptr=rev_mergesort_avg(nptr);
	prev=xptr;
	rank=0;
	flag=0;
	n=1;
	while(xptr!=NULL)
	{
		
		printf("In to while of rank!\n");
		if(xptr->average!=prev->average&&strcmp(xptr->sub,prev->sub)!=0)
		{
			rank++;
			n++;
			if(rank==k)
			{
				flag=1;
				printf("The %s holds rank %d in popularity with average score of %f\n",prev->sub,k,prev->average);
				break;
			}
			
			printf("Incremented rank!\n");
		}
		prev=xptr;
		xptr=xptr->nxt;
	}
	if(xptr==NULL&&flag==0&&k<=n)
	{
		printf("The %s holds rank %d in popularity with average score of %f\n",prev->sub,k,prev->average);//to printone with lowest popularuty
	}
	else if(k>n||k==0)
	{
		printf("No subject has ranked %d\n",k);
	}

}
sub_list2* create_sub_list2(in_Node *xptr, float avg, sub_list2 *lptr)//to create sublist2 which stores subject code and average score scored by students in tha subject!
{
	sub_list2 *nptr;
	nptr=(sub_list2*)malloc(sizeof(sub_list2));
	strcpy(nptr->sub,xptr->subject_code);
	nptr->average=avg;
	nptr->nxt=lptr;
	lptr=nptr;
	return(lptr);
}
sub_list2* rev_mergesort_avg(sub_list2 *lptr)//Sorts sub_list2 according to average in descending order!
{
	sub_list2 *ptr,*head1=lptr;
	
	if(lptr->nxt!=NULL)
	{
	
		ptr=rev_divide_avg(lptr);
		//printf("Divide ll 1:\n");
		//print(lptr);
		//printf("Divided ll 2: \n");
		//print(ptr);
		lptr=rev_mergesort_avg(lptr);
		//printf("done");
		ptr=rev_mergesort_avg(ptr);
		//printf("done1\n");
		head1=rev_merge_avg(lptr,ptr);
	}

	return(head1);
}
sub_list2* rev_divide_avg(sub_list2 *lptr)//component of rev_-mergesort_avg
{
	sub_list2 *slow,*fast,*ptr;
	slow=lptr;
	fast=lptr->nxt->nxt;
	while(fast!=NULL)
	{
		slow=slow->nxt;
		fast=fast->nxt;
		if(fast!=NULL)
		{
			fast=fast->nxt;
		}
	}
	ptr=slow->nxt;
	slow->nxt=NULL;
	//printf("Sucessfull divide!\n");
	return(ptr);
}
sub_list2* rev_merge_avg(sub_list2 *lptr1, sub_list2 *lptr2)//component of rev_mergesort-avg!
{
	sub_list2 *p,*q,*r,*head2;
	p=lptr1;
	q=lptr2;
//	head2=NULL;
	if(p==NULL)
	{
		head2=q;
	}
	else if(q==NULL)
	{
		head2=p;
	}
	else
	{
		if(p->average>q->average)
		{
			head2=p;
			p=p->nxt;
		}
		else
		{
			head2=q;
			q=q->nxt;
		}
		
	}
	r=head2;
	while(p!=NULL&&q!=NULL)
	{
	
		
			if(p->average>q->average)
			{
				r->nxt=p;
				r=r->nxt;
				p=p->nxt;
			}
			else
			{
				r->nxt=q;
				r=r->nxt;
				q=q->nxt;
			}
	}
	
	if(p!=NULL)
	{
		r->nxt=p;
	}
	else if(q!=NULL)
	{
		r->nxt=q;
	}
	//printf("done2\n");
	//print(head2);
	return(head2);
}
void find_failures(Node *lptr, int p, int k)//List of students who have received marks less than p in k or more than k subjects!
{
	int count,flag;
	Node *temp;
	in_Node *tempi;
	temp=lptr;
	while(temp!=NULL)
	{
		count=0;
		flag=0;
		tempi=temp->inside;
		while(tempi!=NULL)
		{
			if(tempi->marks<p)
			{
				count++;
			}
			if(count==k)
			{
				flag=1;
				break;
			}
			tempi=tempi->in_next;
		}
		if(flag==1)
		{
			printf("Student %s (Roll number %d) is fail!\n",temp->name,temp->roll_no);
		}
		temp=temp->next;
	}
}

int in_num_nodes(in_Node *lptri)//to get number of subjects enrolled by a particular student!
{
	in_Node *tempi;
	int count=0;
	tempi=lptri;
	while(tempi!=NULL)
	{
		count++;
		tempi=tempi->in_next;
	}
	return(count);
}

Node* list_unique_x(Node *lptr)//alternative
{
	int count,flag,k1,k2;
	Node *temp1,*temp2,*prev,*ret;
	in_Node *temp1i,*temp2i;
	temp1=lptr;
	ret=lptr;
	while(temp1!=NULL)
	{
		prev=temp1;
		temp2=temp1->next;
		while(temp2!=NULL)
		{
			count=0;
			flag=0;
			//printf("Inside while 1\n");
			if(temp1->roll_no==temp2->roll_no)
			{
				temp1i=temp1->inside;
				temp2i=temp2->inside;
				k1=in_num_nodes(temp1i);
				k2=in_num_nodes(temp2i);
				if(k1==k2)
				{
					//printf("No of nodes matched!\n");
					while(temp1i!=NULL)
					{
						if(strcmp(temp1i->subject_code,temp2i->subject_code)==0)
						{
							count++;
							
						}
						temp1i=temp1i->in_next;
						temp2i=temp2i->in_next;
					}
					if(count==k1)
					{
						prev->next=temp2->next;
						free(temp2);
						//printf("Freeing memory");
						temp2=prev->next;
						flag=1;
						//printf("Setted flag\n");
					}
				}
			}
			if(flag==0)
			{
				prev=temp2;
				temp2=temp2->next;
			}
			
		}
		temp1=temp1->next;
	}
	return(ret);
}
Node* list_union(Node *lptr1, Node *lptr2)//takes list 1 and list 2 and creates list 3 as output which is union of list1 and 2!
{
	Node *ptr,*start,*xptr,*ret;
	ptr=lptr1;
	start=lptr1;
	xptr=NULL;
	ret=NULL;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=lptr2;
	xptr=list_unique_x(start);
	ret=mergesort_roll_no(xptr);
	return(ret);
}
Node* list_intersection(Node *lptr1, Node *lptr2)//just like intersection of sets!
{
	int count,k1,k2,flag;
	Node *list1,*list2,*xptr,*ret,*ptr;
	in_Node *list1i,*list2i;
	list1=NULL;
	list2=NULL;
	list1i=NULL;
	list2i=NULL;
	ptr=NULL;
	xptr=NULL;
	ret=NULL;
	list1=list_unique_x(lptr1);
	list2=list_unique_x(lptr2);
	ptr=list2;
	while(list1!=NULL)
	{
		list2=ptr;
		while(list2!=NULL)
		{
			count=0;
			if(list1->roll_no==list2->roll_no)
			{
				list1i=list1->inside;
				list2i=list2->inside;
				k1=in_num_nodes(list1i);
				k2=in_num_nodes(list2i);
				if(k1==k2)
				{
					//printf("No of nodes matched!\n");
					while(list1i!=NULL)
					{
						if(strcmp(list1i->subject_code,list2i->subject_code)==0)
						{
							count++;
							
						}
						list1i=list1i->in_next;
						list2i=list2i->in_next;
					}
					if(count==k1)
					{
						flag=1;
						xptr=insert_externally(xptr,list2);
						printf("Inserted Successfully!");
					}
				}
			}
			if(flag!=1)
			{
				printf("Not found!!\n");
			}
			list2=list2->next;
		}
		list1=list1->next;
	}
	if(flag==1)
	{
		ret=mergesort_roll_no(xptr);
		//printf("done sorting\n");
		
	}
	//printf("Returning value!\n");
	return(ret);

}
Node* insert_externally(Node *lptr, Node *ptr)//lptr=head of list ptr=pointer to node whose data is to be inserted in new node created!
{
	int i;
	Node *neww;
	in_Node *newwi,*lptri,*reti,*ptri;
	ptri=NULL;
	reti=NULL;
	lptri=NULL;
	newwi=NULL;
	neww=(Node*)malloc(sizeof(Node));
	neww->roll_no=ptr->roll_no;
	strcpy(neww->name,ptr->name);
	neww->next=lptr;
	lptr=neww;
	ptri=ptr->inside;
	newwi=neww->inside;
	for(i=0;i<in_num_nodes(ptri);i++)
	{
		newwi=(in_Node*)malloc(sizeof(in_Node));
		strcpy(newwi->subject_code,ptri->subject_code);
		newwi->marks=ptri->marks;
		newwi->in_next=lptri;
		lptri=newwi;
	}
	reti=mergesort_subject_code(lptri);
	neww->inside=reti;
	return(lptr);
	
}	
Node* list_difference(Node *lptr1, Node *lptr2)
{
	int count,flag,k1,k2;
	Node *list1,*list2,*ptr,*prev,*temp,*fix;
	in_Node *list1i,*list2i;
	list2=NULL;
	list1=list_unique_x(lptr1);
	fix=list1;//savng current head of list1
	list2=list_intersection(list1,lptr2);
	//printf("Intersected set returned successfully!\n");
	ptr=list2;//for saving head of list2;
	prev=list1;
	while(list1!=NULL)
	{
		//printf("Entering loop1\n");
		list2=ptr;
		while(list2!=NULL)
		{
			flag=0;
			count=0;
			//printf("Entering loop2\n");
			if(list1->roll_no==list2->roll_no)
			{
				
				list1i=list1->inside;
				list2i=list2->inside;
				k1=in_num_nodes(list1i);
				k2=in_num_nodes(list2i);
				if(k1==k2)
				{
					while(list1i!=NULL)
					{
						if(strcmp(list1i->subject_code,list2i->subject_code)==0)
						{
							count++;
						}
						list1i=list1i->in_next;
						list2i=list2i->in_next;
		
					}
					if(count==k1)
					{
						//printf("Matched!\n");
						if(prev==list1)//first node deletion case
						{
							temp=list1;
							list1=list1->next;
							free(temp);
							prev=list1;
							fix=list1;
							//printf("removed extra Node and fixed head ptr\n");
						}
						else
						{
							prev->next=list1->next;
							free(list1);
							list1=prev->next;
					
						}
						flag=1;
						break;
					}
				}
				
			}
			list2=list2->next;
		}
		if(flag!=1)
		{
			prev=list1;
			list1=list1->next;
		}
	}
	return(fix);
}
Node* list_symmetric_difference(Node *lptr1, Node *lptr2)//output: keys present in list1 but not in list2 and keys present in list2 but not in list1
{
	Node *dlptr1,*dlptr2,*sub1,*sub2,*ret;
	dlptr1=duplicate_list(lptr1);
	dlptr2=duplicate_list(lptr2);
	sub1=list_union(lptr1,lptr2);
	sub2=list_intersection(dlptr1,dlptr2);
	ret=list_difference(sub1,sub2);
	return(ret);
}
Node* duplicate_list(Node *lptr)//to create a look alike record/list for sake of list_symm_diff
{
	Node *new_node,*temp,*head;
	in_Node *new_nodei,*tempi,*headi;
	temp=lptr;
	head=NULL;
	while(temp!=NULL)
	{
		new_node=(Node*)malloc(sizeof(Node));
		new_node->roll_no=temp->roll_no;
		strcpy(new_node->name,temp->name);
		new_node->next=head;
		head=new_node;
		tempi=temp->inside;
		headi=NULL;
		while(tempi!=NULL)
		{
			new_nodei=(in_Node*)malloc(sizeof(in_Node));
			strcpy(new_nodei->subject_code,tempi->subject_code);
			new_nodei->marks=tempi->marks;
			new_nodei->in_next=headi;
			headi=new_nodei;
			tempi=tempi->in_next;
		}
		headi=mergesort_subject_code(headi);
		new_node->inside=headi;	
		temp=temp->next;	
	}
	head=mergesort_roll_no(head);
	return(head);
}
