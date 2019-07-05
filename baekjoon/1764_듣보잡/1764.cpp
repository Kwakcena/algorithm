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


	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			int ret = strcmp(d_list[i], see_list[j]);
			// -1 : 아스키 코드 기준으로 문자열 see_list가 더 클때
			// 0 : 아스키 코드 기준으로 두 문자열이 같을 때
			// 1 : 아스키 코드 기준으로 문자열 d_list가 더 클때
			if(ret == 0) {
				strcpy(result[idx++], d_list[i]);
			}
		}
	}
			
	
	Sort(result, idx);

	for(int i=0; i<idx; i++) {
		printf("%s\n", result[i]);
	}
	

	return 0;
}
