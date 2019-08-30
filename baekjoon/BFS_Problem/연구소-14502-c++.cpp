#include <cstdio>
#include <bits/stdc++.h>

#define MX_LEN 10

using namespace std;

int N, M;
int Table[MX_LEN][MX_LEN], visited[MX_LEN][MX_LEN];
int dy[] = {-1, +1, 0, 0}, dx[] = {0, 0, -1, +1};

vector<pair<int, int> > virus_list, safe_zone;

void testPrint()
{
	printf("====================\n");
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			printf("%d ", Table[i][j]);
		}
		printf("\n");
	}
}

int BFS()
{
	queue<pair<int, int> > pos_q;
	for(int i=0; i<virus_list.size(); i++) pos_q.push(virus_list[i]);

	while(!pos_q.empty()) {
		pair<int, int> curt = pos_q.front();

		for(int i=0; i<4; i++) {
			int r = curt.first + dy[i];
			int c = curt.second + dx[i];

			if(r < 0 || r >= N || c < 0 || c >= M) continue;
		}
	}
}


void makeWall(int idx, int cnt)
{
	if(cnt == 3) {
		testPrint();
		return;
	}
	for(int i=idx; i<safe_zone.size(); i++) {
		Table[safe_zone[i].first][safe_zone[i].second] = 1;
		makeWall(i + 1, cnt + 1);
		Table[safe_zone[i].first][safe_zone[i].second] = 0;
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			scanf("%d", &Table[i][j]);
			if(Table[i][j] == 2) virus_list.push_back(make_pair(i, j));
			else if(Table[i][j] == 0) safe_zone.push_back(make_pair(i, j));
		}
	}

	makeWall(0, 0);
	
	return 0;
}
