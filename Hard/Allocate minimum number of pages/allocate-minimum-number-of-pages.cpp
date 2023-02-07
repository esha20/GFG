//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool ispossiblesol(int n, int m, int arr[], int mid){
        int student =1;
        int pagesum = 0;
        
        for(int i=0;i<n;i++){
            if(pagesum + arr[i] <= mid){
                pagesum+=arr[i];
            }
            else{
                student++;
                if(student>m || arr[i] > mid)
                    return false;
                pagesum = arr[i];
            }
        }
        return true;
    }
    int findPages(int arr[], int n, int m) 
    {
        //code here
        int sum =0;
        
        for(int i=0;i<n;i++)    sum+=arr[i];
        
        int start=0,end= sum,ans=-1;
        int mid = start+(end-start)/2;
        
        if(n<m) return ans;
        
        while(start<=end){
            if(ispossiblesol(n,m,arr,mid))
            {
                ans = mid;
                end = mid -1;
            }
            else{
                start = mid +1;
            }
            mid = start +(end-start)/2;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends