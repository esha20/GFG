//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
void swap(int& a, int &b){
    int temp = a;
    a=b;
    b=temp;
}
	void pushZerosToEnd(int arr[], int n) {
	    // code here
	    int i=0,j=0;
	   // bool cnt=0;
	    while(i<n){
	        if(arr[i]==0){
	           //cnt = true;
	           i++;
	        }
	        else{
	           // arr[j]=arr[i];
	           swap(arr[j],arr[i]);
	            j++;i++;
	        }
	    }
	}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.pushZerosToEnd(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends