#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N, M, idx = 0;

int getLeft(char arr[][21], char left[][21], int start, int end, const char* pivot)
{
	int idx = 0;
	for(int i=start; i<=end; i++) {
		if(strcmp(arr[i], pivot) < 0) {
			strcpy(left[idx++], arr[i]);
		}
	}

	return idx;
}

int getRight(char arr[][21], char right[][21], int start, int end, const char* pivot)
{
	int idx = 0;
	for(int i=start; i<=end; i++) {
		if(strcmp(arr[i], pivot) >= 0) {
			strcpy(right[idx++], arr[i]);
		}
	}

	return idx;
}

void quickSort(char arr[][21], int start, int end)
{
	if(start >= end) return;

	const char *pivot = arr[start];
	char left[N+M][21], right[N+M][21];

	int left_cnt = getLeft(arr, left, start+1, end, pivot);
	int right_cnt = getRight(arr, right, start+1, end, pivot);
	
	printf("\n==================\n");
	printf("pivot : %s\n", pivot);
	printf("***getLeft\n");
	for(int i=0; i<left_cnt; i++) printf("%s\n", left[i]);
	printf("***getRight\n");
	for(int i=0; i<right_cnt; i++) printf("%s\n", right[i]);
	printf("==================\n");

	for(int i=0; i<left_cnt; i++) {
		strcpy(arr[start+i], left[i]);
	}
	strcpy(arr[start+left_cnt], pivot);
	for(int i=0; i<right_cnt; i++) {
		strcpy(arr[start+left_cnt+1+i], right[i]);
	}

	printf("\n==================\n");
	printf("***arr\n");
	for(int i=0; i<end; i++) {
		printf("%s\n", arr[i]);
	}
	printf("\n==================\n");


	quickSort(arr, start, start+left_cnt-1);
	quickSort(arr, start+left_cnt+1, end);
}

//이진탐색 비 재귀
int binarySearch(char arr[][21], int myStart, int myEnd, char value[])
{
	int start, end;
	int mid = 0;
	// start : value보다 항상 작은 값을 가리킨다.
	// end : valueㅂ다 항상 큰 값을 가리킨다.
	
	if(strcmp(arr[myStart], value) > 0) return -1;
	else if(strcmp(arr[myStart], value) == 0) return myStart;

	if(strcmp(arr[myEnd], value) < 0) return -1;
	else if(strcmp(arr[myEnd], value) == 0) return myEnd;

	start = myStart;
	end = myEnd;

	while(start + 1 < end)
	{
		mid = (start + end) / 2;

		if(strcmp(arr[mid], value) == 0) return mid;
		else if(strcmp(arr[mid], value) > 0) end = mid;
		else start = mid;
	}

	return -1;
}

int main()
{

	scanf("%d %d", &N, &M);

	//듣도 보도 못한
	char d_list[N][21];
	char see_list[M][21];
	//답을 담는 배열
	char result[N+M][21];


	for(int i=0; i<N; i++) {
		scanf("%s", d_list[i]);
	}

	for(int i=0; i<M; i++) {
		scanf("%s", see_list[i]);
	}
	quickSort(see_list, 0, M-1);

	printf("----- SORT\n");
	for(int i=0; i<M; i++) {
		printf("%s\n", see_list[i]);
	}
	for(int i=0; i<N; i++) {
		if(binarySearch(see_list, 0, M-1, d_list[i]) != -1) {
			strcpy(result[idx++], d_list[i]);
		}
	}

	quickSort(result, 0, idx-1);
	printf("---\n");
	for(int i=0; i<idx; i++) {
		printf("%s\n", result[i]);
	}


	return 0;
}
