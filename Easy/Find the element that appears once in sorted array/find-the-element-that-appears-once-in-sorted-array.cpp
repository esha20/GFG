//{ Driver Code Starts
// Driver code

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
  public:
    int findOnce(int arr[], int n)
    {
        //code here.
        int start =0, end = n-1;
        int mid = start+(end-start)/2;
        
        if(n==1)
            return arr[0];
            
        else if(arr[end] != arr[end-1]){
            return arr[end];
        }
        while(start<=end){
            if(arr[mid]!=arr[mid-1] && arr[mid] != arr[mid+1])
                return arr[mid];
            else if(((mid % 2 == 0) && (arr[mid+1]==arr[mid])) || ((mid%2 != 0) && (arr[mid-1] == arr[mid])))
                start = mid +1;
            // else if(((mid%2 != 0) && (arr[mid-1] != arr[mid])) || ((mid % 2 == 0) && (arr[mid+1]==arr[mid])))
            else
                end = mid -1;
            
            mid = start +(end-start)/2;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
}
// } Driver Code Ends