/*
  Bitonic Point
  EasyAccuracy: 58.67%Submissions: 102K+Points: 2
  
  
  Given an array arr of n elements that is first strictly increasing and then maybe strictly decreasing, find the maximum element in the array.
  Note: If the array is increasing then just print the last element will be the maximum value.
  
  Example 1:
  
  Input: 
  n = 9
  arr[] = {1,15,25,45,42,21,17,12,11}
  Output: 45
  Explanation: Maximum element is 45.
  Example 2:
  
  Input: 
  n = 5
  arr[] = {1, 45, 47, 50, 5}
  Output: 50
  Explanation: Maximum element is 50.
  Your Task:  
  You don't need to read input or print anything. Your task is to complete the function findMaximum() which takes the array arr[], and n as parameters and returns an integer denoting the answer.
  
  Expected Time Complexity: O(logn)
  Expected Auxiliary Space: O(1)
  
  Constraints:
  3 ≤ n ≤ 106
  1 ≤ arri ≤ 106
*/

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int findMaximum(int arr[], int n) {
	    // code here
	    sort(arr,arr+n);
	    return arr[n-1];
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
        auto ans = ob.findMaximum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
