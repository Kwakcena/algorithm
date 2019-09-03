#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>

#define MX_LEN 301

using namespace std;

int L, Table[MX_LEN][MX_LEN];
int s_r,s_c,e_r,e_c;
int dy[] = {-2, -2, -1, -1, 1, 1, 2, 2}, dx[] = {-1, +1, -2, +2, -2, +2, -1, +1};

void BFS(int **Table)
{
	*(*(Table + s_r) + s_c) = 0;
	queue<pair<int, int> > pos_q;
	pos_q.push(make_pair(s_r, s_c));	

	while(!pos_q.empty()){
		pair<int, int> curt = pos_q.front();
		pos_q.pop();

		for(int i=0; i<8; i++) {
			int n_r = curt.first + dy[i];	
			int n_c = curt.second + dx[i];	
			
			if(n_r < 0 || n_r >= L || n_c < 0 || n_r >= L) continue;
			if(*(*(Table + n_r) + n_c) == -1) {
				*(*(Table + n_r) + n_c) = *(*(Table + curt.first) + curt.second) + 1;
				pos_q.push(make_pair(n_r, n_c));
			}
		}
	}
}

int main()
{
	int T;
	scanf("%d", &T);

	for(int i=0; i<T; i++) {
		scanf("%d", &L);

		int **Table = new int * [L];
		for(int j=0; j<L; j++) {
			*(Table + j) = new int[L];
			memset(*(Table + j), -1, sizeof(int)*L);
		}
		scanf("%d %d", &s_r, &s_c);
		scanf("%d %d", &e_r, &e_c);

		BFS(Table);

		printf("%d\n", *(*(Table + e_r) + e_c));
		for(int j=0; j<L; j++) delete [] *(Table + j); 
		delete [] Table;
	}
	return 0;
}
