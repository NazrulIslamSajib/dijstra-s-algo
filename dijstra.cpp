#include<bits/stdc++.h>
using namespace std;
vector<pair<long long,long long>>adj[10010];
int const mx=1e5+123;
int const max1=100000000;;
long long dis[mx],i;
int j,tt;
int path[10010];
map<int,pair<long long,long long>>mp;
void dst(long long s,long long n)
{
    pair<long long,long long>sc;
    sc.first=0;
    sc.second=s;
    dis[s]=0;
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
    pq.push(sc);
    while(!pq.empty())
    {
        int u,curD;
        u=pq.top().second;
        curD=pq.top().first;
        pq.pop();
        for(auto x:adj[u])
        {
            int v,w;
            v=x.first;
            w=x.second;
            if(w+curD<dis[v])
            {   path[v]=u;
                dis[v]=w+curD;
                pq.push({w+curD,v});
            }
        }

    }
    for(i=1;i<=n;i++)
    {
        cout<<dis[i]<<" ";
    }


}

int main()
{
   // cin>>tt;

   tt=1;
    for(j=1;j<=tt;j++)
    {
    int n,m;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        long long u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});

    }
    for(i=0;i<=n;i++)
    {
        dis[i]=max1;
    }
    dst(1,n);
    for(i=0;i<=n;i++)
    {
        adj[i].clear();
    }

    }
    return 0;
}
