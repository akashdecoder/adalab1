
#include <bits/stdc++.h>

using namespace std;
int max(int a, int b) { 
	return (a > b)? a : b; 
} 


int knapsack(int n, int wt[], int val[], int W) { 
	int i, w; 
	int K[n+1][W+1]; 
	for (i = 0; i <= n; i++){ 
	 
		for (w = 0; w <= W; w++) { 
			if (i==0 || w==0) 
				K[i][w] = 0; 
			else if (wt[i-1] <= w) 
					K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]); 
			else
					K[i][w] = K[i-1][w]; 
		}
	} 
	return K[n][W]; 
} 

int main() { 
	int n,c;
	cin>>n>>c;
	int w[n],pr[n];
	for(int i=0;i<n;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>pr[i];
	}
	cout<<knapsack(n,w,pr,c);
	return 0;
} 
