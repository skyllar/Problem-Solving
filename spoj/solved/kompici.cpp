#include<cstdio>
#include<string.h>
#define FOR(A,B,C) for(A=B ; A<= C ; A++ )
#define FORB(D,B,C) for(D=B ; D<= C ; D++ )
#define MEM(A,B) memset(A,B,sizeof(A))
int outcome[1024];
int main()
{
	int inputs,i,j;
	char c;
	int digits[10],sum;
	scanf("%d",&inputs);
	getchar();
	short int arr[10]={1,2,4,8,16,32,64,128,256,512};
	while( inputs-- )
	{	
		MEM(digits,0);
		sum=0;
		while( (c=getchar())>47 && c < 58 )
			if( ++digits[c - 48] == 1 )
				sum+=arr[c-48];
		outcome[sum]++;
	}

	long long count=0;
	FOR(i,1,1024)	
	{
		count+=(outcome[i]*(outcome[i]-1))/2;
		FORB(j,i+1,1024)//for(j=i+1 ; j< len ; j++ )
		{
			if(i&j)
			{
				count+=(outcome[i]*outcome[j]);
				
			}
		}
	}
	printf("%lld\n",count);
	return 0;
}
