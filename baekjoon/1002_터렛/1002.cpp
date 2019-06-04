#include <cstdio>
#include <cmath>

using namespace std;

int T, x_1, y_1, r_1, x_2, y_2, r_2;
int r_big, r_sm;
int idx = 0;
int result[10005];

int diff(int a_num1, int a_num2) {
	if(a_num1 > a_num2) {
		return a_num1 - a_num2;
	}
	else {
		return a_num2 - a_num1;
	}
}

int main()
{
	//테스트 케이스 입력 
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d %d %d %d %d", &x_1, &y_1, &r_1, &x_2, &y_2, &r_2);
		//두 점 사이의 거리
		double d = sqrt(pow(diff(x_1, x_2), 2) + pow(diff(y_1, y_2), 2));	
		int value = 0;
		
		//큰 반지름과 작은 반지름 구별
		if(r_1 > r_2) {
			r_big = r_1;
			r_sm = r_2;
		}
		else {
			r_big = r_2;
			r_sm = r_1;
		}
		
		//조건 판별
		/*
		 * 2. 두 점에서 만나는 경우
		 * 3. 한 점에서 만나는 경우
		 * 4. 만나지 않는 경우
		 */

		if(r_big - r_sm < d && r_big + r_sm > d) {
			value = 2;
		}
		else if(d == 0 && r_big == r_sm) {
			value = -1;
		}
		else if(r_big + r_sm == d || r_big - r_sm == d) {
			value = 1;
		}
		else if(r_big + r_sm < d || r_big - r_sm > d) {
			value = 0;
		}

		result[idx++] = value;
	}

	for(int i=0; i<idx; i++) {
		printf("%d\n", result[i]);
	}
	return 0;
}
