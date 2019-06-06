#include <cstdio>
using namespace std;

const int MAX = 30;

int N;
int map[MAX][MAX];
int result[MAX*MAX];
bool check[MAX][MAX];

int dy[4] = { -1, +1, 0, 0 };
int dx[4] = { 0, 0, -1, +1};

void DFS(int start_row, int start_col, int value)
{
	check[start_row][start_col] = true;
	map[start_row][start_col] = value;
	result[value]++;

	for(int i=0; i<4; i++) {
		int newRow = start_row + dy[i];
		int newCol = start_col + dx[i];
		if((newRow < N && newRow >= 0) && (newCol < N && newCol >= 0)) {
			if(!check[newRow][newCol] && map[newRow][newCol] == 1) {
				DFS(newRow, newCol, value);
			}
		}
	}

}

void sort(int index)
{
	for(int i=0; i<index; i++) {
		int inx = i;
		for(int j=i+1; j<index; j++) {
			if(result[inx] > result[j]) {
				int temp;
				temp = result[inx];
				result[inx] = result[j];
				result[j] = temp;
			}
		}
	}
}

int main()
{
	int value = 1;
	//지도의 크기 입력
	scanf("%d", &N);

	//단지 입력
	for(int i=0; i<N; i++) {
		char temp[MAX];
		scanf("%s", temp);
		for(int j=0; j<N; j++) {
			temp[j] == '1' ? map[i][j] = 1 : map[i][j] = 0; 
		}
	}

	//단지 번호 붙이기
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			if(map[i][j] == 1 && !check[i][j]) {
				DFS(i, j, value); 
				value++;
			}
		}
	}

	//결과 오름차순 정렬
	sort(value);
	//결과 출력
	printf("%d\n", value-1);
	for(int i=1; i<value; i++) {
		printf("%d\n", result[i]);
	}

	return 0;
}
