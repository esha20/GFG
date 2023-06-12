//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    bool dfs(vector<bool> &vis,vector<int> adj[], int node,int p){
        vis[node]=1;
        
        for(auto i :adj[node]){
            if(!vis[i]){
                bool ans = dfs(vis,adj,i,node);
                if(ans)     return true;
            }
            else{
                if(p!=i)     return true;
            }
        }
        return false;
    }
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool>vis(V,0);
        vector<int> parent(V,-1);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                bool ans = dfs(vis,adj,i,-1);
                if(ans)     return true;
            }
        }
        return false;
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
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends