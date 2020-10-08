#include<bits/stdc++.h>
using namespace std;
typedef vector<int>vi;
int timer;
vi visited;
vi tim,low;
vector<pair<int,int> > bridges;
void dfs(int src,vi *arr,int p=-1){
	visited[src]=1;
	timer+=1;
	int children=0;
	tim[src]=timer;
	low[src]=timer;
	for(auto i:arr[src]){
		if(i==p)
			continue;
		if(visited[i]){
			low[src]=min(low[src],tim[i]);
		}
		else(!visited[i]){
			dfs(i,arr);
			low[src]=min(low[src],low[i]);
			if(low[i]>=tim[src])
				bridges.push_back(make_pair(src,i));
		}
	}
}

void find_bridges(vi *arr, int n){
	timer=0;
	visited.assign(n,0);
	tim.assign(n,-1);
	low.assign(n,-1);
	for(int i=0;i<n;i++){
		if(!visited[i]){
			dfs(i,arr);
		}
	}
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
	find_bridges(arr,n);
	for(int i=0;i<bridges.size();i++){
		cout<<bridges[i]->first<<" "<<bridges[i]->second<<"\n";
	}
}