#include <cstdio>

using namespace std;

int one_print_cnt, zero_print_cnt;

int fibonacci(int n) {
	if(n==0) {
		zero_print_cnt++;
		return 0;
	}
	else if(n==1) {
		one_print_cnt++;	
		return 1;
	}
	else {
		return fibonacci(n-1) + fibonacci(n-2);
	}
}

int main()
{

	int T;
	scanf("%d", &T);
	while(T--) {
		int N;

		scanf("%d", &N);
		fibonacci(N);
		printf("%d %d\n", zero_print_cnt, one_print_cnt);

		zero_print_cnt = 0;
		one_print_cnt = 0;
	}
	return 0;
}
