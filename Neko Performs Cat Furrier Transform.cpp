/*
problem link: https://codeforces.com/problemset/problem/1152/B
author: anan afrida
date created: 04/25/2019
*/



#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define p pair<int,int>
#define fo(i,j,n) for(register int i=j;i<n;i++)

using namespace std;

int main()
{
    int x,r,msb,cnt=0;
    vector<int>ans;
    cin>>x;
    if(1>=x)
        cout<<0;
    else
    {
        r=(int)ceil(log2((double)x));
        while((1<<r)-x!=1)
        {
            cnt++;
            if(!((1<<r)-x))
            {
                msb=(int)floor(log2((double)x));
                ans.pb(msb);
                break;
            }
            else
            {
                msb=(int)floor(log2((double)x));
                msb++;
                x^=(1<<msb)-1;
                r=(int)ceil(log2((double)x));
                ans.pb(msb);
                if((1<<r)-x==1)
                {
                    break;
                }
                cnt++;
                x++;
                r=(int)ceil(log2((double)x));
            }
        }
        cout<<cnt<<"\n";
        fo(i,0,ans.size())cout<<ans[i]<<" ";
    }
}
