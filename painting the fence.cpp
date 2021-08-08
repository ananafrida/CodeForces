/*
problem link: https://codeforces.com/contest/1132/problem/C
author: anan afrida
date created: 05/28/2019
*/

#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define ii pair<int,int>
#define fo(i,j,n) for(register int i=j;i<n;i++)
#define S size()
#define vii vector<int>
using namespace std;

int main()
{
    int n,q;
    cin>>n>>q;
    int l[5040],r[5040],only[5040];
    vii c[5040];
    fo(i,1,q+1)
    {
        cin>>l[i]>>r[i];
        fo(j,l[i],r[i]+1)
        c[j].pb(i);
    }
    int ans=0;
    fo(k,1,q+1)
    {
        memset(only,0,sizeof only);
        fo(j,1,n+1)
        {
            if(c[j].size()==1 && (j>r[k] || j<l[k]))
            {
                only[c[j][0]]++;
            }
            else if(j<=r[k]&&j>=l[k] )
            {
                if(c[j].size()==2)
                {
                    if(c[j][0]==k)
                        only[c[j][1]]++;
                    else only[c[j][0]]++;
                }
            }
        }
        int mini=INT_MAX;
        fo(i,1,q+1)
        {
            if(mini>only[i] && i!=k)mini=only[i];
        }
        int cnt=0;
        fo(i,1,n+1)
        {
            if(i>r[k]||i<l[k])
            {
                if(c[i].size()!=0)cnt++;
            }
            else
            {
                if(c[i].size()!=1 ) cnt++;
            }
        }
        ans=max(cnt-mini,ans);
    }
    cout<<ans;
}
