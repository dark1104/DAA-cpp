#include <bits/stdc++.h>
using namespace std;

void fibIterative(int n){
	int firstTerm = 0, secondTerm =1, nextTerm;
	for (int i = 1; i <= n; ++i)
	{
		if(i==1 || i==2){
			cout<<i-1<<" ";
			continue;
		}

		nextTerm = firstTerm+secondTerm;
		cout<<nextTerm<<" ";
		firstTerm = secondTerm;
		secondTerm = nextTerm;

	}
	cout<<endl;
}

int fibRecursive(int n){
	if(n<=1){
		return n;
	}

	return fibRecursive(n-1)+fibRecursive(n-2);
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
        cout<<fibRecursive(i)<<" ";
	}
}