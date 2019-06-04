#include <cstdio>

using namespace std;

typedef struct dpTable {
	int one, zero;
} TABLE;

int one_cnt, zero_cnt;
TABLE Table[41];

int fibonacci(int n) {
	if(n==0) {
		zero_cnt++;
		return 0;
	}
	else if(n==1) {
		one_cnt++;	
		return 1;
	}
	else {
		return fibonacci(n-1) + fibonacci(n-2);
	}
}

int main()
{
	fibonacci(0);
	Table[0].one = one_cnt; 
	Table[0].zero = zero_cnt;

	/*
	 * N = 0 일때 fibonacci를 구해놓으면 그 이후의 N에 대한 0과 1의 개수는
	 * 아래의 규칙에 의해 구할 수 있음.
	 * 
	 * 숫자 N에 대한 fibonacci 1의 개수 = N-1에 대한 0의 개수 + 1의 개수
	 * 숫자 N에 대한 fibonacci 0의 개수 = N-1에 대한 1의 개수
	 * */
	for(int i=1; i<=40; i++) {
		Table[i].zero = Table[i-1].one;
		Table[i].one = Table[i-1].one + Table[i-1].zero;
	}

	int T;
	scanf("%d", &T);
	while(T--) {
		int N;
		scanf("%d", &N);
		
		printf("%d %d\n", Table[N].zero, Table[N].one);
	}
	return 0;
}
