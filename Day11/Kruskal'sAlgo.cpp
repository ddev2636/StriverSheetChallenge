
#include <bits/stdc++.h>
class DisjointSet
{
    vector<int> parent, size;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }
    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int kruskalMST(int n, int m, vector<vector<int>> &graph)
{
    vector<pair<int, pair<int, int>>> edges;
    for (auto i : graph)
    {
        int u = i[0], v = i[1], wt = i[2];
        edges.push_back({wt, {u, v}});
        edges.push_back({wt, {v, u}});
    }
    sort(edges.begin(), edges.end());
    DisjointSet ds(n);
    int sum = 0;

    for (auto i : edges)
    {
        int wt = i.first, u = i.second.first, v = i.second.second;
        if (ds.findUPar(u) != ds.findUPar(v))
        {
            sum += wt;
            ds.unionBySize(u, v);
        }
    }

    return sum;
}
