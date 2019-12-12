#include <iostream>
#include <cmath>
#include <vector>
#include <map>

#define N 10    //정점의 개수

using namespace std;

//3차원 공간에서 좌표를 저장하는 구조체
typedef struct pos {
    int x, y, z;
} POS;

//disjoint set 자료구조 
typedef struct disjointSet {
    vector<int> parent, rank;

    disjointSet(int n): parent(n), rank(n,1) {
        for(int i=0; i<n; i++) 
            parent[i] = i;
    }

    int find(int u) {
        return u == parent[u] ? u : parent[u] = find(parent[u]);
    }

    void merge(int u, int v) {
        u = find(u); v = find(v);
        if(u == v) return;

        if(rank[u] > rank[v]) 
            swap(u, v);
        parent[v] = u;

        if(rank[u] == rank[v]) ++rank[v];
    }
}DS;

//두 점 사이의 거리 구하는 함수
double distanceBetweenTwoPoints(POS A, POS B)
{
    double base = sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2)); 
    double height = B.z - A.z;
    double result = sqrt(pow(base, 2) + pow(height, 2));

    return result;
}

//각 점을 연결하는 함수
void vertexConnection(POS *posData, DS *ds, double R)
{
    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {
            //실수 R보다 작거나 같은 거리에 대해서만 직접 연결.
           if(R >= distanceBetweenTwoPoints(posData[i], posData[j])) {
               ds->merge(i, j);
           }
        }
    }
}

//최종 결과를 출력해주는 함수
void resultPrint(POS *posData, DS *ds)
{
    map<int, vector<int>> partition;
    cout << "=== 좌표 정보 출력 ===" << endl;
    for(int i=0; i<N; i++) {
        partition[ds->find(i)].push_back(i);
        cout << "POINT [" << i << "]" 
            << " 좌표 ( x : " << posData[i].x
            << ", y : " << posData[i].y
            << ", z : " << posData[i].z
            << ") " << endl;
    }

    cout << endl << "=== 무선망의 개수 출력 ===" << endl;
    int wirelessCnt = partition.size();
    wirelessCnt == 1 ? 
        cout << "하나의 무선망 입니다." : 
        cout << "무선망의 개수는 " << wirelessCnt << "개 입니다.";
    cout << endl;

    int idx = 1;
    cout << endl << "=== partition 정보 출력 ===" << endl;
    for(auto elem : partition) {
        cout << "partition " << idx++ << " --- ";
        cout << "POINT [" << elem.first << "] 과 연결된 정점 { ";
        for(auto vector_elem : elem.second) {
            cout << vector_elem << " ";
        }
        cout << "}" <<  endl;
    }

}


int main()
{
    double R;
    DS ds(N + 1);
    POS vertex[N] = {
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
   
    cout << "전파 도달 거리를 입력하세요(실수값) : ";
    cin >> R;

    vertexConnection(vertex, &ds, R);
    resultPrint(vertex, &ds);

    return 0;
}
