#include<bits/stdc++.h>
using namespace std;
const int N=1e7+1;
vector<bool>isPrime(N,1);

int main()
{
	isPrime[0]=isPrime[1]=0;
	for(int i=2;i<N;i++)
	{
		if(isPrime[i])
		{
			for(int j=2*i;j<N;j+=i)
			{
				isPrime[j]=0;
			}
		}
	}
	
	cout<<N<<endl;
	
}
// agar prime number hai to uske sare multiples kp uda do
//// j=i,2i,3i,4i,5i and j=2*i se initialize kiye kyunki j=i is a prime number
//sabko prime bana diye