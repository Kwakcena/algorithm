#include <stdio.h>

int main()
{
    int n;
    int rank[201] = {}, score[201] = {};

    scanf("%d", &n);
    int value = 1;

    for(int i=0; i<n; i++) {
        scanf("%d", &score[i]);
        rank[score[i]]++;
    }

    for(int i=200; i>=1; i--) {
        int temp = rank[i];
        rank[i] = value;
        value += temp;
    }

    for(int i=0; i<n; i++) {
        printf("%d %d\n", score[i], rank[score[i]]);
    }

    return 0;
}
