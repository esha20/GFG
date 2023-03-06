//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int arr[],long long int n, long long int k) {
    vector<long long> vect;
    queue <long long> q;
    int i=0, count =0;
    for(int j=0; j<n; j++){
        if(arr[j]<0 )      q.push(j);
        if(count < k){
            count++;
        }
        if(count == k){
            if(q.empty())   vect.push_back(0);
            else if(i <= q.front())    {
                vect.push_back(arr[q.front()]);
                if(i==q.front())    q.pop();
            }
            i++;
            count--;
        }
    }
    return vect;
 }