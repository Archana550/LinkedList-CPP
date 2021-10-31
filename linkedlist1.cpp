/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;
class node
{
public:
  int data;
  node *next;

    node (int val)
  {
    data = val;
    next = NULL;
  }
};

//display linked list
void display (node * head)
{
  node *temp = head;

  while (temp->next != NULL)
    {
      cout << temp->data << "->";
      temp = temp->next;
    }
  cout << "NULL";
}

//search in a linked list
bool search(int n, node* head){
    node* temp = head;
    while(temp){
        if(temp->data == n)
        return true;
        temp = temp->next;
    }
    return false;
}

int main ()
{

  node *head = NULL;

  node *firstnode = new node (1);

  node *secondnode = new node (2);

  node *thirdnode = new node (3);

  node *lastnode = new node (4);
  
  head = firstnode;
  
  firstnode->next = secondnode;
  
  secondnode->next = thirdnode;
  
  thirdnode->next = lastnode;
  
  lastnode->next = NULL;

  display (head);
  
  cout<<endl<<search(5,head);

  return 0;
}

