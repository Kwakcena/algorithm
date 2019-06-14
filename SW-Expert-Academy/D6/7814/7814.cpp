#include <cstdio>

const int MAX = 105;

typedef struct {
	int understanding;
	int digestive_power;
	int capacity_value;
} DATA;

int N;
int cnt, maxCnt = -1;
bool check[MAX];
DATA data[MAX];

void DFS(int visited, int a_under, int a_diges, int test)
{
	check[visited] = true;
	cnt++;
	if(cnt > maxCnt) maxCnt = cnt;

	printf("재귀 %d) 방문 : (%d %d)\n", test, data[visited].understanding, data[visited].digestive_power);

	for(int i=0; i<=data[visited].capacity_value; i++) {
		a_under += data[visited].capacity_value - i;
		a_diges += i;
		printf("재귀 %d) 현재 (%d %d)\n",test, a_under, a_diges);
		for(int k=0; k<N; k++) {
			if(!check[k] && k != visited) {
				if(a_under >= data[k].understanding || a_diges >= data[k].digestive_power) {
					test++;
					DFS(k, a_under, a_diges, test);
					printf("재귀 %d) %d 에서 돌아옴\n",test,  k);
					test--;
					cnt--;
					check[k] = false;
				}
				else {
					printf("재귀 %d) %d 불가능\n",test,  k);
				}
			}
			else {
				printf("재귀 %d) %d 불가능\n",test, k);
			}
		}
		printf("재귀 %d) 감소 실행\n", test);
		a_under -= data[visited].capacity_value - i;
		a_diges -= i;
	}
	
}

int main()
{
	int T, result_idx = 0;
	int result[MAX] = {0,};
	scanf("%d", &T);

	while(T--) {
		int idx = 0;
		int list[MAX] = {0,};

		scanf("%d", &N);
		for(int i=0; i<N; i++) {
			scanf("%d %d %d", &data[i].understanding, &data[i].digestive_power, &data[i].capacity_value);

			if(data[i].understanding == 1 || data[i].digestive_power == 1) list[idx++] = i;
		}
		
		for(int i=0; i<idx; i++) {
			cnt = 0;
			maxCnt = 0;
			int index = list[i];
			DFS(index, data[index].understanding, data[index].digestive_power, 1);

			if(result[result_idx] < maxCnt) result[result_idx] = maxCnt;
		}
		result_idx++;
	}

	for(int i=0; i<result_idx; i++) {
		printf("#%d %d\n", i+1, result[i]);
	}

	return 0;
}
