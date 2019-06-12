#include <stdio.h>
#include <string.h>

#define ONE_DAY 86400
#define ONE_MONTH 2592000
#define ONE_YEAR 31536000

const int MAX = 1000;

typedef struct _memo{
	char schedule[MAX];
	long long int y, m, d;
	long long int total;
} MEMO;

int N;
MEMO memo_data[MAX];

void Sort_schedule() 
{
	for(int i=0; i<N; i++) {
		int idx = i;
		for(int j=i+1; j<N; j++) {
			if(memo_data[idx].total == memo_data[j].total && strcmp(memo_data[idx].schedule, memo_data[j].schedule) > 0) {
				MEMO temp = memo_data[j];
				memo_data[j] = memo_data[idx];
				memo_data[idx] = temp;
			}
		}
	}
}

void Sort_time() 
{
	for(int i=0; i<N; i++) {
		int idx = i;
		for(int j=i+1; j<N; j++) {
			if(memo_data[idx].total > memo_data[j].total){
				MEMO temp = memo_data[j];
				memo_data[j] = memo_data[idx];
				memo_data[idx] = temp;
			}
		}
	}
}

int main()
{
	
	scanf("%d", &N);

	for(int i=0; i<N; i++) {
		scanf("%s %lld %lld %lld", memo_data[i].schedule, &memo_data[i].y, &memo_data[i].m, &memo_data[i].d);
		memo_data[i].total = (memo_data[i].y * ONE_YEAR) + (memo_data[i].m * ONE_MONTH) + (memo_data[i].d * ONE_DAY);
	}

	Sort_time();
	Sort_schedule();
	for(int i=0; i<N; i++) {
		printf("%s\n", memo_data[i].schedule);
	}

	return 0;
}

