#include <cstdio>
#include <cmath>

#define ABS_DIFF(x,y) x > y ? x-y : y-x

using namespace std;

int main()
{
	int T, n;
	int x1, y1, x2, y2;

	scanf("%d", &T);		//테스트 케이스 입력
	while(T--) {
		//진입, 이탈 변수
		int result = 0;
		//출발점과 도착점 입력
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		//행성계의 개수 입력
		scanf("%d", &n);

		while(n--) {
			int c_x, c_y, r;
			//행성계의 중점과 반지름 입력
			scanf("%d %d %d", &c_x, &c_y, &r);

			//출발점과 방금 입력받은 행성의 거리를 구한다.
			double start_d = sqrt(pow(ABS_DIFF(x1, c_x), 2) + pow(ABS_DIFF(y1, c_y), 2)); 
			double end_d = sqrt(pow(ABS_DIFF(x2, c_x), 2) + pow(ABS_DIFF(y2, c_y), 2)); 

			if(start_d < r && end_d < r) continue;
			else if(start_d < r || end_d < r) {
				result += 1;	
			}
		}

		printf("%d\n" ,result);
	}

	return 0;
}	
