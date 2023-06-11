#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<int>A;
	int n;
	cin>>n;
	int b;
	cin>>b;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		A.push_back(x);
	}
	int ans=0;
	unordered_map<int,int>mp;
	mp[0]=1;// most important step
	int prefix=0;
	for(int i=0;i<n;i++)
	{
		prefix=prefix^A[i];
		int target=prefix^b;
		if(mp.count(target))
		{
			ans+=mp[target];
		}
		mp[prefix]++;
	}
	cout<<ans<<endl;
}