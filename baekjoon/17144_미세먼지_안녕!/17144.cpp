#include <cstdio>

using namespace std;

const int MAX = 55;

typedef struct {
	int Arc;
	int receive_value;
} DATA;

int R,C,T;

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

DATA data[MAX][MAX];

void findDust_diffusion(DATA a_data[MAX][MAX])
{
	for(int i = 0; i<R; i++){
		for(int j=0; j<C; j++){
			if(a_data[i][j].Arc > 0){
				int diffusion_value = a_data[i][j].Arc / 5;
				for(int k=0; k<4; k++) {
					int row = i + dy[k];
					int col = j + dx[k];
					if(a_data[row][col].Arc != -1 && (row >= 0 && row < R) && (col >= 0 && col < C)) {
						a_data[row][col].receive_value += diffusion_value; 
						a_data[i][j].Arc -= diffusion_value;
						//printf("%d %d -- %d\n", i, j, a_data[i][j].Arc);
					}
				}
			}
		}
	}

	for(int i = 0; i<R; i++){
		for(int j=0; j<C; j++){
			if(a_data[i][j].Arc != -1) {
				a_data[i][j].Arc += a_data[i][j].receive_value;
				a_data[i][j].receive_value = 0;
			}
		}
	}
}

int main()
{
	scanf("%d %d %d", &R, &C, &T);
	for(int i = 0; i<R; i++){
		for(int j=0; j<C; j++){
			scanf("%d", &data[i][j].Arc);
		}
	}

	findDust_diffusion(data);

	printf("\n");
	for(int i = 0; i<R; i++){
		for(int j=0; j<C; j++){
			printf("%d ", data[i][j].Arc);
		}
		printf("\n");
	}
	return 0;
}

