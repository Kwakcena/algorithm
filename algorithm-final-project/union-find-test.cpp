#include <iostream>
#include <vector>

using namespace std;

struct DisjointSet {
    vector<int> parent, rank;

    DisjointSet(int n): parent(n), rank(n,1) {
        for(int i=0; i<n; i++) 
            parent[i] = i;
    }

    int find(int u) {
        if(u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }

    void merge(int u, int v) {
        u = find(u); v = find(v);

        if(u == v) return;
        if(rank[u] > rank[v]) swap(u, v);
        parent[u] = v;

        if(rank[u] == rank[v]) ++rank[v];
    }
};

int main()
{
    struct DisjointSet ds(10);

    ds.merge(1, 2);
    ds.merge(1, 3);

    cout << ds.find(1) << endl;
    cout << ds.find(3) << endl;

    return 0;
}
