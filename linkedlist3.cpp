/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* next;
  
  //constructor
  Node(int val){
      data = val;
      next = NULL;
  }
};


void insertAtFront(int val, Node** head){
   
    Node* newnode = new Node(val);
    if(*head == NULL)
    {
        *head = newnode;
        return;
    }
    
    newnode->next = *head;
    *head=newnode;
    return;
    
    
}

void display(Node *node)
{
    while (node != NULL)
    {
        cout<<" "<<node->data<<"->";
        node = node->next;
    }
    cout<<"NULL";
}

int main()
{
   Node* head = NULL;
   
   insertAtFront(1, &head);
   insertAtFront(3, &head);
   insertAtFront(5, &head);
   display(head);
    return 0;
}

