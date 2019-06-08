#include <cstdio>
#include <vector>

using namespace std;

const int MAX = 1005;

int N, M;
bool check[MAX];
vector <int> myGraph[MAX];

void DFS(int start)
{
	check[start] = true;
	for(int i=0; i<myGraph[start].size(); i++) {
		int next_node = myGraph[start][i];
		if(!check[next_node]) {
			DFS(next_node);
		}
	}

}

int main()
{
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		myGraph[a].push_back(b);
		myGraph[b].push_back(a);
	}


	int cnt = 0;
	for(int i=1; i<=N; i++) {
		if(!check[i]) {
			DFS(i);
			cnt++;
		}
	}

	printf("%d", cnt);


	return 0;
}
