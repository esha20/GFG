//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int n)
    {
        // your code here
        string ans = arr[0];
        for(int i=1 ; i<n ; i++)
        {
            if(ans.length() > arr[i].length())
            {
                ans.erase(arr[i].length());
            }
            
            for(int j=0 ; j<arr[i].length() ; j++)
            {
                if(ans[j] != arr[i][j])
                {
                    ans.erase(j);
                    break;
                } 
            }
        }
        if(ans.size() == 0) return "-1";
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends