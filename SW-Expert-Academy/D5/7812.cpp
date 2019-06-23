#include <cstdio>

using namespace std;

int N;

void merging(int arr[], int s1, int e1, int s2, int e2)
{
	int p, q;
	int temp[N];
	int temp_idx = 0;

	p = s1;
	q = s2;

	while(p <= e1 && q <= e2) {
		if(arr[p] < arr[q]) {
			temp[temp_idx++] = arr[p];
			p++;
		}
		else {
			temp[temp_idx++] = arr[q];
			q++;
		}
	}

	if(p > e1) {
		for(int i=q; i<=e2; i++) {
			temp[temp_idx++] = arr[i];
		}
	}
	else if(q > e2){
		for(int i=p; i<=e1; i++) {
			temp[temp_idx++] = arr[i];
		}
	}

	for(int i=s1; i<=e2; i++) {
		arr[i] = temp[i-s1];
	}
}

void mergeSort(int arr[], int start, int end)
{
	if(start >= end) {
		return;
	}
	else {
		int mid = (start + end) / 2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid+1, end);
		merging(arr, start, mid, mid+1, end);
	}
}

int main()
{
	int T, sharp = 1;
	int cnt = 0;
	scanf("%d", &T);

	while(T--)
	{
		int M;
		scanf("%d %d", &N, &M);

		int arr[N];
		for(int i=0; i<N; i++) {
			scanf("%d", &arr[i]);
		}

		mergeSort(arr, 0, N-1);
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
