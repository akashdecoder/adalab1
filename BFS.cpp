#include <bits/stdc++.h>

using namespace std;

const int MAX=5;
void BFS(int curv, int visited[MAX],int adj[MAX][MAX],int n){
	queue<int>q;
	int fv;
	visited[curv] = 1;
	q.push(curv);
	while(!q.empty()){
		fv = q.front();
		q.pop();
		for(int i=0;i<n;i++){
			if(adj[fv][i] == 1 && visited[i] == 0){
				visited[i] = 1;
				q.push(i);
			}
		}
	}
}

int main(){
	int n,srv;
	cin>>n;
	int adj[MAX][MAX];
	int vis[MAX];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>adj[i][j];
		}
	}
	cout<<"\nSource Vertex:";
	cin>>srv;
	
	for(int i=0;i<n;i++){
		vis[i] = 0;
	}
	BFS(srv,vis,adj,n);
	for(int i=0;i<n;i++){
		if(vis[i] == 0)
			cout<<"\nVertex "<<i<<" is not visited";
		else
			cout<<"\nVertex "<<i<<" is visited";
	}
}
