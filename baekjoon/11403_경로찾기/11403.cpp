#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int MAX = 100;

int Table[MAX][MAX];
int result[MAX][MAX];
vector <int> myGraph[MAX];

void DFS(int start, bool check[]) {
	check[start] = true;
	printf("start : %d\n", start);

	for(int j=0; j<myGraph[start].size(); j++) {
		int node = myGraph[start][j];
		if(!check[node]) {
			result[start][node] = 1;
			DFS(node, check);
		}
	}
}

int main()
{
	int N;
	scanf("%d", &N);

	bool check[N];
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			scanf("%d", &Table[i][j]);
			if(Table[i][j] == 1) {
				myGraph[i].push_back(j);
				myGraph[j].push_back(i);
			}
		}
	}

	for(int i=0; i<N; i++) {
		memset(check, false, sizeof(bool)*(N));
		DFS(i, check);
	}
	
	printf("======================\n");
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}

	return 0;
}
