//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
typedef long long ll;
class Solution
{
  public:
    bool isposs(int arr[], int n , int k, ll mid){
        int painter =1;
        ll board=0;
        
        for(int i=0;i<n;i++){
            if(board + arr[i] <= mid){
                board+=arr[i];
            }
            else{
                painter++;
                if(arr[i]>mid || painter > k){
                    return false;
                }
                board = arr[i];
            }
        }
        return true;
    }
    long long minTime(int arr[], int n, int k)
    {
        // if(n<k)    return 0; 
        ll sum =0;
        for(int i=0;i<n;i++)        sum+=arr[i];
        
        ll start =0, end = sum, ans =-1;
        ll mid = start+(end -start)/2;
        
        while(start <= end){
            if(isposs(arr, n, k ,mid)){
                ans = mid;
                end = mid-1;
            }
            else    start = mid+1;
            mid = start +(end-start)/2;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends