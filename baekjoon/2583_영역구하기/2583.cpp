#include <cstdio>
#include <unistd.h>

using namespace std;

const int MAX = 101;

int M, N, K, idx = 0;
int Table[MAX][MAX];
bool check[MAX][MAX];

int dy[4] = {-1, +1, 0, 0};
int dx[4] = {0, 0, -1, +1};

void DFS(int start_x, int start_y, int *value)
{
	check[start_y][start_x] = true;
	(*value)++;

	for(int i=0; i<4; i++) {
		int row = start_y + dy[i];
		int col = start_x + dx[i];

		if(((row < N) && (row >= 0)) && ((col < M) && (col >= 0))) {
			if(!check[row][col] && Table[row][col] == 0) {
				DFS(col, row, value);
			}
		}
	}

}

void Sort(int result[], int idx) {
	for(int i=0; i<idx; i++) {
		int temp = i;
		for(int j=i+1; j<idx; j++) {
			if(result[temp] > result[j]) {
				int tmp = result[j];
				result[j] = result[temp];
				result[temp] = tmp;
			}
		}
	}
}

int main()
{
	int value = 0;
	int result[MAX] = {0,};

	scanf("%d %d %d", &M, &N, &K);

	while(K--) {
		int s_x = 0, s_y = 0, e_x = 0, e_y = 0;
		scanf("%d %d %d %d", &s_y, &s_x, &e_y, &e_x);
		e_y--; e_x--;
		
		for(int row = s_y; row <= e_y; row++) {
			for(int col = s_x; col <= e_x; col++) {
				Table[row][col] = 1;
			}
		}
	}

	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			if(!check[i][j] && Table[i][j] == 0) {
				int cnt = 0;
				DFS(j, i, &cnt);
				value++;
				result[idx++] = cnt;
			}
		}
	}
	Sort(result, idx);

	printf("%d\n", value);
	for(int i=0; i<idx; i++) printf("%d ", result[i]);
	
	return 0;
}
