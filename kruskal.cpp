#include<bits/stdc++.h>
using namespace std;
typedef vector<int>vi;
typedef pair<int,int>pii;
const int Max=1e4+5;
pair<int,pii>p[Max];

int Find(int arr[],int i){
	if(arr[i]==-1)
		return -1;
	return Find(arr,arr[i]);
}

int *Union(int arr[],int x,int y){
	int i=Find(arr,x);
	int j=Find(arr,y);
	if(i!=j)
		arr[i]=j;
	return arr;
}

int kruskal(pair<int,pii>p[],int e){
	int mincost=0;
	int arr[e];
	memset(arr,-1,sizeof arr);
	for(int i=0;i<e;i++){
		int x=p[i].second.first;
		int y=p[i].second.second;
		int wt=p[i].first;
		if(Find(arr,x)!=Find(arr,y)){
			mincost+=wt;
			Union(arr,x,y);
		}
	}
}

int main(){
	int n,e;
	cin>>n>>e;
	for(int i=0;i<e;i++){
		int w,x,y;
		cin>>x>>y>>w;
		p[x]=make_pair(w,make_pair(x,y));
	}
	sort(p,p+e);
	int mincost=kruskal(p,e);
	cout<<mincost;
	return 0;
}
