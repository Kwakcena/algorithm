#include <stdio.h>

int main()
{
	int T, idx = 0;
	scanf("%d", &T);
	int result[T];

	while(T--) {
		int arr[10];
		int sum = 0;
		for(int i=0; i<10; i++) {
			scanf("%d", &arr[i]);
			if(arr[i] % 2 == 1) 
				sum += arr[i];
		}

		result[idx++] = sum;
	}

	for(int i=0; i<idx; i++) printf("#%d %d\n", i+1, result[i]); 
	return 0;
}
