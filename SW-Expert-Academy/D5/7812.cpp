#include <cstdio>

using namespace std;

void sort(int arr[], int idx) 
{
	for(int i=0; i<idx; i++) {
		for(int j=i+1; j<idx; j++) {
			if(arr[i] > arr[j]) {
				int temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
}

int main()
{
	int T, sharp = 1;
	int cnt = 0;
	scanf("%d", &T);

	while(T--)
	{
		int N, M;
		scanf("%d %d", &N, &M);

		int arr[N];
		for(int i=0; i<N; i++) {
			scanf("%d", &arr[i]);
		}

		sort(arr, N);

		for(int i=0; i<N; i++) {
			M -= arr[i];
			cnt++;
			if(M == 0 || M < 0) break;
		}
		printf("#%d %d\n", sharp, cnt);
		cnt = 0;
		
	}
	return 0;
}
