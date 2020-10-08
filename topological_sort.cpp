#include<bits/stdc++.h>
using namespace std;

vector<int> find_in_degree(vector<int>&v,int n,vector<int> *arr){
	for(int i=0;i<n;i++){
		for(auto j:arr[i]){
            v[j]++;
		}
	}
  return v;
}

vector<int> topological_sort(vector<int>in_degree,vector<int>*arr,int n){
    int c=0;
	vector<int>top_sort;
	queue<int>q;
	for(int i=0;i<n;i++){
		if(in_degree[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int tp=q.front();
		top_sort.push_back(tp);
		q.pop();
		for(auto u:arr[tp]){
			if(--in_degree[u]==0)
				q.push(u);
		}
		c++;
	}
	if(c!=n){
        cout<<"There is cycle\n";

	}
	return top_sort;
}

int main(){
	int n,e;
	cin>>n>>e;
	vector<int>*arr=new vector<int>[n];
	for(int i=0;i<e;i++){
		int x,y;
		cin>>x>>y;
		arr[x].push_back(y);
	}
	vector<int>in_degree(n,0);
	find_in_degree(in_degree,n,arr);
	vector<int> top_sort=topological_sort(in_degree,arr,n);
	for(auto i:top_sort)
        cout<<i<<" ";
	return 0;
}
