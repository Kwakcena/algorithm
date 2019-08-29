#include <stdio.h>
#define MAX(x, y) ((x) > (y) ? (x) : (y))

int main()
{
	int T, DP[301] = {0,}, Table[301] = {0,};
	scanf("%d", &T);

	for(int i=1; i<=T; i++) {
		scanf("%d", &Table[i]);
		if(i == 1) DP[i] = Table[i];
		else if(i == 2) DP[i] = Table[i] + Table[i-1];
		else if(i == 3) DP[i] = MAX(Table[i] + Table[i-1] , Table[i] + Table[i-2]);
		else {
			DP[i] = MAX(Table[i] + Table[i-1] + DP[i-3], Table[i] + DP[i-2]);
		}
	}
	printf("%d", DP[T]);

	return 0;
}
