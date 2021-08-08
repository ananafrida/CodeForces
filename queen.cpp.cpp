/*
problem link: https://codeforces.com/problemset/problem/1143/C
author: anan afrida
date created: 03/31/2019
*/

#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define fo(i,j,n) for(register int i=j;i<n;i++)
#define mp make_pair
#define pb push_back
#define pr pair<int,int>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int no;
    int ara[100010];
    vector<int >ans;
    vector<pr>vec[100010];
    fo(i,0,n)
    {
        int p,c;
        cin>>p>>c;
        if(p==-1)
            vec[0].pb({i+1,c});
        else vec[p].pb({i+1,c});
        ara[i+1]=c;
    }
    for(int i=1; i<=n; i++)
    {
        no=0;
        fo(j,0,vec[i].size())
        if(!vec[i][j].second)no=1;
        if(ara[i]==1 && !no)ans.pb(i);
    }
    if(ans.size()==0)cout<<-1;
    else
    {
        sort(ans.begin(),ans.end());
        fo(i,0,ans.size())cout<<ans[i]<<" ";
    }
    return 0;
}

