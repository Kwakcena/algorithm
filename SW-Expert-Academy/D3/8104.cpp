#include <stdio.h>

int main()
{
	int N, K, T;
	scanf("%d", &T);

	for(int index=1; index<=T; index++) {
		scanf("%d %d", &N, &K);

		int Table[N][K];
		int rank = 1;

		for(int row=0; row<N; row++)
			for(int col=0; col<K; col++) 
				Table[row][row % 2 == 0 ? col : (K-1)-col] = rank++;
		
		printf("#%d ", index);
		for(int col=0; col<K; col++) {
			int total = 0;
			for(int row=0; row<N; row++) {
				total += Table[row][col];
			}
			printf("%d ", total);
		}
		printf("\n");
	}
	return 0;
}
