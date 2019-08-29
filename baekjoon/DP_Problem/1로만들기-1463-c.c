#include <stdio.h>
#define MIN(x, y) ((x) > (y) ? (y) : (x))

int main()
{
	int num, DP[1000001];
	scanf("%d", &num);

	DP[1] = 0, DP[2] = 1, DP[3] = 1;

	for(int i=4; i<=num; i++) {
		if(i % 3 == 0) DP[i] = MIN(1 + DP[i/3], 1 + DP[i-1]);
		else if(i % 2 == 0) DP[i] = MIN(1 + DP[i/2], 1 + DP[i-1]);
		else DP[i] = 1 + DP[i-1];
	}

	printf("%d", DP[num]);
	return 0;
}
