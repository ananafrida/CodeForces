#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define fo(i,j,n) for(register int i=j;i<n;i++)
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define vi vector<int>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    int pos_sum[5010]={0};
    cin>>n;
    int ara[600010];
    set<int>st;
    int cnt[5010]={0};

    fo(i,0,2*n)
    {
       cin>>ara[i];
       st.insert(ara[i]);
       cnt[ara[i]]++;
    }
    for(auto k:st)
    {
        if(cnt[k]%2!=0)
        {
            cout<<-1<<"\n";
            return 0;
        }
    }
   int cn[5010]={0};
    fo(i,0,2*n)
    {
        cn[ara[i]]++;
        if(cn[ara[i]]%2==0)
        {
            cout<<pos_sum[ara[i]]+1<<" "<<i+1<<"\n";
            pos_sum[ara[i]]=0;
        }
        else{
            pos_sum[ara[i]]+=i;
        }
    }

}
