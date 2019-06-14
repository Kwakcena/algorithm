#include <stdio.h>
#include <math.h>

int main()
{
	int T, idx = 0;
	scanf("%d", &T);
	double result[T];

	while(T--) {
		double arr[10];
		double sum = 0;
		for(int i=0; i<10; i++) {
			scanf("%lf", &arr[i]);
			sum += arr[i];
		}

		result[idx++] = floor((sum / 10.0) + 0.5);

	}

	for(int i=0; i<idx; i++) printf("#%d %.0lf\n", i+1, result[i]); 
	return 0;
}
