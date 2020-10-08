#include<bits/stdc++.h>
using namespace std;
typedef vector<int>vi;
vi dis,low;
vi ap,visited;
int timer;

void dfs(vi *arr,int src,int p=-1){
	visited[src]=1;
	timer+=1;
	low[src]=dis[src]=timer;
	for(auto i:arr[src]){
		if(p==i)
			continue;
		if(visited[i]){
			low[src]=min(low[src],dis[src]);
		}
		else{
			dfs(arr,i,src);
			low[src]=min(low[src],low[i]);
			if(low[i]>dis[src] && p!=-1){
				cout<<i<<" ";
				ap.push_back(i);
			}
		}
	}
	if(p!=-1 && children>1){
		ap.push_back(src);
		cout<<src;
	}
}

void find_ap(vi *arr,int n){
	dis.assign(n,-1);
	low.assign(n,-1);
	visited.assign(n,0);
	for(int i=0;i<n;i++){
		if(!visited[i]){
			dfs(arr,i);
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
		arr[x].append(y);
		arr[y].append(x);
	}
	find_ap(arr,n);
}