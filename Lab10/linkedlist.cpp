#include <iostream>
using namespace std;

#include "function.h"

 //Node Definition:
 
  /*struct Node { 
     int data; 
     struct Node *next; 
  };*/
 


/*
 * Lab10 Part 1: Implement push and print functions for creating
 * a linked list.
*/
Node* push(Node* head, int new_data) { 
   /*
    * Implement push function to add a new element to the linked list
    *
    * input parameter:   pointer to head of linked list,
    *                    new_data to add to the linked list
    * returns: Return the new head of the linked list after push
    *
    * E.g.  If linked list was 3->2->1->NULL before push  with 
    *       head pointing to 3 and new_data is 4, then after push ,
    *       linked list should be 4->3->2->1->NULL and head should
    *       point to 4.
   */
  
  //Node* newnode = new Node();
  struct Node* newnode = (struct Node*)malloc(sizeof(struct Node)); //or use Node* new_node = new Node();
  newnode -> data = new_data;
  newnode -> next = head;
  head = newnode;
   /*if(head == NULL) {
   	head -> data = new_data;
   	head -> next = NULL;
   } else {
   	Node* new_node = new Node();
   	new_node -> data = new_data;
   	new_node -> next = head;
   }*/
   return head;

}

void print(Node* head) { 
   /*
    * Implement print function to print the entire linked list
    *
    * input parameter:   pointer to head of linked list
    * returns: void
    *
    * E.g.  Print linked list like this: 4->3->2->1->NULL
   */

   while (head != NULL) {
   		cout << head->data << "->";
   		head = head -> next;
   }
   cout << "NULL ";
}


/*
 * Lab10 Part 2: Implementing Stack using linked list.
 *                
 * Using previous implemention of push function, add 4 more functions
 * i.e. isEmpty, size, top and pop to complete the implementation of 
 * stack using linked list.
*/
bool isEmpty(Node* head) {
   /*
    * Implement isEmpty function to check if the stack is empty.
    *
    * input parameter:   pointer to head of stack
    * returns: bool i.e. If empty return true else return false
   */

   return head == NULL; //returns true or false

}

int size(Node* head) {
   /*
    * Implement size function to get number of elements in stack.
    *
    * input parameter:   pointer to head of stack
    * returns: size of stack. If empty, return 0
   */
	int ctr = 0;
   if(isEmpty(head)){
   	return 0;
   } else {
   		while (head != NULL){
   			ctr ++;
   			head = head -> next;
   		}
   }
   return ctr;

}

int top(Node* head) {
   /*
    * Implement top function to fetch the top element of stack
    *
    * input parameter:   pointer to head of stack
    * returns: Return the data in top element of the stack
    *
    * E.g.  If stack was 3->2->1->NULL then top should return 3
   */

   if(!isEmpty(head))
   		return head->data;
   else
   		exit(1);

}

Node* pop(Node* head) {
   /*
    * Implement pop function to remove the top element of stack
    *
    * input parameter:   pointer to head of stack
    * returns: Return the new head pointer of the stack after pop
    *
    * E.g.  If stack was 4->3->2->1->NULL before pop with 
    *       head pointing to 4, then after pop, stack should
    *       be 3->2->1->NULL with head pointing to 4
   */

   //struct Node* temp;
   //struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	Node* temp = new Node();
   if(head == NULL){
   	exit(1);
   } else {
   	temp = head;
   	head = head -> next;
   	temp -> next = NULL;
   	//cout << "cow";
   	delete(temp);
   }
   //cout << "chicken";
   return head;
}


/*
 * Lab10 Part 3: Find the middle element of a linked list
*/
Node* middle_element(Node* head) {
   /* 
    * input parameter:   pointer to head of linked list
    * returns: Return the middle element of linked list
    *
    * E.g. For 4->3->2->1->NULL, return node with value 2. (Even size)
    *      For 5->4->3->2->1->NULL, return node with value 3 (Odd size)
   */
   int ctr = 0;
   int sizer;
   sizer = size(head);
   int middle_element_loc;

   if (sizer % 2 == 0){ //finds the middle element
   		middle_element_loc = sizer/2;
   } else {
   		middle_element_loc = sizer/2;
   }
   //cout << "middle_element_loc: " << middle_element_loc << endl;
   if (isEmpty(head)){
   	return NULL;
   }
   while (ctr <= middle_element_loc){ //iterates through linked list until hits middle element
   		if(ctr == middle_element_loc){
   			//cout <<"made it here" << endl;
   			return head;
   		}
   		//cout << "ctr: " << ctr << endl;
   		head = head -> next;
   		ctr++;
   }

}

/*
 * Lab10 Part 4: Remove middle node from Linked List
*/
Node* remove_middle_element(Node* head, Node* middle_node) {
   /* 
    * input parameter:   pointer to head of linked list,
    *                    pointer to the node to remove
    * returns: Return the head pointer
    *
    * E.g. For 5->4->3->2->1->NULL, after this operation the
    *      linked list will become 5->4->2->1->NULL
   */
	if (head == NULL) 
        return NULL; 
    if (head->next == NULL) 
    { 
        delete head; 
        return NULL; 
    } 
  

 	struct Node *slow_ptr = head; 
    struct Node *fast_ptr = head; 
  
    // Find the middle and previous of middle. 
    struct Node *prev; // To store previous of slow_ptr 
    while (fast_ptr != NULL && fast_ptr->next != NULL) 
    { 
        fast_ptr = fast_ptr->next->next; 
        prev = slow_ptr; 
        slow_ptr = slow_ptr->next; 
    } 
  
    //Delete the middle node 
    prev->next = slow_ptr->next; 
    delete slow_ptr; 
  
    return head; 
   /*sizer = size(head);
   int middle_element_loc;

   if (sizer % 2 == 0){ //finds the middle element
   		middle_element_loc = sizer/2;
   } else {
   		middle_element_loc = sizer/2;
   }

   return head;*/

}