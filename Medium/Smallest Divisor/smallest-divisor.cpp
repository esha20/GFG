//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isposs(vector<int>& nums, int mid , int k){
        int newans = 0;
        for(int i=0;i<nums.size();i++){
            //nums[i] = float(nums[i]);
            newans += ceil(float(nums[i])/mid);
            if(newans > k )     return false;
        }
        // ans = min(ans, newans);
        return true;
    }
    int smallestDivisor(vector<int>& nums, int K) {
        int maxi = INT_MIN;
        
        for(int i=0;i<nums.size();i++){
            if(maxi<nums[i])     maxi = nums[i];
        }
        maxi = max(maxi, K);
        int start = 1, end = maxi, ans = INT_MAX;
        int mid = start +(end-start)/2;
        
        while(start<=end){
            if(isposs(nums,mid, K)){
                ans = mid;
                end = mid-1;
            }
            else
                start= mid+1;
                
            mid = start+(end-start)/2;
        }   
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends