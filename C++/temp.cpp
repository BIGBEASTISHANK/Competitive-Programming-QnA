#include<bits/stdc++.h>
#define int long long int
using namespace std;
int ans=INT_MAX;

void cylinder(int ht[],int n, int i,int curr,int h)
{
    if(curr>h)
        return;
    if(i==n)
    {
        ans=min(ans,h-curr);
        return;
    }

    cylinder(ht,n,i+1,curr+ht[i],h);
    cylinder(ht,n,i+1,curr,h);
}

int32_t main()
{
    int n,h;
    cin>>n>>h;
    int ht[n];
    for(int i=0;i<n;i++)
        cin>>ht[i];
    cylinder(ht,n,0,0,h);
    cout<<ans;
}