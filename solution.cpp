#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define INF 1e18
#define pb push_back
#define pi pair<ll,ll>
char s[50];
ll ans;
ll n;
bool find(ll curr,ll prev)
{
	if(prev==-1)
	{
		ll cnt=0;
		for(int i=curr;i<n-1;i++)
		{
			cnt=cnt*10+(s[i]-'0');
			if(s[i+1]!='0' && find(i+1,cnt)==true)
			{
				ans=cnt;
				return true;
			}
		}
		return false;
	}
	ll cnt=0;
	for(int i=curr;i<n-1;i++)
	{
		cnt=cnt*10+(s[i]-'0');
		if(cnt==prev+1 && s[i+1]!='0' && find(i+1,cnt)==true)
		{
			return true;
		}
	}
	cnt=cnt*10+(s[n-1]-'0');
	if(cnt==prev+1)
		return true;
	return false;
}
int main()
{
	ll q;
	cin>>q;
	while(q--)
	{
		cin>>s;
		n=strlen(s);
		if(find(0,-1)==true)
		{
			cout<<"YES"<<" "<<ans<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
}
