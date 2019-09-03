#include <cstring>
#include <cstdio>
#include <queue>
#define MX_LEN 101
#define ABS(x, y) (x) > (y) ? (x)-(y) : (y)-(x)

using namespace std;
int N;
int dy[] = {-1, +1, 0, 0}, dx[] = {0, 0, -1, +1};
char Table[MX_LEN][MX_LEN];

void BFS(int r, int c, int cnt, int **map, char color, bool flag)
{
	*(*(map + r) + c) = cnt;
	queue<pair<int, int> > pos_q;
	pos_q.push(make_pair(r, c));

	while(!pos_q.empty()) {
		pair<int, int> curt = pos_q.front();
		pos_q.pop();

		for(int i=0; i<4; i++) {
			int n_r = curt.first + dy[i];
			int n_c = curt.second + dx[i];

			if(n_r >= N || n_r < 0 || n_c >= N || n_c < 0) continue;
			if(*(*(map + n_r) + n_c) == -1) {
				int temp = ABS(Table[n_r][n_c], color);
				if(flag) {
					if(temp == 0) { 
						*(*(map + n_r) + n_c) = cnt; 
						pos_q.push(make_pair(n_r,n_c));
					}
				}
				else {
					if(temp == 0 || temp == 11) { 
						*(*(map + n_r) + n_c) = cnt; 
						pos_q.push(make_pair(n_r,n_c));
					}
				}
			}
		}
	}
}

int main()
{
	scanf("%d", &N);
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			scanf(" %c", &Table[i][j]);
		}
	}

	int **normal = new int *[N];
	int **abnormal = new int *[N];
	for(int i=0; i<N; i++) {
		*(normal + i) = new int[N];
		memset(*(normal + i), -1, sizeof(int)*N);
		*(abnormal + i) = new int[N];
		memset(*(abnormal + i), -1, sizeof(int)*N);
	}
	
	int cnt = 1;
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			if(*(*(normal + i) + j) == -1) {
				BFS(i, j, cnt, normal, Table[i][j], true);
				cnt++;
			}
		}
	}
	printf("%d ", cnt-1);

	cnt = 1;
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			if(*(*(abnormal + i) + j) == -1) {
				BFS(i, j, cnt, abnormal, Table[i][j], false);
				cnt++;
			}
		}
	}
	printf("%d", cnt-1);
	
	for(int i=0; i<N; i++) {
		delete [] *(normal + i);
		delete [] *(abnormal + i);
	}
	delete [] normal;
	delete [] abnormal;


	return 0;
}
