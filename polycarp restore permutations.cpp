/*
problem link: https://codeforces.com/problemset/problem/1141/C
author: anan afrida
date created: 03/20/2019
*/


#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define fo(i,j,n) for(register int i=j;i<n;i++)
#define fo2(i,j,n) for(register int i=j;i<=n;i++)

using namespace std;
const int N=5e5+10;
int las[200010];

int main()
{
    clock_t time_req;

    time_req = clock();
    int n,c,pos;
    cin>>n;
    int ans=0;
    int a[n],m[n];
    int s[n],b[n];
    int got=0;
    fo(i,0,n-1)
    {
        cin>>a[i];
        if(!a[i])
            ans=-1;
    }
    if(ans!=-1)
    {
        if(a[0]>0)
        {
            for(int i=a[0]+1; i<=n; i++)
            {
                int temp=i;
                for(c=1; c<n-1; c++)
                {
                    if(a[c]+temp>=1 && a[c]+temp<=n)
                    {
                        temp+=a[c];
                    }
                    else  break;
                }
                if(c==n-1)
                {
                    got=1;
                    pos=i;
                    break;
                }
            }
            if(got==1)
            {
                int p;
                p=pos-a[0];
                fo(k,0,n)
                {
                    las[p]++;
                    if(las[p]>1)
                    {
                        ans=-1;
                        break;
                    }
                    p+=a[k];
                }
                if(ans==-1)cout<<-1;
                else
                {
                    p=pos-a[0];
                    fo(k,0,n)
                    {
                        cout<<p<<" ";
                        p+=a[k];
                    }
                }
            }
            else cout<<-1;
        }
        if(a[0]<0)
        {
            for(int i=n+a[0]; i>0; i--)
            {
                int temp=i;
                for(c=1; c<n-1; c++)
                {
                    if(a[c]+temp<=n && a[c]+temp>=1)
                    {
                        temp+=a[c];
                    }
                    else break;
                }

                if(c==n-1)
                {
                    got=1;
                    pos=i;
                    break;
                }

            }
            if(got==1)
            {
                int p=pos-a[0];
                fo(k,0,n)
                {

                    las[p]++;
                    if(las[p]>1)
                    {

                        ans=-1;
                        break;
                    }
                    p+=a[k];
                }
                if(ans==-1)
                {
                    cout<<-1;
                }
                else
                {
                    p=pos-a[0];
                    fo(k,0,n)
                    {
                        cout<<p<<" ";
                        p+=a[k];
                    }
                }
            }
            else cout<<-1;
        }
    }
    else cout<<-1;
    time_req = clock() - time_req;
    cout << "Using pow function, it took " << (float)time_req/CLOCKS_PER_SEC << " seconds" << endl;
    return 0;
}
