#include<bits/stdc++.h>
using namespace std;
typedef vector<int>vi;

void print_path(vi parent,vi dist,int src,int dest){
	vi path;
	for(int i=dest;i!=-1;i=parent[i]){
		path.push_back(i);
	}
	reverse(path.begin(),path.end());
	for(auto i:path){
		cout<<i<<" ";
	}
}

void shortest_path(int src,int dest,vi *arr,int n){
	queue<int>q;
	vi visited(n,0);
	vi d(n,0);
	vi parent(n,-1);
	q.push(src);
	visited[src]=1;
	d[src]=0;
	while(!q.empty()){
		int tp=q.front();
		q.pop();
		for(auto u:arr[tp]){
			if(visited[u]==0){
				visited[u]=1;
				q.push(u);
				d[u]=d[tp]+1;
				parent[u]=tp;
				if(dest==u)
					break;
			}
		}
	}
	print_path(parent,d,src,dest);
}

int main(){
	int n,e;
	cin>>n>>e;
	vi *arr=new vi[n];
	for(int i=0;i<e;i++){
		int x,y;
		cin>>x>>y;
		arr[x].push_back(y);
		arr[y].push_back(x);
	}
	int src,dest;
	cin>>src>>dest;
	shortest_path(src,dest,arr,n);

}
