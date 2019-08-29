#include <cstdio>
#include <cstring>
#include <queue>

#define LEN 101
using namespace std;

int Table[LEN][LEN], visited[LEN][LEN];
int N, M;
int dy[] = {-1, +1, 0, 0}, dx[] = {0, 0, -1, +1};

void BFS()
{
	visited[0][0] = 1;	
	queue<pair<int, int> > pos_Q;
	pos_Q.push(make_pair(0, 0));

	while(!pos_Q.empty())
	{
		pair<int, int> curt = pos_Q.front(), next;
		pos_Q.pop();

		for(int i=0; i<4; i++) {
			next.first = curt.first + dy[i];
			next.second = curt.second + dx[i];

			if(next.first < 0 || next.first >= N || next.second < 0 || next.second >= M) continue;
			if(Table[next.first][next.second] == 1 && visited[next.first][next.second] == -1) {
				pos_Q.push(next);
				visited[next.first][next.second] = visited[curt.first][curt.second] + 1;
			}
		}
	}
}

int main()
{
	memset(visited, -1, sizeof(visited));
	scanf("%d %d", &N, &M);

	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			scanf("%1d", &Table[i][j]);
	
	BFS();
	printf("%d", visited[N-1][M-1]);	

	

	return 0;
}
