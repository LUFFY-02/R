A binomial coefficient C(n, k) can be defined as the coefficient of x^k in the expansion of (1 + x)^n.

A binomial coefficient C(n, k) also gives the number of ways, disregarding order, that k objects can be chosen from among n objects more formally, the number of k-element subsets (or k-combinations) of a n-element set.

The Problem 
Write a function that takes two parameters n and k and returns the value of Binomial Coefficient C(n, k). For example, your function should return 6 for n = 4 and k = 2, and it should return 10 for n = 5 and k = 2.

1) Optimal Substructure 
The value of C(n, k) can be recursively calculated using the following standard formula for Binomial Coefficients.  

   C(n, k) = C(n-1, k-1) + C(n-1, k)
   C(n, 0) = C(n, n) = 1

Following is a simple recursive implementation that simply follows the recursive structure mentioned above.  

// A naive recursive C++ implementation
#include <bits/stdc++.h>
using namespace std;

// Returns value of Binomial Coefficient C(n, k)
int binomialCoeff(int n, int k)
{
	// Base Cases
	if (k > n)
		return 0;
	if (k == 0 || k == n)
		return 1;

	// Recur
	return binomialCoeff(n - 1, k - 1)
		+ binomialCoeff(n - 1, k);
}

/* Driver code*/
int main()
{
	int n = 5, k = 2;
	cout << "Value of C(" << n << ", " << k << ") is "
		<< binomialCoeff(n, k);
	return 0;
}

// This is code is contributed by rathbhupendra

Time Complexity: O(n*max(k,n-k)) 

Auxiliary Space: O(n*max(k,n-k))

2) Overlapping Subproblems 
It should be noted that the above function computes the same subproblems again and again. See the following recursion tree for n = 5 and k = 2. The function C(3, 1) is called two times. For large values of n, there will be many common subproblems. 



// A Dynamic Programming based solution that uses
// table C[][] to calculate the Binomial Coefficient
#include <bits/stdc++.h>
using namespace std;

// Prototype of a utility function that
// returns minimum of two integers
int min(int a, int b);

// Returns value of Binomial Coefficient C(n, k)
int binomialCoeff(int n, int k)
{
	int C[n + 1][k + 1];
	int i, j;

	// Calculate value of Binomial Coefficient
	// in bottom up manner
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= min(i, k); j++) {
			// Base Cases
			if (j == 0 || j == i)
				C[i][j] = 1;

			// Calculate value using previously
			// stored values
			else
				C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}

	return C[n][k];
}

// A utility function to return
// minimum of two integers
int min(int a, int b) { return (a < b) ? a : b; }

// Driver Code
int main()
{
	int n = 5, k = 2;
	cout << "Value of C[" << n << "][" << k << "] is "
		<< binomialCoeff(n, k);
}

// This code is contributed by Shivi_Aggarwal


Time Complexity: O(n*k) 
Auxiliary Space: O(n*k)












