#include <stdio.h>

int main()
{
	int n, DP[1001];
	scanf("%d", &n);
	DP[1] = 1, DP[2] = 2;

	for(int i=3; i<=n; i++) {
		DP[i] = (DP[i-1] + DP[i-2]) % 10007;
	}

	printf("%d", DP[n]);
	return 0;
}
