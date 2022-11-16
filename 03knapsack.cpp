#include <bits/stdc++.h>
using namespace std;


struct Item{
	int value;
	int weight;
    
    Item(int v, int w){
    	weight = w;
    	value = v;
    }
};

bool comparator(Item a, Item b){
	double r1 = (double)a.value/(double)a.weight;
	double r2 = (double)b.value/(double)b.weight;
	return r1>r2;
}


double fractionalKnapScak(int w, Item arr[], int n){
	sort(arr, arr+n,comparator);
	int currWeight = 0;
	double finalValue = 0.0;
	for (int i = 0; i < n; ++i)
	{
		if(currWeight+arr[i].weight<=w){
			currWeight+=arr[i].weight;
			finalValue+=arr[i].value;
		}else{
			int remain = w-currWeight;
			finalValue+=(arr[i].value/(double)arr[i].weight)*(double)remain;
			break;
		}
	}
	return finalValue;
}


int main(){
	int w = 50;
	Item arr[] = {{60,10}, {100,20}, {120,30}};
	int N = sizeof(arr)/sizeof(arr[0]);
	cout<<fractionalKnapScak(w,arr,N)<<endl;

}