#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 10;
const int LOGMAX = 20;

int st[MAX][LOGMAX + 1];
vector<int> gr[MAX];
int level[MAX];

void dfs(int node, int par)
{
    st[node][0] = par;
    level[node] = level[par] + 1;

    for (int k = 1; k <= LOGMAX; ++k)
    {
        if (st[node][k - 1] != -1)
        {
            st[node][k] = st[st[node][k - 1]][k - 1];
        }
    }
    for (auto child : gr[node])
    {
        if (child != par)
        {

            dfs(child, node);
        }
    }
}
int lca(int u, int v)
{
    if (level[v] > level[u])
    {
        swap(u, v);
    }

    for (int k = LOGMAX - 1; k >= 0; --k)
    {
        if (level[st[u][k]] >= level[v] && st[u][k] != -1)
        {
            u = st[u][k];
        }
    }
    if (u == v)
    {
        return u;
    }
    for (int k = LOGMAX - 1; k >= 0; --k)
    {
        if (st[u][k] != st[v][k])
        {
            u = st[u][k];
            v = st[v][k];
        }
    }

    return st[u][0];
}

int32_t main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    dfs(1, -1);
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        int dis = level[u]+level[v] - 2*level[lca(u,v)];
        cout << dis << "\n";
    }
}
