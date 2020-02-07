#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
const int MAX=3;
void Knapsack(int n,int w[MAX],int pr[MAX],int cap){
	int table[n][n];
	int subset[n];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=cap;j++){
			if(i == 0 || j == 0)
				table[i][j] = 0;
			else if((w[i-1])<=j)
				table[i][j] = max(table[i-1][j],table[i-1][j-w[i-1]]+pr[i-1]);
			else
				table[i][j] = table[i-1][j];
		}
	}
	int max_profit = table[n][cap];
	for(int i=0;i<n;i++){
		subset[i] = 0;
	}
	int a=n;
	int b=cap;
	while(a >=1 && b>=1){
		if(table[a][b] != table[a-1][b]){
			subset[a] = 1;
			b = b - w[a];
		}
		a = a-1;
	}
	cout<<"\nMaximum Profit: "<<max_profit<<endl;
	for(int i=0;i<n;i++){
		cout<<subset[i]<<"\t";
	}
	cout<<endl;
}

int main(){
	int n,c;
	cin>>n>>c;
	int w[n],pr[n];
	for(int i=0;i<n;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>pr[i];
	}
	Knapsack(n,w,pr,c);
	return 0;
}
