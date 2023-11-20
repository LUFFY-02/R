#include<bits/stdc++.h>
using namespace std;

bool isSafe(int **arr, int x, int y, int n){
    for(int row=0;row<x;row++){
        if(arr[row][y]==1){
            return false;
        }
    }

    int row =x;
    int col =y;
    while(row>=0 && col>=0){
        if(arr[row][col]==1){
            return false;
        }
        row--;
        col--;
    }

    row =x;
    col =y;
    while(row>=0 && col<n){
        if(arr[row][col]==1){
            return false;
        }
        row--;
        col++;
    }

    return true;
}

void printBoard(int **arr, int n){
	for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
			if(arr[i][j] == 1) cout << "[Q]";
			else cout << "[]";
		}
        cout << endl;
	}
	cout << endl;
	cout << endl;
}


void nQueen(int** arr, int x, int n){
    if(x == n){
        printBoard(arr, n);
		return;
    }

    for(int col=0;col<n;col++){
        if(isSafe(arr,x,col,n)){
            arr[x][col]=1;
            nQueen(arr,x+1,n);
            arr[x][col]=0;
        }
    }
}


int main(){
    int n;
    cin >> n;
    
    int **arr = new int*[n];    
    for(int i=0;i<n;i++){
        arr[i] = new int[n];
        for(int j=0;j<n;j++){
            arr[i][j]=0;
        }
    }
	
	nQueen(arr, 0, n);
	
	cout << "--------All possible solutions--------";
	
    return 0;
}

/*
Time Complexity: O(N!)
Auxiliary Space: O(N^2)
*/

__________________________________

/* C/C++ program to solve N Queen Problem using
backtracking */
#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > result;
int ROW,COL;
/* A utility function to check if a queen can
be placed on board[row][col]. Note that this
function is called when "col" queens are
already placed in columns from 0 to col -1.
So we need to check only left side for
attacking queens */
bool isSafe(vector<vector<int> > board, 
			int row, int col)
{
	int i, j;
	int N = board.size();

	/* Check this row on left side */
	for (i = 0; i < col; i++)
		if (board[row][i])
			return false;

	/* Check upper diagonal on left side */
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return false;

	/* Check lower diagonal on left side */
	for (i = row, j = col; j >= 0 && i < N; i++, j--)
		if (board[i][j])
			return false;

	return true;
}

/* A recursive utility function to solve N
Queen problem */
bool solveNQUtil(vector<vector<int> >& board, int col)
{
	/* base case: If all queens are placed
	then return true */
	int N = board.size();
	if (col == N) {
		vector<int> v;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (board[i][j] == 1)
					v.push_back(j + 1);
			}
		}
		result.push_back(v);
		return true;
	}
    if(col + 1 == COL){
        return solveNQUtil(board,col+1);
    }
	/* Consider this column and try placing
	this queen in all rows one by one */
	bool res = false;
	for (int i = 0; i < N; i++) {
		/* Check if queen can be placed on
		board[i][col] */
		if (isSafe(board, i, col)) {
			/* Place this queen in board[i][col] */
			board[i][col] = 1;

			// Make result true if any placement
			// is possible
			res = solveNQUtil(board, col + 1) || res;

			/* If placing queen in board[i][col]
			doesn't lead to a solution, then
			remove queen from board[i][col] */
			board[i][col] = 0; // BACKTRACK
		}
	}

	/* If queen can not be place in any row in
		this column col then return false */
	return res;
}

/* This function solves the N Queen problem using
Backtracking. It mainly uses solveNQUtil() to
solve the problem. It returns false if queens
cannot be placed, otherwise return true and
prints placement of queens in the form of 1s.
Please note that there may be more than one
solutions, this function prints one of the
feasible solutions.*/

vector<vector<int> > nQueen(int n)
{
	result.clear();
	vector<vector<int> > board(n, vector<int>(n, 0));
    if(ROW<=8 && ROW>0 && COL<=8 && COL>0) board[ROW-1][COL-1]=1;
	if (solveNQUtil(board, 0) == false) {
		return {};
	}

	// sort(result.begin(), result.end());
	return result;
}

// Driver Code
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n = 8;
    cin>>ROW>>COL;
	vector<vector<int> > v = nQueen(n);
	for (auto ar : v) {
        if(ar[0]!=2) continue;
		cout << "[";
		for (auto it : ar)
			cout << it << " ";
		cout << "]"<<endl;
	}

	return 0;
}
