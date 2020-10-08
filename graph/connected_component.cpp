#include<bits/stdc++.h>
using namespace std;
typedef vector<int>vi;

void dfsutil(vi *arr,vi &visited,int n,int src,vi &path){
	visited[src]=1;
	path.push_back(src);
	for(auto i:arr[src]){
		if(!visited[i]){
			dfsutil(arr,visited,n,i,path);
		}
	}
}

void dfs(vi *arr,int n){
    vi visited(n,0);
    for(int i=0;i<n;i++){
    	vi path;
    	if(!visited[i]){
    		dfsutil(arr,visited,n,i,path);
    	}
    	for(int i=0;i<path.size();i++){
    		cout<<path[i]<<" ";
    	}
    	cout<<"\n";
    	path.clear();
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
   dfs(arr,n);
}