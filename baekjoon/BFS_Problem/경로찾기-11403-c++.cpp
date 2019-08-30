#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>

#define MX_LEN 101

using namespace std;

int N;
vector<int> Table[MX_LEN];

void BFS(int start, int **visited)
{
	queue<int> pos_q;
	pos_q.push(start);

	while(!pos_q.empty()) {
		int curt_pos = pos_q.front();
		pos_q.pop();
		
		for(int i=0; i<Table[curt_pos].size(); i++) {
			if(*(*(visited + start) + Table[curt_pos][i]) == 0) {
				*(*(visited + start) + Table[curt_pos][i]) = 1;
				pos_q.push(Table[curt_pos][i]);
			}
		}
	}
}

int main()
{
	scanf("%d", &N);
	int **visited = new int* [N];
	for(int i=0; i<N; i++) {
		*(visited + i) = new int[N];
		memset(*(visited + i), 0, sizeof(int)*N);
	}

	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			int a; scanf("%d", &a);
			if(a == 1) Table[i].push_back(j);
		}
	}

	for(int i=0; i<N; i++) BFS(i, visited); 

	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			printf("%d ", *(*(visited + i) + j));
		}
		printf("\n");
	}

	for(int i=0; i<N; i++) delete [] *(visited + i);
	delete [] visited;

	return 0;
}
