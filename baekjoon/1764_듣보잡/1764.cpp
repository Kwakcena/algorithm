#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX = 500001;
int N, M, idx = 0;

int getLeft(char **arr, char **left, int start, int end, char pivot[])
{
	int idx = 0;
	for(int i=start; i<=end; i++) {
		if(strcmp(arr[i], pivot) < 0) {
			strcpy(left[idx++], arr[i]);
		}
	}

	return idx;
}

int getRight(char **arr, char **right, int start, int end, char pivot[])
{
	int idx = 0;
	for(int i=start; i<=end; i++) {
		if(strcmp(arr[i], pivot) >= 0) {
			strcpy(right[idx++], arr[i]);
		}
	}

	return idx;
}

void quickSort(char **arr, int start, int end)
{
	if(start >= end) return;

	char pivot[21];
	strcpy(pivot, arr[start]);

	char **left = (char **)malloc(sizeof(char*)*MAX);
	char **right = (char **)malloc(sizeof(char*)*MAX);

	for(int i=0; i<MAX; i++) {
		*(left + i) = (char*)malloc(sizeof(char)*21);
		*(right + i) = (char*)malloc(sizeof(char)*21);
	}

	int left_cnt = getLeft(arr, left, start+1, end, pivot);
	int right_cnt = getRight(arr, right, start+1, end, pivot);

	for(int i=0; i<left_cnt; i++) {
		strcpy(arr[start+i], left[i]);
	}
	strcpy(arr[start+left_cnt], pivot);
	for(int i=0; i<right_cnt; i++) {
		strcpy(arr[start+left_cnt+1+i], right[i]);
	}

	quickSort(arr, start, start+left_cnt-1);
	quickSort(arr, start+left_cnt+1, end);
}

//이진탐색 비 재귀
int binarySearch(char **arr, int myStart, int myEnd, char value[])
{
	int start, end;
	int mid = 0;
	// start : value 보다 항상 작은 값을 가리킨다.
	// end : value 보다 항상 큰 값을 가리킨다.
	
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

	//듣지도 못했던 사람을 담는 공간
	char **d_list = (char **)malloc(sizeof(char*)*MAX);
	char **see_list = (char **)malloc(sizeof(char*)*MAX);
	char **result = (char **)malloc(sizeof(char*)*MAX);
	for(int i=0; i<MAX; i++) {
		*(d_list + i) = (char*)malloc(sizeof(char)*21);
		*(see_list + i) = (char*)malloc(sizeof(char)*21);
		*(result + i) = (char*)malloc(sizeof(char)*21);
	}

	//듣 - 입력
	for(int i=0; i<N; i++) {
		scanf("%s", d_list[i]);
	}

	//보 - 입력
	for(int i=0; i<M; i++) {
		scanf("%s", see_list[i]);
	}
	//보 - 정렬
	quickSort(see_list, 0, M-1);

	//듣에서 보를 보면서 일치하면 결과배열에 담음
	for(int i=0; i<N; i++) {
		if(binarySearch(see_list, 0, M-1, d_list[i]) != -1) {
			strcpy(result[idx++], d_list[i]);
		}
	}

	//결과배열을 한번 정렬
	quickSort(result, 0, idx-1);
	//인원수 출력
	printf("%d\n", idx);
	for(int i=0; i<idx; i++) {
		printf("%s\n", result[i]);
	}

	//메모리 해제
	for(int i=0; i<MAX; i++) {
		free(*(result + i));
		free(*(see_list + i));
		free(*(d_list + i));
	}
	free(result);
	free(see_list);
	free(d_list);

	return 0;
}
