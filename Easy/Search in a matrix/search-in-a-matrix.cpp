//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int matSearch (vector <vector <int>> &mat, int n, int m, int x)
	{
	    // your code here
	    if(n > m)
	    {
	    for(int i=0;i<m;i++){
	        
	    int start=0,end=n-1;
	    int mid = start +(end-start)/2;
	    
	    while(start<=end){
	        if(mat[mid][i] == x)
	            return 1;
	        else if(mat[mid][i] < x){
	            start= mid+1;
	        }
	        else if(mat[mid][i] > x){
	            end = mid-1;
	        }
	        mid = start + (end-start)/2;
	    }
	    
	    }
	    }
	    else{
	        
	    for(int i=0;i<n;i++){
	        int nstart = 0,nend = m-1;
	        int nmid = nstart +(nend-nstart)/2;
	        
	        while(nstart<=nend){
	            if(mat[i][nmid]==x)
	                return 1;
	            else if(mat[i][nmid] > x)
	                nend = nmid-1;
	            else if(mat[i][nmid] < x)
	                nstart= nmid+1;
	        nmid = nstart+(nend-nstart)/2;
	        }
	    }
	    
	}
	    return 0;
	}
};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                cin >> arr[i][j];
                
        int x; cin >> x;
        Solution ob;
        cout << ob.matSearch (arr, n, m, x) << endl;
    }
}
// } Driver Code Ends