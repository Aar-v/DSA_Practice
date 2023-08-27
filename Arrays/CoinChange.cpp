/*
  Coin Change
  MediumAccuracy: 43.1%Submissions: 234K+Points: 4
  15K students have upskilled themselves with our courses over the summer. Don't get left behind! Save extra 30% by enrolling today
  
  Given an integer array coins[ ] of size N representing different denominations of currency and an integer sum, find the number of ways you can make sum by using different combinations from coins[ ].  
  Note: Assume that you have an infinite supply of each type of coin. And you can use any coin as many times as you want.
  
  Example 1:
  
  Input:
  N = 3, sum = 4
  coins = {1,2,3}
  Output: 4
  Explanation: Four Possible ways are: {1,1,1,1},{1,1,2},{2,2},{1,3}.
  Example 2:
  
  Input:
  N = 4, Sum = 10
  coins = {2,5,3,6}
  Output: 5
  Explanation: Five Possible ways are: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}.
  Your Task:
  You don't need to read input or print anything. Your task is to complete the function count() which accepts an array coins its size N and sum as input parameters and returns the number of ways to make change for given sum of money. 
  
  Expected Time Complexity: O(sum*N)
  Expected Auxiliary Space: O(sum)
  
  Constraints:
  1 <= sum, N, coins[i] <= 103
*/

// Solution.
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int n, int sum) {
    // 2d dp array where n is the number of coin
    // denominations and sum is the target sum
    vector<vector<long long int> > dp(n + 1, vector<long long int>(sum + 1, 0));
 
    // Represents the base case where the target sum is 0,
    // and there is only one way to make change: by not
    // selecting any coin
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
 
            // Add the number of ways to make change without
            // using the current coin,
            dp[i][j] += dp[i - 1][j];
 
            if ((j - coins[i - 1]) >= 0) {
 
                // Add the number of ways to make change
                // using the current coin
                dp[i][j] += dp[i][j - coins[i - 1]];
            }
        }
    }
    return dp[n][sum];
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends
