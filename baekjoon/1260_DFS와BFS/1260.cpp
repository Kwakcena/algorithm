#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 10005;

int N, M, V;
bool dfs_check[MAX], bfs_check[MAX];
vector <int> myGraph[MAX];

void DFS(int start) {
	dfs_check[start] = true;
	printf("%d ", start);
	for(int i=0; i<myGraph[start].size(); i++) {
		int next_node = myGraph[start][i];
		if(!dfs_check[next_node]) {
			DFS(next_node);
		}
	}
}

void BFS(int start) {
	bfs_check[start] = true;
	queue <int> Q;
	Q.push(start);

	while(!Q.empty()) {
		int current = Q.front();
		printf("%d ", current);
		Q.pop();

		for(int i=0; i<myGraph[current].size(); i++) {
			int next = myGraph[current][i];
			if(!bfs_check[next]) {
				Q.push(next);
				bfs_check[next] = true;
			}
		}
	}
}

int main()
{
	//정점, 간선, 시작점
	scanf("%d %d %d", &N, &M, &V);
	for(int i=0; i<M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		myGraph[a].push_back(b);
		myGraph[b].push_back(a);
	}

	//입력받은 벡터 정렬
	for(int i=1; i<=N; i++) {
		sort(myGraph[i].begin(), myGraph[i].end());
	}

	DFS(V);
	printf("\n");
	BFS(V);

	return 0;
}
