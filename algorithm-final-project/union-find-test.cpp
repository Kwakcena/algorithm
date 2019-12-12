#include <iostream>
#include <cmath>
#include <vector>

#define N 10

using namespace std;

typedef struct pos {
    int x, y, z;
} POS;

typedef struct DisjointSet {
    vector<int> parent, rank;

    DisjointSet(int n): parent(n), rank(n,1) {
        for(int i=0; i<n; i++) 
            parent[i] = i;
    }

    int find(int u) {
        if(u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }

    int findParent(int u, int v) {
        u = find(u); v = find(v);
        return u == v ? 1 : 0;
    }

    void merge(int u, int v) {
        u = find(u); v = find(v);

        if(u == v) return;
        if(rank[u] > rank[v]) swap(u, v);
        parent[v] = u;

        if(rank[u] == rank[v]) ++rank[v];
    }
}DS;

double distanceBetweenTwoPoints(POS A, POS B)
{
    cout << "A의 좌표 : (x : " << A.x << ", y : " << A.y << ", z : " << A.z << ")" << endl;
    cout << "B의 좌표 : (x : " << B.x << ", y : " << B.y << ", z : " << B.z << ")" << endl;

    double base = sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2)); 
    double height = B.z - A.z;

    cout << "거리 : " << sqrt(pow(base, 2) + pow(height, 2)) << endl;
    return sqrt(pow(base, 2) + pow(height, 2));
}

void testPrint(DS ds)
{
    for(int i=0; i<N; i++) {
        cout << "node : " << i << " / parent : " << ds.find(i) << endl;
    }
}

void vertexConnection(POS posData[], DS *ds, double R)
{
    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {
            cout << "( " << i << " " << j << " )" << endl;
           if(R >= distanceBetweenTwoPoints(posData[i], posData[j])) {
               ds->merge(i, j);
           }
        }
    }
}

int main()
{
    DS ds(N + 1);
    POS test_pos[N] = {
        {1, 0, 11},
        {12, 0, 2},
        {3, 2, 10},
        {4, 3, 8},
        {0, 1, 6},
        {7, 2, 1},
        {13, 22, 0},
        {9, 3, 1},
        {1, 3, 3},
        {0, 0, 0},
    };
   

    vertexConnection(test_pos, &ds, 15.0);
    testPrint(ds);

    return 0;
}
