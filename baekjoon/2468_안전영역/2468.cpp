#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 105;

int N, height_min = 999, height_max = -1;
int max_cnt = 1;
int Table[MAX][MAX];
bool check[MAX][MAX];

int dy[4] = {-1, +1, 0, 0};
int dx[4] = {0, 0, -1, +1};

void DFS(int start_y, int start_x, int value)
{
	check[start_y][start_x] = true;

	for(int i=0; i<4; i++) {
		int row = start_y + dy[i];
		int col = start_x + dx[i];
		if((row < N)&&(row>=0) && (col < N)&&(col >= 0)) {
			if(!check[row][col] && Table[row][col] > value) {
				DFS(row, col, value);
			}
		}
	}
	
}

int main()
{
	scanf("%d", &N);
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			scanf("%d", &Table[i][j]);
			if(height_min > Table[i][j]) height_min = Table[i][j];
			if(height_max < Table[i][j]) height_max = Table[i][j];
		}
	}

	for(int value=height_min; value<=height_max; value++) {
		int cnt = 0;
		memset(check, false, sizeof(bool)*(MAX*MAX));
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				if(!check[i][j] && Table[i][j] > value) {
					DFS(i, j, value);
					cnt++;
				}
			}
		}
		if(max_cnt < cnt) max_cnt = cnt;
	}

	printf("%d", max_cnt);

	return 0;
}
