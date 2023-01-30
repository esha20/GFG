//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    // sort(arr.begin(), arr.end());
    sort(arr, arr+n);
    int start =0, end = n-1, ans1=-1, ans2=-1;
    int mid = start+(end-start)/2;
    
    while(start<=end){
        if(arr[mid]==x)
            {
                ans1=arr[mid];
                break;
            }
        else if(arr[mid]>x){
            end=mid-1;
        }
        else{
            ans1=arr[mid];
            start=mid+1;
        }
        mid = start+(end-start)/2;
    }
    
    start =0,end=n-1;
    mid=start+(end-start)/2;
    
    while(start<=end){
        if(arr[mid]==x)
            {
                ans2=arr[mid];
                break;
            }
        else if(arr[mid]>x){
            ans2=arr[mid];
            end=mid-1;
        }
        else{
            start=mid+1;
        }
        mid = start+(end-start)/2;
    }
    
    pair<int, int>p;
    p.first = ans1;
    p.second = ans2;
    
    return p;
}