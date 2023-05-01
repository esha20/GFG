//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//function to find the minimum value in the key array
	int find_mini(int v,vector<int> key,vector<bool>mst){
	    int mini = INT_MAX,u=0;
	    for(int i =0;i<v;i++){
	        if(key[i]<mini && mst[i] == false){
	            u = i;
	            mini = key[i];
	        }
	    }
	    return u;
	}
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        // code here
        vector<int> key(v,1e9);
        key[0]=0;
        
        vector<int> parent(v,-1);
        vector<bool>mst(v,false);
        
        for(int i=0;i<v;i++){
            int u = find_mini(v,key,mst);
            mst[u] = true;
            
            for(auto i : adj[u]){
                int v = i[0];
                int wt = i[1];
                
                if(mst[v] == false && key[v] > wt){
                    key[v] = wt;
                    parent[v] = u;
                }
            }
        }
        
        int ans =0;
        for(auto i : key){
            ans +=i;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends