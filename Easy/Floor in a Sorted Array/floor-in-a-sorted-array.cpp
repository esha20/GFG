//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    
    //iterative approach
    // int findFloor(vector<long long> v, long long n, long long x){
        
    //     // Your code here
    //     long long start =0, end = n-1;
    //     long long mid = start+(end-start)/2;
    //     long long ans =-1;
    //     while(start<=end){
    //         if(v[mid]==x)
    //             return mid;
    //         else if(v[mid]>x)
    //         {
    //           // ans = mid;
    //             end = mid-1;
    //         }
    //         else{
    //             ans = mid;
    //             start = mid+1;
    //         }
    //       mid = start+(end-start)/2; 
    //     }
    //   return ans; 
    // }
    
    //recurrsive approach
    
    void solve(vector<long long> v, long long s,long long e, long long x, int &ans){
        if(s>e)
            return;
        
        int mid = s+(e-s)/2;
        
        if(v[mid]==x)
            ans = mid;
            
        else if(v[mid]>x)
            solve(v,s,mid-1,x,ans);
            
        else
        {
            ans = mid;
            solve(v,mid+1,e,x,ans);
        }
            
    }
    
    int findFloor(vector<long long> v, long long n, long long x){
        int ans = -1;
        solve(v, 0 , n-1,x, ans);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
	
	long long t;
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    long long x;
	    cin >> x;
	    
	    vector<long long> v;
	    
	    for(long long i = 0;i<n;i++){
	        long long temp;
	        cin >> temp;
	        v.push_back(temp);
	    }
	    Solution obj;
	    cout << obj.findFloor(v, n, x) << endl;
	   
	}
	
	return 0;
}
// } Driver Code Ends