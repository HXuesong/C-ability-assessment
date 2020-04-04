#include<stdio.h>

#define N 3

int main() {
	int i, j;
	int x[N][N];
	int a[N], b[N], c, d;
	int flag = 1;

	for(i = 0; i < N; i++) {

		for(j = 0; j < N; j++) {
			scanf("%d", &x[i][j]);
		}
	}
	for(i = 0; i < N; i++) {
		a[i] = 0;

		for(j = 0; j < N; j++) {
			a[i] += x[i][j];
		}
	}
	for(j = 0; j < N; j++) {
		b[j] = 0;

		for(i = 0; i < N; i++) {
			b[j] += x[i][j];
		}
	}
	c = 0;

	for(j = 0; j < N; j++) {
		c += x[j][j];
	}

	d = 0;
	for(j = 0; j < N; j++) {
		d += x[j][N - 1 - j];
	}
	if(c != d) {
		flag = 0;
	} else {
		for(i = 0; i < N; i++) {
			if((a[i] != c) || (b[i] != d))
            {
                flag = 0;
            }

			}
	}
	if(flag) {
		printf("It is a magic square!\n");
	} else {
		printf("It is not a magic square!\n");
	}

	return 0;
}
