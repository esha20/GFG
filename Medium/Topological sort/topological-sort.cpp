//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
// 	public:
// 	void dfs(int node,vector<int> adj[],unordered_map <int, bool> &visited,stack<int> &s){
// 	    visited[node]=1;
// 	    for(auto i : adj[node]){
// 	        if(!visited[i]){
// 	            dfs(i,adj,visited,s);
// 	        }
// 	    }
// 	    s.push(node);
// 	}
// 	//Function to return list containing vertices in Topological order. 
// 	vector<int> topoSort(int V, vector<int> adj[]) 
// 	{
// 	    // code here
// 	    stack <int> s;
// 	    unordered_map <int, bool> visited;
	    
// 	    for(int i=0;i<V;i++){
// 	        if(!visited[i]){
// 	            dfs(i,adj,visited,s);
// 	        }
// 	    }
// 	    vector<int> ans;
// 	    while(!s.empty()){
// 	       // int x = s.pop();
// 	        ans.push_back(s.top());
// 	        s.pop();
// 	    }
// 	    return ans;
// 	}

public:

vector<int> topoSort(int v, vector<int> adj[]) 
{
    vector<int> ans;
    queue<int> q;
    vector<int> indegree(v);

    //indegree vector create kar lo
    for(int i=0;i<v;i++){
        for(auto j : adj[i]){
            indegree[j]++;
        }
    }
    
    //0 indegree walo ko queue mei add kar do.
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    
    //bfs chala do bakiyo k liye
    while(!q.empty()){
        
        int frontnode = q.front();
        q.pop();
        
        for(auto i: adj[frontnode]){
            indegree[i]--;
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        ans.push_back(frontnode);
    }
    return ans;
}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends