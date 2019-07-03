#include <stdio.h>

int func(int N)
{
	if(N == 1) return 1;
	else return N * func(N-1);
}

int main()
{
	int N;
	scanf("%d", &N);

	printf("%d" , func(N));

	return 0;
}
