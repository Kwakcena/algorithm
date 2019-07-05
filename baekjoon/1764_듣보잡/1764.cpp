#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Sort(char str[][21], int a_len)
{
	for(int i=0; i<a_len; i++) {
		int idx = i;
		for(int j=i+1; j<a_len; j++) {
			if(strcmp(str[idx], str[j]) > 0) {
				char temp[21];
				strcpy(temp, str[idx]);
				strcpy(str[idx], str[j]);
				strcpy(str[j], temp);
			}
		}
	}
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

	int N, M, idx = 0;
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
	Sort(see_list, M);

	for(int i=0; i<N; i++) {
		if(binarySearch(see_list, 0, M-1, d_list[i]) != -1) {
			strcpy(result[idx++], d_list[i]);
		}
	}

	//printf("%d\n", binarySearch(see_list, 0, M-1, d_list[0]));

	Sort(result, idx);
	for(int i=0; i<idx; i++) {
		printf("%s\n", result[i]);
	}


	return 0;
}
