#include <cstdio>
#include <cstring>
using namespace std;

const int MAX = 51;

int N, M, K;

int dy[4] = {-1, +1, 0, 0};
int dx[4] = {0, 0, -1, +1};

int Table[MAX][MAX];
bool check[MAX][MAX];

void DFS(int s_row, int s_col, int value)
{
	check[s_row][s_col] = true;
	Table[s_row][s_col] = value;

	for(int idx = 0; idx<4; idx++) {
		int n_row = s_row + dy[idx];
		int n_col = s_col + dx[idx];
		if((n_row < N && n_row >= 0) && (n_col < M && n_col >=0)) {
			if(!check[n_row][n_col] && Table[n_row][n_col] == 1) {
				DFS(n_row, n_col, value);
			}
		}
	}
}

int main()
{
	int T=0;
	scanf("%d", &T);

	while(T--) {
		int value = 1;
		memset(Table, 0, sizeof(int)*(MAX*MAX));
		memset(check, false, sizeof(bool)*(MAX*MAX));

		scanf("%d %d %d", &M, &N, &K);
		for(int i=0; i<K; i++) {
			int row, col;
			scanf("%d %d", &col, &row);
			Table[row][col] = 1;
		}


		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) {
				if(Table[i][j] && !check[i][j]) {
					DFS(i,j,value);
					value++;
				}
			}
		}

		printf("%d\n", value-1);
	}

	return 0;
}
