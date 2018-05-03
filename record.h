#ifndef RECORD_H
#define RECORD_H
	typedef struct in_Node_tag//for inner linked list
	{
		char subject_code[20];
		int marks;
		struct in_Node_tag *in_next;
		
	}in_Node;
	typedef struct Node_tag//for outer linked list
	{
		int roll_no;
		char name[20];
		struct Node_tag *next;
		struct in_Node_tag *inside;
		
	}Node;
	typedef struct get_Max
	{
		int roll;
		float m;
		struct get_Max *nxt;
	}sub_list;
	typedef struct k_popular
	{
		char sub[20];
		float average;
		struct k_popular *nxt;
	}sub_list2;
	Node* create(int n, Node *lptr);//creates record by taking inputs
	in_Node* in_create(int n, in_Node *lptr);//create the inner linked list
	Node* insert(Node *lptr, int Roll_no, char Subject_code[]);//inserts new record element or updates the existing one
	Node* mergesort_roll_no(Node *lptr);//merge_sort on roll_no
	Node* divide_roll_no(Node *lptr);
	Node* merge_roll_no(Node *lptr1, Node *lptr2);
	in_Node* mergesort_subject_code(in_Node *lptr);//merge_sort on subject_code
	in_Node* divide_subject_code(in_Node *lptr);
	in_Node* merge_subject_code(in_Node *lptr1, in_Node *lptr2);
	void print(Node *lptr);//to display a single record or all data in the record
	Node* delete_entry(Node *lptr, int Roll_no, char Subject_code[20]);//deletes an entry only if its in present in record
	int getNumRecords(Node *lptr);//returns no of active records!
	int isEmpty(Node *lptr);//is record empty??
	int isFull(Node *lptr);//it is considered that record is never full and we can always add data in it!
	void getMaxMarks(Node *lptr, char Subject_code[]);//to print roll no(s) of student who had scored highest marks in given subject code!
	sub_list* create_sub_list(Node *xptr, float M, sub_list *lptr);//to create sublist.....is used in getMaxmarks function
	sub_list* rev_mergesort_marks(sub_list *lptr);//Sorts sub_list according to marks in descending order!
	sub_list* rev_divide_marks(sub_list *lptr);//component of rev_-mergesort
	sub_list* rev_merge_marks(sub_list *lptr1, sub_list *lptr2);//component of rev_mergesort!
	void Find_topper(Node *lptr);//to find the roll no of student scoring highest total marks!
	void k_popular_subject(Node *lptr, int k);//to find out kth popular subject according to average marks scored by every studentnin that subject
	sub_list2* create_sub_list2(in_Node *xptr, float avg, sub_list2 *lptr);//to create sublist2 which stores subject code and average score scored by students in tha subject!
	sub_list2* rev_mergesort_avg(sub_list2 *lptr);//Sorts sub_list2 according to average in descending order!
	sub_list2* rev_divide_avg(sub_list2 *lptr);//component of rev_-mergesort_avg
	sub_list2* rev_merge_avg(sub_list2 *lptr1, sub_list2 *lptr2);//component of rev_mergesort-avg!
	void find_failures(Node *lptr, int p, int k);//List of students who have received marks less than p in k or more than k subjects!
	//Node* list_unique(Node *lptr);//removes duplicate entries(Having same roll_no and subject_codes)
	int in_num_nodes(in_Node *lptri);//to get number of subjects enrolled by a particular student!
	//Node* delete_node_complete(Node *lptr, Node *ptr);//to delete an entry completely from record!
	Node* list_unique_x(Node *lptr);//alternative
	Node* list_union(Node *lptr1, Node *lptr2);//takes list 1 and list 2 and creates list 3 as output which is union of list1 and 2!
	Node* list_intersection(Node *lptr1, Node *lptr2);//just link intersection of sets!
	Node* insert_externally(Node *lptr, Node *ptr);//lptr=head of list ptr=pointer to node whose data is to be inserted in new node created!
	Node* list_difference(Node *lptr1, Node *lptr2);
	Node* list_symmetric_difference(Node *lptr1, Node *lptr2);//output: keys present in list1 but not in list2 and keys present in list2 but not in list1
	Node* duplicate_list(Node *lptr);//to create a look alike record/list for sake of list_symm_diff
#endif
