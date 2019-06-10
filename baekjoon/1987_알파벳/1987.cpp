#include <cstdio>

using namespace std;

const int MAX = 21;

char Table[MAX][MAX];
int R, C, result;
bool check[123];

int dy[4] = {-1, +1, 0, 0};
int dx[4] = {0, 0, -1, +1};

void DFS(int start_y, int start_x)
{
	check[Table[start_y][start_x]] = true;
	result++;

	for(int idx=0; idx<4; idx++) {
		int row = start_y + dy[idx];
		int col = start_x + dx[idx];

		if((row <= R) && (row >= 1) && (col <= C) && (col >= 1)) {
			if(!check[Table[row][col]]) {
				DFS(row, col);
			}
		}
	}
}

int main()
{
	//입력
	scanf("%d %d", &R, &C);
	for(int i=1; i<=R; i++) {
		char temp[MAX];
		scanf("%s", temp);
		for(int j=1; j<=C; j++) {
			Table[i][j] = temp[j-1];
		}
	}
	DFS(1,1);
	printf("%d", result);
			
	return 0;
}
