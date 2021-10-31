/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class Node{
  public:
  int data;
  Node* next;
  
  Node(int val){
      data = val;
      next = NULL;
  }
};

//insert nodes in ll
void insertAtLast( Node**head, int val){
    Node* newnode = new Node(val);
    if(*head == NULL){
        *head = newnode;
        return;
    }
    
    Node* temp = *head;
    while(temp ->next !=NULL){
      temp = temp ->next;
    }
     temp ->next = newnode;
    return;
}

//display linked list
void display (Node * head)
{
  Node *temp = head;

  if(head==NULL)
  cout<<"List is Empty";
  while (temp)
    {
      cout << temp->data << "->";
      temp = temp->next;
    }
  cout << "NULL";
}



int main()
{
     
    Node* head = NULL;
    
     
    insertAtLast( &head,1);
    insertAtLast(&head,2);
     
    display(head);
     

    
    return 0;
}



