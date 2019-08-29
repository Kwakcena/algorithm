#include <cstdio>
#include <queue>
#define LEN 100050

using namespace std;

int b(int value) { return value - 1; }
int f(int value) { return value + 1; }
int m(int value) { return value * 2; }
int (*p[3])(int) = {&b, &f, &m};

int check[LEN];

int BFS(int start, int end)
{
	queue<pair<int, int> > pos_q;
	pos_q.push(make_pair(start, 0));

	while(!pos_q.empty()) {
		pair<int, int> curt = pos_q.front(), next;		
		pos_q.pop();

		for(int i=0; i<3; i++) {
			next.first = (*p[i])(curt.first);
			next.second = curt.second + 1;

			if(next.first == end) { return next.second; }
			if(next.first <= 100000 && check[next.first] == 0) {
				check[next.first] = 1;
				pos_q.push(next);
			}
		}
	}
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	if(N == M) printf("0");
	else printf("%d", BFS(N, M));

	return 0;
}
