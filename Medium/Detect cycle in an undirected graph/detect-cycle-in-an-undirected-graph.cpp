//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool bfs(unordered_map<int, bool> &visited, vector<int> adj[], int node){
        
        //map for parent DS
        unordered_map<int,int>parent;
        parent[node] = -1;     //the parent of the starting node will be -1
        
        //queue for bfs
        queue <int> q;
        
        visited[node]=true;    //visited the node
        q.push(node);          //push the visited node to the queue
        
        
        while(!q.empty()){
            int frontnode = q.front();
            q.pop();
            for(auto i : adj[frontnode]){
            if(!visited[i]){
                q.push(i);
                parent[i] = frontnode;
                visited[i]=1;
            }
            else{
                if(parent[frontnode]!= i){
                    return true;
                }
            }
        }
        }
        return false;
    }
    bool dfs(int node, int parent, unordered_map<int, bool> &visited, vector<int> adj[]){
        visited[node] = 1;
        for(auto i : adj[node]){
            if(!visited[i]){
                visited[i]=1;
                bool ans = dfs(i,node, visited, adj);
                if(ans) return true;
            }
            else{
                if(parent != i)     return true;
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        
        //visited DS
        unordered_map<int, bool> visited;
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                // bool ans = bfs(visited,adj, i);
                bool ans = dfs(i,-1,visited, adj);
                if(ans ==1 )
                    return true;
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