#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct pos {
    int x, y, z;
};

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

double distance_between_two_points(struct pos A, struct pos B)
{
    cout << "A의 좌표 : (x : " << A.x << ", y : " << A.y << ", z : " << A.z << ")" << endl;
    cout << "B의 좌표 : (x : " << B.x << ", y : " << B.y << ", z : " << B.z << ")" << endl;

    double base = sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2)); 
    cout << "밑변 : " << base << endl;

    double height = B.z - A.z;
    cout << "높이 : " << height << endl;

    return sqrt(pow(base, 2) + pow(height, 2));
}

int main()
{
    struct DisjointSet ds(10);
    struct pos test_pos[3] = {
        {1, 1, 1},
        {2, 2, 2},
        {3, 3, 3}
    };

    double test = distance_between_two_points(test_pos[0], test_pos[2]);
    cout << test;

    return 0;
}
