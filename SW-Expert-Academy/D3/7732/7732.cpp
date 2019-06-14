#include <stdio.h>

typedef struct {
	int H, M, S;
} DATA;

int main()
{
	int T, index = 0;
	DATA data[T];

	scanf("%d", &T);
	while(T--) {
		int s_h, s_m, s_s, e_h, e_m, e_s;
		scanf("%02d:%02d:%02d", &s_h, &s_m, &s_s);
		scanf("%02d:%02d:%02d", &e_h, &e_m, &e_s);

		data[index].H = 

	}
	return 0;
}
