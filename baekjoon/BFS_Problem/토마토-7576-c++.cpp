#include <iostream>
#include <cstdio>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int dy[] = {-1, +1, 0, 0}, dx[] = {0, 0, -1, +1};
int zero_cnt, one_cnt;

int BFS(vector<pair<int, int> > a_list, int **a_Table, int N, int M)
{
	queue<pair<pair<int ,int>, int> > pos_q;
	
	if(one_cnt == 0) return -1;
	for(int i=0; i<a_list.size(); i++) { pos_q.push(make_pair(a_list[i], 0)); }

	while(!pos_q.empty()) {
		pair<pair<int, int>, int> curt = pos_q.front(), next;
		pos_q.pop();

		for(int i=0; i<4; i++) {
			next.first.first = curt.first.first + dy[i];
			next.first.second = curt.first.second + dx[i];
			next.second = curt.second + 1;
			

			if(next.first.first < 0 || next.first.first >= N || next.first.second < 0 || next.first.second >= M) continue;

			if(*(*(a_Table + next.first.first) + next.first.second) == 0) {
				*(*(a_Table + next.first.first) + next.first.second) = 1;
				zero_cnt--;
				pos_q.push(next);
			}

		}
	}

	return pos_q.back().second;
}

int main()
{
	int M, N;
	vector<pair<int, int> > list;

	scanf("%d %d", &M, &N);

	int **Table = new int *[N];
	for(int i=0; i<N; i++) *(Table + i) = new int[M];

	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++) {
			scanf("%d", (*(Table + i) + j));
			if(*(*(Table + i) + j) == 1) {
				list.push_back(make_pair(i, j));
				one_cnt++;
			}
			else if(*(*(Table + i) + j) == 0) zero_cnt++;
		}
	}

	
	int result = BFS(list, Table, N, M);

	if(zero_cnt > 0) printf("-1");
	else printf("%d", result);


	for(int i=0; i<N; i++) delete [] *(Table + i);
	delete [] Table;


	return 0;
}
