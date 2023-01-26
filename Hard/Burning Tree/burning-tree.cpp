//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    //function for step 1
    Node* createparentmapping(Node* root, int target, map<Node*,Node*> &nodetoparent){
        //passed the map by refernce because we want to store the values such that we can use it in the next burntree functiona s well
        
        Node* targetnode = NULL;
        
        //we will here do the level order traversal for step 1. i.e. to traverse the tree.
        queue<Node*> q;
        q.push(root);
        
        //root ka prent nahi hai toh usko map mei null likh do parent.
        nodetoparent[root]=NULL;
        
        while(!q.empty()){
            
            Node* frontnode = q.front();
            q.pop();
            
            if(frontnode->data==target)
                targetnode= frontnode;
            
            //frontnode->left ka left hai toh check kro aur then update that frontnode->left ka parent frontnode hai
            if(frontnode->left){
                q.push(frontnode->left);
                nodetoparent[frontnode->left]=frontnode;
            }
            
            //similarly for right
            if(frontnode->right){
                q.push(frontnode->right);
                nodetoparent[frontnode->right]=frontnode;
            }
        }
        return targetnode;
    }
    int burntree(Node* targetnode, map<Node*, Node*> &nodetoparent){
        map<Node*, bool> visited;
        queue<Node*> q;
        
        q.push(targetnode);
        visited[targetnode]=true;
        
        int waqt =0;
        
        while(!q.empty()){
            
            bool flag = 0;  //set to false
            int size = q.size();
            for(int i=0; i<size;i++){
                
                Node* frontnode = q.front();
                q.pop();
                
                //left child hai ki nahi check
                if(frontnode->left && visited[frontnode->left]==false)
                {
                    flag = true;
                    q.push(frontnode->left);
                    visited [frontnode->left] = true;
                }
                
                //same for right child
                if(frontnode->right && visited[frontnode->right]==false){
                    flag = true;
                    visited[frontnode->right] = true;
                    q.push(frontnode->right);
                }
                
                //check for parent from the map of nodetoparent
                if(visited[nodetoparent[frontnode]]==false && nodetoparent[frontnode]){
                    flag = true;
                    visited[nodetoparent[frontnode]]=true;
                    q.push(nodetoparent[frontnode]);
                }
            }
            
            if(flag == 1)
                waqt++;
        }
        return waqt;
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        //step 1: create node to parent  mapping
        //step 2: find target node
        //step 3: burn the tree in min time
        
        //step 1
        map<Node* , Node*> nodetoparent;
        
        //step 2
        //function for finding the target node as well does the mapping at the same time.
        //returns the target node ans then we store it in the targetnode
        Node* targetnode = createparentmapping(root, target, nodetoparent);
        
        //step 3
        return burntree(targetnode, nodetoparent);
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends