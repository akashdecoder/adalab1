#include <bits/stdc++.h>
using namespace std;
const int MAX=5;
void DFS(int currv,	int vis[MAX],int ad[MAX][MAX], int n){
	vis[currv] = 1;
	for(int i=0;i<n;i++){
		if((ad[currv][i] == 1)&&vis[i] == 0)
			DFS(i,vis,ad,n);
	}
}
int main(){
	int src,n;
	cout<<"Enter number of vertices: ";
	cin>>n;
	int adj[MAX][MAX];
	int visited[MAX];
	
	cout<<"Enter the adjacency matrix: \n";
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>adj[i][j];
		}
	}
	cout<<"Enter the source vertex: ";
	cin>>src;
	for(int i=0;i<n;i++){
		visited[i]=0;
	}
	DFS(src,visited,adj,n);
	for(int i=0;i<n;i++){
		if(visited[i] == 0)
			cout<<"Vertex not visited\n";
		else
			cout<<"Vertex Visited\n";
	}
	return 0;
}
