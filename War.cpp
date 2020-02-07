ge#include<bits/stdc++.h>
using namespace std;

const int MAX = 5;

void Warshall(int adj[MAX][MAX], int n){
	int path[MAX][MAX];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			path[i][j] = adj[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				if(path[i][j] || (path[i][k] && path[k][j]))
					path[i][j] = 1;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			adj[i][j] = path[i][j];
		}
	}
}

int main(){
	int n;
	cin>>n;
	int arr[MAX][MAX];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	Warshall(arr,n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}
