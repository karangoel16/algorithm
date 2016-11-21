//this code is prims minimum spanning tree written in STL library
//inspired from dijstra's algorithm in this library
//and is used in hackkerrank
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#define INT_MAX 2147483647
using namespace std;
typedef pair<int,int> ipair;
list <ipair> *lt;
int n;
class Compare
{
public:
    bool operator() (const ipair &a, const ipair &b)
    {
        return a.second>b.second;
    }
};
void shortest_path(int src)
{
    vector <int> dist(n,INT_MAX);
    vector <int> dist_small(n,1);
    priority_queue <ipair,vector<ipair>,Compare>pq;
    pq.push(make_pair(src,0));
    dist[src]=0;
    dist_small[src]=0;
    long sum=0;
    while(!pq.empty())
    {
        int u=pq.top().first;
        int t=pq.top().second;
        pq.pop();
        //std::cout<<u+1<<"\t"<<t<<"\n";
        dist_small[u]=0;
        for(auto i=lt[u].begin();i!=lt[u].end();++i)
        {
            int v=(*i).first;
            int w=(*i).second;
            if(dist_small[v] && dist[v]>w)
            {
                //std::cout<<"**"<<v+1<<"\t"<<w<<"\n";
                    dist[v]=w;
                pq.push(make_pair(v,w));
            }
        }
    }
    //std::cout<<"*";
    for(auto i:dist)
    {
        if(i<100000)
        {
            //std::cout<<"P";
            sum+=i;
        }
        //std::cout<<i<<"\n";

    }
    std::cout<<sum<<"\n";
}
int main()
{
    std::cin>>n;
    int k;
    std::cin>>k;
    lt=new list<ipair>[n];
    for(int i=0;i<k;i++)
    {
        int i1,i2,i3;
        std::cin>>i1>>i2>>i3;
        lt[i1-1].push_back(ipair(i2-1,i3));
        lt[i2-1].push_back(ipair(i1-1,i3));
    }
    int src;
    std::cin>>src;
    shortest_path(src-1);
    return 0;
}
