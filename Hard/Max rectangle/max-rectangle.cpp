//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  private:
//   int max(int a, int b){
//       if(a>b){
//           return a;
//       }
//       return b;
//   }
    vector<int> nextSmallerElement(int *arr , int n){
      stack<int> s;
      s.push(-1);
      vector<int> ans(n);
      for(int i=n-1;i>=0;i--){
          while(s.top() != -1 && arr [s.top()]>= arr[i]){
              s.pop();
          }
          ans [i] = s.top();
          s.push(i);
      }
      return ans;
  }
    vector<int> prevSmallerElement(int *arr , int n){
       stack<int> s;
       s.push(-1);
       vector<int> ans(n);
       for(int i=0;i<n;i++){
           while(s.top()!=-1 && arr[s.top()]>= arr[i]){
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
  }
    int maxAreaHistogram(int *arr , int n){
      
      vector<int> next (n);
      next = nextSmallerElement(arr, n);
      
      vector<int> prev(n);
      prev = prevSmallerElement(arr, n);
      
      int area = INT_MIN;
      
      for(int i=0;i<n;i++){
          int l = arr[i];
          if(next[i]==-1){
              next[i]=n;
          }
          int b = next[i]-prev[i]-1;
          
          int newArea = l*b;
          area = max(area, newArea);
      }
      return area;
  }
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        //compute area of the first row
        int maxA = maxAreaHistogram(M[0], m);
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                //row Update : by adding previous row values
                //only done when the curr ele is not zero 
                if(M[i][j] !=0){
                M[i][j] = M[i][j] + M[i-1][j];
                }
                //agar zero hai matlb uss bar ko ham count nahi kar sakte.
                else{
                    M[i][j]=0;
                }
            }
            maxA = max(maxA, maxAreaHistogram(M[i], m));
        }
        return maxA;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends