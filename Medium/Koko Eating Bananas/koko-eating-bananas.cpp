//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool ispossible(int n, vector<int>& piles, int h,int mid){
        int timecnt=0;
        for(int i=0;i<n;i++){
            long long qt = piles[i]/mid;
            timecnt+=qt;
            
            if(piles[i] % mid != 0)     timecnt++;
            
            if(timecnt>h)       return false;
        }
        return (timecnt<=h);
    }
    int Solve(int n, vector<int>& piles, int h) {
        // Code here
        long long sum =0;
        for(int i=0;i<n;i++)        sum+=piles[i];
        
        long long start =0, end = sum, ans =-1;
        long long mid = start +(end -start)/2;
        
        while(start<=end){
            if(ispossible(n,piles,h,mid)){
                ans = mid;
                end = mid-1;
            }
            else
            {
                start= mid+1;
            }
            mid = start +(end -start)/2;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends