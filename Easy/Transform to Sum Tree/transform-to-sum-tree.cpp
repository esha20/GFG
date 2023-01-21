//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}
void inorder(Node * node)
{
    if(node==NULL)
        return;
    
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}


// } Driver Code Ends
//User function template for C++

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
    pair<bool,pair<int, int>> fasttosum(Node* &root){
        if(root==NULL){
            pair<bool,  pair<int, int>> p = make_pair(true,make_pair(0,0));
            return p;
        }
        if(root->left ==NULL && root->right==NULL){
            pair<bool,pair<int, int>> p = make_pair(true, make_pair(root->data,0));
            root->data = 0;
            return p;
        }
        pair<bool,pair<int, int> > left = fasttosum(root->left);
        pair<bool, pair<int, int>> right = fasttosum (root->right);
        
        //checking if the subtrees are sum tree or not
        bool leftans = left.first;
        bool rightans = right.first;
        
        //to store the answer
        pair<bool, pair<int, int>> ans;
        
        //if both the subtrees are sum tree then the current root is in sum tree if changed the value.
        if(leftans && rightans){
            ans.first = true;
        }
        //store the previous data of the node
        ans.second.first = root->data;
        
        //add the previous as well as the recent data of the node to make the final node sum
        ans.second.second = left.second.first + right.second.first+left.second.second+right.second.second;
        
        //set the data of the root to be the current value.
        root->data = ans.second.second;

        return ans;
        
    }
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    void toSumTree(Node *node)
    {
        // Your code here
        fasttosum(node);
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        Solution ob;
        ob.toSumTree(root);
        inorder(root);
        cout<<endl;
    }
    return 1;
}
// } Driver Code Ends