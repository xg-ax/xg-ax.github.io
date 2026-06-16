#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5005;
const int M=2e5+10;
const int INF=0x3f3f3f3f;
struct Edge{
	int to;
	int w;
    int next;
}edge[M*2];
int head[N],cnt;
void init(){
    memset(head,-1,sizeof head);
    cnt=0;
}
void add(int u,int v,int w){
    edge[cnt].to=v;
    edge[cnt].w=w;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
struct Node{
    int d=0;
    int u;
    bool operator < (const Node &a) const{
        return d>a.d;
    }
};
int dis[N];
bool vis[N];
int n,m;
void prim(){
    fill(dis,dis+N,INF);
    memset(vis,0,sizeof(vis));
    priority_queue<Node>q;
    dis[1]=0;
    q.push({0,1});
    ll weight=0;
    int cnt;
    while(!q.empty()){
        Node t=q.top();
        int u=t.u;
        int d=t.d;
        q.pop();
        if(vis[u]){
            continue;
        }
        vis[u]=true;
        weight+=d;
        cnt++;
        for(int i=head[u];i!=-1;i=edge[i].next){
            int v=edge[i].to;
            int w=edge[i].w;
            if(!vis[v]&&w<dis[v]){
                dis[v]=w;
                q.push({dis[v],v});
            }
        }
    }
    if(cnt==n){
        cout<<weight<<endl;
    }else{
        cout<<"orz"<<endl;
    }
}
int main(){
    cin>>n>>m;
    init();
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);
        add(v,u,w);
    }
    prim();
}