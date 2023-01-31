//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    
    // int searchInsertK(vector<int>Arr, int N, int k)
    // {
    //     // code here
    //     int start =0, end = N-1;
        
    //     int mid = start -(end+start)/2;
        
    //     while(start<=end){
    //         if(Arr[mid]==k)
    //             {
    //                 return mid;
    //             }
    //         else if(Arr[mid]>k)
    //             end = mid -1;
    //         else if(Arr[mid]<k)
    //             start=mid+1;
                
    //         mid = start+(end-start)/2;
    //     }
    //     return start;
    // }
    
    
    int searchInsertK(vector<int>Arr, int N, int k){
        int ans =-1, start =0, end = N-1;
        int mid = start +(end-start)/2;
        
        while(start<=end){
            if(Arr[mid]==k)
                return mid;
            else if(Arr[mid]>k){
                ans = mid;
                end = mid-1;
            }
            else
                start =mid+1;
                
            mid = start+(end-start)/2;
        }
        return (ans=-1)?start:ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<int>Arr(N);
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.searchInsertK(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends