#include <stdio.h>
#include <stdlib.h>

const int MAX = 250000;

void eratosthenes(int *ptr)
{
	*(ptr + 0) = 0;
	for(int i=2; i<=123456; i++) {
		if(*(ptr + (i-1)) == 0) continue;
		else {
			for(int j=i+i; j<=123456*2; j+=i) {
				if(*(ptr + (j-1))) {
					*(ptr + (j-1)) = 0;
				}
			}
		}
	}
}

int func(int start, int *ptr)
{
	int cnt = 0;
	int end = start*2;

	for(int i=start; i<end; i++)
		if(*(ptr + i)) cnt++;

	return cnt;
}

int main()
{
	int *ptr = (int*)malloc(sizeof(int)*MAX);

	for(int i=1; i<=MAX; i++) {
		*(ptr + (i-1)) = i;
	}


	eratosthenes(ptr);

	while(1) {
		int s;
		scanf("%d", &s);
		if(s == 0) break;
		else printf("%d\n", func(s, ptr));
	}

	free(ptr);
	return 0;
}
