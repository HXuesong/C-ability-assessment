#include <stdio.h>

#define MAX 20

int main() {

	int a[MAX][MAX];
	int n;
	int i, j, k;
	int base = 1;

	printf("请输入矩阵的基数:\n");

	scanf("%d", &n);

	for(k = 0; k < n / 2; k++) {

		for(i = k; i <= n - 1 - k; i++)
			a[i][k] = base++;

		for(j = k + 1; j < n - 1 - k; j++)
			a[n - 1 - k][j] = base++;

		for(i = n - 1 - k; i > k; i--)
			a[i][n - 1 - k] = base++;

		for(j = n - 1 - k; j > k; j--)
			a[k][j] = base++;

		if(n % 2 == 1)
			a[(n - 1) / 2][(n - 1) / 2] = base;
	}

	printf("螺旋矩阵输出如下所示:\n");

	for(i = 0; i < n; i++)     {

		for(j = 0; j < n; j++)
			printf("%-4d", a[i][j]);
		printf("\n");
	}

	return 0;
}
