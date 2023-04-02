//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(vector<int> adjls[], int node, int visited[]){
        visited[node] = 1;
        for(auto i : adjls[node]){
            if(!visited[i]){
                dfs(adjls, i, visited);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        int visited[V] = {0};
        vector<int> adjls[V];
        
        //change the adjacency matrix to list for convenience
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(i!=j && adj[i][j]==1){
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }
            }
        }
        int count =0;
        for(int i=0;i<V;i++){
            if(visited[i]!=1){
                count++;
                dfs(adjls,i,visited);
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends