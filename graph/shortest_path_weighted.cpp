#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int>pii;
typedef vector<pair<int,int>>vpii;

void dijkstra(vpii *arr,int n,int src,int dest){
	priority_queue<pii,vpii,greater<pii> >pq;
	vector<int>dist(n,INT_MAX);
	pq.push(make_pair(0,src));
	dist[src]=0;
	while(!pq.empty()){
		int tp=pq.top().second;
		pq.pop();
		for(auto j:arr[tp]){
			int v=j->first;
			int wt=j->second;
			if(dist[v]>dist[tp]+wt){
				dist[v]=dist[tp]+wt;
				pq.push(make_pair(dist[v],v));
			}
		}
	}
	cout<<"from src= "<<src<<" to dest"<<dest<<"\n";
	for(int i=0;i<n;i++){
		cout<<i<<" "<<dist[i]<<"\n";
	}
}

int main(){
	int n,e;
	cin>>n>>e;
	vpii *arr=new vpii[n];
	for(int i=0;i<e;i++){
		int x,y,wt;
		cin>>x>>y>>wt;
		arr[x].push_back(make_pair(y,wt));
		arr[y].push_back(make_pair(x,wt));
	}
	int src,dest;
	cin>>src>>dest;
	dijkstra(arr,n,src,dest);
}