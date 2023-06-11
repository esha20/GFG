//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    // vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    //     // Code here
    //     //zero indexing graph;
    //     int visited[V]={0}; //created a visited array of nodes.
    //     visited[0]=1;   //mark the starting node
        
    //     queue<int> q;       //maintaining the queue
    //     q.push(0);          //pushing the starting node into the queue
        
    //     vector<int> bfs;    //to store the result popped out of the queue
    //     while(!q.empty()){
    //         int node = q.front();
    //         q.pop();
    //         bfs.push_back(node);
            
    //         for(auto x : adj[node]){
    //             //i.e. for every node in the adjacency list of this node, push it into the queue if not visited
    //             if(!visited[x]){
    //                 q.push(x);
    //                 visited[x]=1;   //once pushed into the queue , the node should be marked visited.
    //             }
    //         }
    //     }
    //     return bfs;
    // }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        queue<int> q;
        q.push(0);
        
        vector<bool>vis(V,0);
        vis[0]=1;
        
        vector<int> ans;
        
        while(!q.empty()){
            
            int topnode = q.front();
            q.pop();
            ans.push_back(topnode);
            
            for(auto i : adj[topnode]){
                if(!vis[i]){
                    vis[i]=1;
                    q.push(i);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends