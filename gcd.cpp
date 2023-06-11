#include<bits/stdc++.h>
using namespace std;
int hcf(int a, int b)
{
	if(a==0)
	return b;
	if(b==0)
	return a;
	while(a!=b)
	{
		if(a>b)
		{
			a=a-b;
		}
		else
		{
			b=b-a;
		}
	}
	return a;
}
int main()
{
	cout<<hcf(333,100)<<endl;
}