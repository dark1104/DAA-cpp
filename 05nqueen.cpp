#include <bits/stdc++.h>
using namespace std;


void solve(int col, vector<string>&board, vector<vector<string>> &ans,vector<int> &leftRow, vector<int> &upperDiagnonal, vector<int> &lowerDiagonal, int n){

	if(col==n){
		ans.push_back(board);
		return;
	}

	for (int row = 0; row < n; ++row)
	{
		if(leftRow[row]==0 && lowerDiagonal[row +col]==0 && upperDiagnonal[n-1+col-row]==0){
			board[row][col] = 'Q';
			leftRow[row] = 1;
			lowerDiagonal[row+col] = 1;
			upperDiagnonal[n-1+col-row] =1;
			solve(col+1,board, ans, leftRow, upperDiagnonal, lowerDiagonal,n);
			board[row][col] = '.';
			 leftRow[row] = 0;
			lowerDiagonal[row+col] = 0;
			upperDiagnonal[n-1+col-row] =0;
		}
	}
} 


int main(){
	int n=5;
	vector<vector<string>> ans;
	vector<string> board(n);
	string s(n, '.');
	for (int i = 0; i < n; ++i)
	{
		board[i] = s;
	}

	vector<int> leftRow(n, 0), upperDiagnonal(2*n-1,0), lowerDiagonal(2*n-1,0);
	solve(0, board, ans, leftRow, upperDiagnonal, lowerDiagonal,n);
	for(auto i:ans){
		for(auto j:i){
			cout<<j<<endl;
		}
		cout<<endl;
	}
}