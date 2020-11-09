#include<bits/stdc++.h>
using namespace std;

int LCS(string txt,string pat){
	int n=txt.length();
	int m=pat.length();
	int dp[n+1][m+1];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i==0 || j==0){
				dp[i][j]=0;
			}
			else if(txt[i-1]==pat[j-1]){
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else
				dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
		}
	}
	return dp[n-1][m-1];
}

int main(){
	string txt,pat;
	cin>>txt>>pat;
	cout<<LCS(txt,pat);
	return 0;
}