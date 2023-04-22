//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:

//METHOD 1 DFS  
    // bool dfs(int node,unordered_map <int, bool> &visited,vector<int> adj[],unordered_map <int, bool> &dfsvisited){
    //     visited[node]=1;
    //     dfsvisited[node]=1;
        
    //     for(auto i : adj[node]){
    //         if(!visited[i]){
    //             bool cycledetected = dfs(i,visited,adj,dfsvisited);
    //             if(cycledetected)   return true;
    //         }
    //         else{
    //             if(dfsvisited[i]){
    //                 return true;
    //             }
    //         }
    //     }
    //     dfsvisited[node] = false;           //mark the node 0 i ndfs visited when the dfs call is to die.
    //     return false;
    // }
    // // Function to detect cycle in a directed graph.
    // bool isCyclic(int V, vector<int> adj[]) {
    //     // code here
    //     unordered_map <int, bool> visited;
    //     unordered_map <int, bool> dfsvisited;
    //     for(int i=0;i<V;i++){
    //         if(!visited[i]){
    //             bool ans = dfs(i,visited,adj,dfsvisited);
    //             if(ans)     return true;
    //         }
    //     }
    //     return false;
    // }
    
    //METHOD 2 BFS USING KAHNS ALGORITHM
    bool isCyclic(int v, vector<int> adj[]) {
        
        int cnt=0;        //to count the number of elements we calculate in the topological sort 
        //if the elements are equal to the no of vertices then no cycle present else it has a cycle.
        
        vector<int> indegree(v);
        queue<int> q;
        
        //create the indegree vector
        for(int i=0;i<v;i++){
            for(auto j : adj[i]){
                indegree[j]++;
            }
        }
        
        //push the nodes with 0 indegree to the queue
        for(int i=0; i<v;i++){
            if(indegree[i] == 0 ){
                q.push(i);
            }
        }
        
        //bfs + decreasing the indegree of neighbours(using adj) of the ones to be popped from the queue + pushing the ones with 0 indegree to the queue.
        while(!q.empty()){
            int frontnode = q.front();
            q.pop();
            cnt++;
            for(auto i : adj[frontnode]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }
        
        if(cnt == v)        return false;
        
        else
            return true;
    }
    
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends