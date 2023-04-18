//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string maxOdd(string s) {
        // your code here
        string ans;
        int index=-1;
        for(int i=s.length();i>=0;i--){
            if((s[i]%2)!=0){
                index = i;
                break;
            }
        }
        if(index!=-1){
            for(int i=0;i<=index;i++){
                ans += s[i];
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;

        cout << ob.maxOdd(s) << endl;
    }
}

// } Driver Code Ends