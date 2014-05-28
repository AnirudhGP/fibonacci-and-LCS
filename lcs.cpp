#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int lcs(char s1[], char s2[], int m, int n)
{
	int LCS[100][100]={};
	for(int i=0; i<=m; i++)
	{
		for(int j=0; j<=n; j++)
		{
			if(i==0 || j==0)
			{
				LCS[i][j]=0;
			}
			else if(s1[i-1]==s2[j-1])
			{
				LCS[i][j]=LCS[i-1][j-1]+1;
			}
			else
			{
				LCS[i][j]=max(LCS[i-1][j], LCS[i][j-1]);	
			}
		}
	}	
	return LCS[m][n];
}
int main()
{
	char s1[100], s2[100];
	cin>>s1>>s2;
	int m=strlen(s1);
	int n=strlen(s2);
	int ans= lcs(s1, s2, m, n);
	cout<<ans<<endl;
	return 0;
}
