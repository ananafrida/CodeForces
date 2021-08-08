/*
problem link: https://codeforces.com/problemset/problem/1155/D
author: anan afrida
date created: 04/24/2019
*/

#include<bits/stdc++.h>
#define ll long long
#define  ld long double
#define mp make_pair
#define p pair<int,int>
#define pb push_back
#define fo(i,j,n) for(register ll i=j;i<n;i++)

using namespace std;
ll dp[300010][3];
int main()
{
    ll n;
    ll x;
    cin>>n>>x;
    ll ara[n],ans=0;
    fo(i,1,n+1)
    {
        cin>>ara[i];
        dp[i][0]=max(0ll,dp[i-1][0])+ara[i];
        dp[i][1]=max(max(dp[i-1][0],dp[i-1][1]),0ll)+ara[i]*x;
        dp[i][2]=max(max(dp[i-1][2],dp[i-1][1]),dp[i-1][0])+ara[i];
        ans=max(ans,max(max(dp[i][0],dp[i][1]),dp[i][2]));
    }
    cout<<ans;
}
