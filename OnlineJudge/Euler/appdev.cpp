#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 1000000000
using namespace std;
typedef pair<int, int> pp;

int n, m, s, ap1, ap2, sum;
int dist[1000001], visit[1000001];
vector<vector<pp> > a;
priority_queue<pp, vector<pp>, greater<pp> > Q;
pp tmp;

int main()
{
    int i, x, y, z, len;

    scanf("%d %d %d %d %d", &m, &n, &s, &ap1, &ap2);
    a.resize(n+1);

    for(i=1 ; i<=m ; i++)
    {
        scanf("%d %d %d", &x, &y, &z);
        a[x].push_back(make_pair(y, z));
        a[y].push_back(make_pair(x, z));
    }

    for(i=1 ; i<=n ; i++)
        dist[i] = INF;

    Q.push(make_pair(0, s));
    while(!Q.empty())
    {
        tmp = Q.top(), Q.pop();
        if(!visit[tmp.second])
        {
            visit[tmp.second] = 1;
            dist[tmp.second] = tmp.first;
            len = a[tmp.second].size();
            for(i=0 ; i<len ; i++)
                if(!visit[a[tmp.second][i].first] && dist[a[tmp.second][i].first]>a[tmp.second][i].second+dist[tmp.second])
                    Q.push(make_pair(a[tmp.second][i].second+dist[tmp.second], a[tmp.second][i].first));
        }
    }


    sum+=min(dist[ap1], dist[ap2]);

    for(i=1 ; i<=n ; i++)
        dist[i] = INF, visit[i] = 0;

    Q.push(make_pair(0, ap1));
    while(!Q.empty())
    {
        tmp = Q.top(), Q.pop();
        if(!visit[tmp.second])
        {
            visit[tmp.second] = 1;
            dist[tmp.second] = tmp.first;
            len = a[tmp.second].size();
            for(i=0 ; i<len ; i++)
                if(!visit[a[tmp.second][i].first] && dist[a[tmp.second][i].first]>a[tmp.second][i].second+dist[tmp.second])
                    Q.push(make_pair(a[tmp.second][i].second+dist[tmp.second], a[tmp.second][i].first));
        }
    }
    sum+=dist[ap2];
    printf("%d", sum);
    return 0;
}
