#include<iostream>

using namespace std;

int main(){
    int capacity = 10;
    int items = 4;
    int price[items + 1] = {0, 3, 7, 2, 9};
    int wt[items + 1] = {0, 2, 2, 4, 5};
    int dp[items + 1][capacity + 1];
    
    for(int i = 0; i <= items; i++){
        for(int j = 0; j <= capacity; j++){
            if(i == 0 || j == 0){
                //There's nothing to add to Knapsack
                dp[i][j] = 0;
            }
            else if(wt[i] <= j){
                //Choose previously maximum or value of current item + value of remaining weight
                dp[i][j] = max(dp[i - 1][j], price[i] + dp[i - 1][j - wt[i]]);
            }
            else{
                //Add previously added item to knapsack
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
	

    cout << "Maximum Profit Earned: " << dp[items][capacity] << "\n";
    return 0;
}

/*
0/1 Knapsack :
Time Complexity: O(N*W). 
where ‘N’ is the number of weight element and ‘W’ is capacity. As for every weight element we traverse through all weight capacities 1<=w<=W.
Auxiliary Space: O(N*W). 
The use of 2-D array of size ‘N*W’.
*/

// A dynamic programming based 
// solution for 0-1 Knapsack problem 
#include <bits/stdc++.h> 
using namespace std; 

// A utility function that returns 
// maximum of two integers 
int max(int a, int b) { return (a > b) ? a : b; } 

// Returns the maximum value that 
// can be put in a knapsack of capacity W 
int knapSack(int W, int wt[], int val[], int n) 
{ 
	int i, w; 
	vector<vector<int> > K(n + 1, vector<int>(W + 1)); 

	// Build table K[][] in bottom up manner 
	for (i = 0; i <= n; i++) { 
		for (w = 0; w <= W; w++) { 
			if (i == 0 || w == 0) 
				K[i][w] = 0; 
			else if (wt[i - 1] <= w) 
				K[i][w] = max(val[i - 1] 
								+ K[i - 1][w - wt[i - 1]], 
							K[i - 1][w]); 
			else
				K[i][w] = K[i - 1][w]; 
		} 
	} 
	return K[n][W]; 
} 

// Driver Code 
int main() 
{ 
	int profit[] = { 60, 100, 120 }; 
	int weight[] = { 10, 20, 30 }; 
	int W = 50; 
	int n = sizeof(profit) / sizeof(profit[0]); 

	cout << knapSack(W, weight, profit, n); 

	return 0; 
} 

// This code is contributed by Debojyoti Mandal


