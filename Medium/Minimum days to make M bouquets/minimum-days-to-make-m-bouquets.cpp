//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool ispossible(vector<int> &arr, int mid , int m , int k){
        int flwcnt =0, bqcnt =0;
        for(int i=0;i<arr.size();i++){
            if(arr[i] <= mid ){
                flwcnt ++;
                if(flwcnt == k){
                    bqcnt ++;
                    flwcnt =0;
                    if(bqcnt == m)      return true;
                }
            }
            else
            {
                flwcnt =0;
            }
        }
        return false;
    }
    int solve(int m, int k, vector<int> &arr){
      // Code here
      long long pro = m*k;
      
      if(pro > arr.size())      return -1;
      
      int start =0, end = INT_MIN,ans=INT_MAX;
      
      for(int i=0;i<arr.size();i++)      end = max(end,arr[i]);
      
      int mid = start +(end-start)/2;
      
      while(start<=end){
          if(ispossible(arr,mid,m, k)){
              ans = min(mid,ans);
              end = mid -1;
          }
          else
            start = mid +1;
            
        mid = start +(end-start)/2;
      }
      return ans==INT_MAX?-1:ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, k;
    cin >> m >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = s.length();
    int num = 0;
    bool f = 0;
    vector<int> bloomDay;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ' ')
      {
        if (!f)
          continue;
        bloomDay.push_back(num);
        num = 0;
        f = 0;
      }
      else
      {
        num = (num * 10) + (s[i] - '0');
        f = 1;
      }
    }
    if (f)
    {
      bloomDay.push_back(num);
    }
    Solution obj;
    cout<<obj.solve(m, k, bloomDay)<<endl;
    }
    return 0;
}
// } Driver Code Ends