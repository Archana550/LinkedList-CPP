/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

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

//insert nodes in ll
void
insertAtLast (Node ** head, int val)
{
  Node *newnode = new Node (val);
  if (*head == NULL)
    {
      *head = newnode;
      return;
    }

  Node *temp = *head;
  while (temp->next != NULL)
    {
      temp = temp->next;
    }
  temp->next = newnode;
  return;
}


//delete any Node
void
deleteANode (int key, Node ** head)
{

  Node *prev, *temp = *head;

  if (temp == NULL)
    return;

  //head node
  if (temp != NULL && temp->data == key)
    {

      *head = temp->next;
      free (temp);
      return;
    }

  //other nodes
  while (temp->data != key)
    {
      prev = temp;
      temp = temp->next;
    }

  prev->next = temp->next;
  free (temp);
  return;

}

//delete entire list
void
deleteEntireList (Node ** head)
{
  Node *next, *temp = *head;
  while (temp != NULL)
    {

      next = temp->next;
      free (temp);
      temp = next;
    }
  *head = NULL;
}


//reverse entire list
void
reverseList (Node** head)
{

  Node *prev, *curr, *next;
  prev = next = NULL;

  curr = *head;
 
  while (curr != NULL)
    {
     next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
     
    }

  *head = prev;

}

//display linked list
void
display (Node * head)
{
  Node *temp = head;

  if (head == NULL)
    cout << "List is Empty";
  while (temp)
    {
      cout << temp->data << "->";
      temp = temp->next;
    }
  cout << "NULL";
}



int
main ()
{

  Node *head = NULL;


  insertAtLast (&head, 1);
  insertAtLast (&head, 2);
  insertAtLast (&head, 3);
  insertAtLast (&head, 4);
  insertAtLast (&head, 5);

  display (head);


  //deleteANode (5, &head);
  //display (head);

  //deleteEntireList(&head);

  reverseList (&head);
  display (head);
  return 0;
}

