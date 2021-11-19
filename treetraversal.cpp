/******************************************************************************

Iterative traversal of inorder and preorder is same.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
  int data;
  struct Node *left, *right;

    Node (int val)
  {
    data = val;
    left = right = NULL;
  }
};

void preorder (Node * root)
{
  if (root == NULL)
    return;

  cout << root->data << " ";
  preorder (root->left);
  preorder (root->right);

  return;
}

void inorder (Node * root)
{
  if (root == NULL)
    return;


  inorder (root->left);
  cout << root->data << " ";
  inorder (root->right);

  return;
}

void postorder (Node * root)
{
  if (root == NULL)
    return;


  preorder (root->left);

  preorder (root->right);

  cout << root->data << " ";

  return;
}

vector < vector < int >>LevelOrder (Node * root)
{

  vector < vector < int >>ans;
  if (root == NULL)
    return ans;

  queue < Node * >q;
  q.push (root);

  while (!q.empty ())
    {
      int size = q.size ();
      vector < int >level;

      for (int i = 0; i < size; i++)
	{
	  Node *temp = q.front ();
	  q.pop ();

	  if (temp->left != NULL)
	    q.push (temp->left);
	  if (temp->right != NULL)
	    q.push (temp->right);

	  level.push_back (temp->data);

	}
      ans.push_back (level);
    }
  return ans;
}


vector <vector <int>> SpiralOrder(Node *root){
    vector<vector<int>> spiral;
    if(root == NULL){
        return spiral;
    }
    
    queue<Node*> q;
    q.push(root);
    bool leftToRight = true;
    
    while(!q.empty()){
        int size = q.size();
        vector <int> row(size);
        
        for(int i=0;i<size;i++){
          Node* node = q.front();
            q.pop();
            
            //find position to fill nodes value;
            int index = (leftToRight?i:(size-1-i));
            row[index] = node->data;
            
            if(node->left){
                q.push(node->left);
               
            }
            
            if(node->right){
                 q.push(node->right);
            }
        }
        //after this level'
            leftToRight = !leftToRight;
            spiral.push_back(row);
        
    }
    return spiral;
}

vector<int> nonRecInorder(Node* root){
    stack <Node*> st;
    Node* node = root;
    vector<int> inorder;
    
    if(root==NULL)
    return inorder;
    
    while(true){
        if(node!=NULL){
            st.push(node);
            node= node->left;
        }else{
          if(st.empty()==true)break;
            node = st.top();
            st.pop();
            inorder.push_back(node->data);
            node= node->right;
        }
    }
    return inorder;
}

int main ()
{
  struct Node *root = new Node (1);
  new Node (1);

  root->left = new Node (2);
  root->right = new Node (3);

  root->left->right = new Node (5);
  root->left->left = new Node (4);


  root->right->right = new Node (7);
  root->right->left = new Node (6);

//Traversals
  cout << "Preorder: ";
  preorder (root);
  cout << endl;
  cout << "Inorder: ";
  inorder (root);
  cout << endl;
  
   vector<int> inorder;
   inorder= nonRecInorder(root);
    for (int j = 0; j < inorder.size (); j++)
	{
	  cout << inorder[j] << " ";
	}
   cout<<endl;
  cout << "Postorder: ";
  postorder (root);
  cout << endl;

  vector < vector < int >>levelorder = LevelOrder (root);

  cout << "Level Order:" << endl;
  for (int i = 0; i < levelorder.size (); i++)
    {
      for (int j = 0; j < levelorder[i].size (); j++)
	{
	  cout << levelorder[i][j] << " ";
	}
      cout << endl;
    }
    
    vector < vector < int >>spiralorder = SpiralOrder (root);

  cout <<endl<< "Spiral Order:" << endl;
  for (int i = 0; i < spiralorder.size (); i++)
    {
      for (int j = 0; j < spiralorder[i].size (); j++)
	{
	  cout << spiralorder[i][j] << " ";
	}
      cout << endl;
    } 

  return 0;
}
