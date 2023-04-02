//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
     //function to find the dfs recursively
     void finddfs(int node, int *visited,vector<int> &dfs, vector<int> adj[] ){
         visited[node]=1;   //mark the node as visited in the array
         dfs.push_back(node);   //push that node into the solution array
         
         //traverse for all the nodes in the adjacency list of a particular node.
         for(auto i : adj[node]){
             if(!visited[i]){       //if the node is not visited yet, run the dfs algo on that node again.
                 finddfs(i,visited,dfs,adj);
             }
         }
     }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int visited[V] = {0};
        //int start =0;
        vector <int> dfs;
        finddfs(0,visited,dfs,adj);
        return dfs;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends