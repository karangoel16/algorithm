#include <vector>
#include <iostream>
#include <limits>
#include <queue>
#include <list>
using namespace std;
typedef pair<int,int> ipair;
class graph
{
    int V;//this is the number of the vertices a graph has;
    list<ipair> *adj;
    public:
    graph(int v);
    void addEdge(int u,int v,int w);
    int shortest_path(int s);
};
graph::graph(int v)
{
    this->V=v;
    adj=new list<ipair> [v];
}
void graph::addEdge(int u,int v,int w)
{
    adj[u].push_back(std::pair<int,int>(v,w));
    adj[v].push_back(std::pair<int,int>(u,w));
}
int graph::shortest_path(int src)
{
    if(src>V)
    {
        return -1;
    }
    vector<int> dist(V,INT_MAX);
    priority_queue<ipair,vector<ipair>,greater<ipair>>pq;
    pq.push(make_pair(0,src));
    dist[src]=0;//distance of source from itself is 0
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        for(auto i=adj[u].begin();i!=adj[u].end();++i)
        {
            int v=(*i).first;
            int w=(*i).second;
            if(dist[v]>dist[u]+w)
            {
                dist[v]=dist[u]+w;
                pq.push(make_pair(dist[v],v));
            }
        }
    }
    std::cout<<"Vectex distance from source\n";
    for(int i=0;i<V;i++)
    {
        std::cout<<i<<" "<<dist[i]<<"\n";
    }
}
int main()
{
    int V=9;
    graph g(V);
g.addEdge(0,1,4);
g.addEdge(0,7,8);
g.addEdge(1,2,8);
g.addEdge(1, 7, 11);
g.addEdge(2, 3, 7);
g.addEdge(2, 8, 2);
g.addEdge(2, 5, 4);
g.addEdge(3, 4, 9);
g.addEdge(3, 5, 14);
g.addEdge(4, 5, 10);
g.addEdge(5, 6, 2);
g.addEdge(6, 7, 1);
g.addEdge(6, 8, 6);
g.addEdge(7, 8, 7);
g.shortest_path(0);
    return 0;
}
