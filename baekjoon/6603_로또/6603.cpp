#include <cstdio>
#include <cstring>
using namespace std;

int K, result_idx=1;
int result[50];

void DFS(int arr[], bool check[], int idx)
{
	check[idx] = true;
	result[result_idx] = arr[idx];

	if(result_idx == 6) {
		for(int i=1; i<=result_idx; i++) printf("%d ", result[i]);
		printf("\n");
		return ;
	}
	for(int i=1; i<=K; i++) {
		if(arr[idx] < arr[i] && !check[i]) {
			result_idx++;
			DFS(arr, check, i);
			check[i] = false;
			result_idx--;
		}
	}
}

int main()
{

	while(1)
	{
		scanf("%d", &K);
		if(K==0) break;

		int arr[K+1];
		bool check[50];
		memset(check, false, sizeof(bool)*(50));

		for(int i=1; i<=K; i++)
			scanf("%d", &arr[i]);

		for(int start=1; start <= K-5; start++)
			DFS(arr, check, start);
		printf("\n");
	}

	return 0;
}
