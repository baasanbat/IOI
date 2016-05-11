#include <stdio.h>
#include <stdlib.h>
#define N 10

int jin[N];
char graph[N][N];

/*
* returns false if there is at least one pair of nodes
* that are neighbours.
* Otherwise returns true.
*/
char is_independent_set(int k, int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if ( ((1<<i)&k) && ((1<<j)&k) && i!=j && graph[i][j]) 
				return 0;
		}
	}
	return 1;
}

int main(int argc, char *argv[]) {
	int n; scanf("%d", &n);
	int i; for (i = 0; i < n; i++) scanf("%d", &jin[i]);
	for (i = 1; i < n; i++) {
		int HOST, A; scanf("%d%d", &HOST, &A);
		if (A == 0) {
			graph[HOST][i] = graph[i][HOST] = 1;
		} else if (A == 1) {
			int j; for (j = 0; j < n; j++)
				if (graph[HOST][j])
					graph[j][i] = graph[i][j] = 1;
		} else {
			graph[HOST][i] = graph[i][HOST] = 1;
			int j; for (j = 0; j < n; j++)
				if (graph[HOST][j]) 
					graph[j][i] = graph[i][j] = 1;
		}
	}
	int ret = -1;
	for (int i = 0; i < (1<<n); i++) {
		if (is_independent_set(i, n)) {
			int sum = 0;
			int j; for (j = 0; j < n; j++)
				if ((1<<j)&i)
					sum += jin[j];
			ret = sum>ret?sum:ret;
		}
	}
	printf("%d\n", ret);
	return 0;
}
