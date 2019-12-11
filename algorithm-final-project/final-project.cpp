#include <iostream>
using namespace std;

const int N = 10;

typedef struct pos {
    int x, y, z;
} POS;

POS test_pos[N] = {
    {1, 1, 1},
    {4, 9, 3},
    {14, 2, 3},
    {3, 8, 0},
    {0, 23, 3},
    {6, 2, 9},
    {1, 3, 3},
    {21, 7, 3},
    {1, 4, 0},
    {9, 2, 3}
};

int main()
{
    double r;
    cout << "전파 도달거리 입력 : ";
    cin >> r;

    for(int i=0; i<N; i++) {
        cout << i << "번 : " << test_pos[i].x << " " << test_pos[i].y << " " << test_pos[i].z << endl;
    }


    return 0;
}
