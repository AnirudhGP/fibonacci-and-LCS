#include<map>
#include<stdio.h>
#include <iostream>
using namespace std;
int fib[5002][1003];
char str[100002];
map <string,int> m;
void checkfib()
{
	long long int a,j,k,l,i;
    fib[0][1000]=0;fib[1][1000]=fib[2][1000]=1;
    for(long long int i=3;i<5000;i++)
    {
        for(j=1000;j>=0;j--)
        {
            fib[i][j]=fib[i][j]+fib[i-1][j]+fib[i-2][j];
            if(fib[i][j]>9)
            {
                fib[i][j-1]+=(fib[i][j]/10);
                fib[i][j]=fib[i][j]%10;
            }
 
        }
		for(k=0;;k++)
        {  
			if(fib[i][k]!=0)
				break; 
		}
        for(j=k,l=0;j<=1000;j++,l++)
        {
        	str[l]=fib[i][j]+48;
        }
		str[l]=0;
		m[str]=1;
    }
}

int main() {
	int t;
    checkfib();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",str);
		if(m.find(str)==m.end())
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
	return 0;
}
