//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        
        // Your code here
        map <char, char> s1;
        map <char, bool> s2;
        map <char, bool> s3;
        
        if(str1.size()!=str2.size())        return false;
        
        for(int i=0;i<str1.size();i++){
            s2[str1[i]] = false;
        }
        for (int i =0;i<str1.size();i++){
            if(s2[str1[i]]==false){
                s1[str1[i]] = str2[i];
                s2[str1[i]] = true;
            }
            else{
                if(s1[str1[i]] != str2[i]){
                    return false;
                }
            }
        }
        s1.clear();
        for(int i=0;i<str2.size();i++){
            s3[str2[i]] = false;
        }
        for (int i =0;i<str2.size();i++){
            if(s3[str2[i]]==false){
                s1[str2[i]] = str1[i];
                s3[str2[i]] = true;
            }
            else{
                if(s1[str2[i]] != str1[i]){
                    return false;
                }
            }
        }
        
        return true;
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends