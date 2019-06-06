#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

const int MAX = 100050;

using namespace std;

int T, N, K, W, D[MAX];
int max_level;

vector <int> myGraph[MAX];
vector <int> myTree[MAX];

void BFS()
{
	max_level = 0;
	queue <int> Q;
	queue <int> level;

	Q.push(1);
	level.push(1);
	myTree[1].push_back(D[1]);

	while(!Q.empty()) {
		int current = Q.front();
		int curt_level = level.front();

		if(current == W) max_level = curt_level;

		Q.pop();
		level.pop();

		for(int idx=0; idx<myGraph[current].size(); idx++) {
			int next = myGraph[current][idx];	
			int next_level = curt_level + 1;

			Q.push(next);
			level.push(next_level);
			myTree[next_level].push_back(D[next]);
		}
	}

}

//벡터 초기화
void clearVector(vector<int> arr[], int size) {
	for(int i=0; i<size; i++) {
		arr[i].clear();
	}
}

int main()
{
	//테스트 케이스 입력
	scanf("%d", &T);

	while(T--) {
		//건물 개수, 건설 순서 규칙 입력
		scanf("%d %d", &N, &K);
		for(int i=1; i<=K; i++) {
			scanf("%d", &D[i]);
		}
		printf("시간 입력 끝\n");

		while(N--) {
			int x, y;
			scanf("%d %d", &x, &y);
				
			//연결 관계 입력
			myGraph[x].push_back(y);
		}
		printf("연결 입력 끝\n");
		//목표 건물 입력
		scanf("%d", &W);
		//BFS를 돌린다.
		BFS();

		//각 레벨 별 제일 오래 걸리는 건물의 시간을 더함.
		int result = 0;
		for(int i=1; i<max_level; i++) {
			double max = *max_element(myTree[i].begin(), myTree[i].end());	
			result += (int)max;
		}
		result += D[W];
		//결과 출력
		printf("\n%d\n", result); 

		clearVector(myGraph, MAX);
		clearVector(myTree, MAX);
	}

	return 0;
}
