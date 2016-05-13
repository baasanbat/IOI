#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 1002
int v[N][N]; //graph
char used[N]; //dfs

int dfs(int source, int target, int n) {
	if (source == target) return 1;
	
	used[source] = 1;
	int ret = -1;
	int i; for (i = 0; i < n; i++) {
		if (v[source][i]==1 && used[i]!=1) {
			ret = dfs(i, target, n);
			if (ret != -1) {
				v[source][i]--;
				v[i][source]++;
				return ret;
			}
		}
	}
	return ret;
}

int ford_fulkerson(int source, int target, int n) {
	int flow = 0;
	while (dfs(source, target, n) == 1) {
		memset(used, 0, sizeof used);
		flow++;
	}
	return flow;
}

int main(int argc, char *argv[]) {
	int n, m; scanf("%d%d", &n, &m);
	int i; for (i = 0; i < m; i++) {
		int a, b; scanf("%d%d", &a, &b);
		v[a][b] = 1;
	}
	int s, t; scanf("%d%d", &s, &t);
	int j; for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			printf("%d ", v[i][j]);
		printf("\n");
	}
	int ret = ford_fulkerson(0, t, n);
	printf("%d\n", ret);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			printf("%d ", v[i][j]);
		printf("\n");
	}

	return 0;
}
