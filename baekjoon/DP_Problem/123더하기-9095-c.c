#include <stdio.h>

int DP[12];

int func(int num)
{
	if(num == 0) return 0;
	else if(num == 1) return 1;
	else if(num == 2) return 2;
	else if(num == 3) return 4;
	else {
		if(!DP[num])
			DP[num] = func(num-3) + func(num-2) + func(num-1);
		return DP[num];
	}

}

int main()
{
	int T;

	scanf("%d", &T);
	for(int i=0; i<T; i++) {
		int a;
		scanf("%d", &a);
		printf("%d\n", func(a));
	}

	return 0;
}
