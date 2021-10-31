/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

class Node
{

public:
  int data;
  Node *next;

    Node (int val)
  {
    data = val;
    next = NULL;
  }
};


void
insertAfter (int pos, int val, Node ** head)
{
  Node *newnode = new Node (val);
  Node *temp = *head;
  pos = pos - 1;
  while (pos--)
    {
      temp = temp->next;
    }

  newnode->next = temp->next;
  temp->next = newnode;
  return;
}

void insertBefore(int pos, int val, Node** head){
    Node* newnode = new Node(val);
    Node* temp, *pre;
    temp=pre = *head;
    pos-=1;
    while(pos--){
        pre = pre ->next;
        temp = pre->next;
    }
    
    newnode->next = pre->next;
    pre->next = newnode;
    return;
}



void
display (Node * node)
{
  while (node != NULL)
    {
      cout << " " << node->data << "->";
      node = node->next;
    }
  cout << "NULL";
}

int
main ()
{
  Node *head = NULL;
  Node *revhead = NULL;

  Node *firstnode = new Node (1);
  Node *secondnode = new Node (2);
  Node *thirdnode = new Node (3);
  Node *lastnode = new Node (4);

  head = firstnode;
  firstnode->next = secondnode;
  secondnode->next = thirdnode;
  thirdnode->next = lastnode;
  lastnode->next = NULL;

  display (head);
  insertAfter (1, 9, &head);
  cout << endl;
  display (head);
   cout << endl;
  insertBefore(1,5, &head);
  display(head);
 

  return 0;
}


